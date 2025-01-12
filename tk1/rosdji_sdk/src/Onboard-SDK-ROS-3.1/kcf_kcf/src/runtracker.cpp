#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <dirent.h>
#include <time.h>

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include "geometry_msgs/Twist.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "kcftracker.hpp"
#include<kcf/Sendselect.h>
//#include<dji_sdk/dji_drone.h>
#include<dji_sdk/TransparentTransmissionData.h>
#include<dji_sdk/SendDataToRemoteDevice.h>

using namespace std;
static const std::string RGB_WINDOW = "RGB Image window";
//static const std::string DEPTH_WINDOW = "DEPTH Image window";

#define Max_linear_speed 0.6
#define Min_linear_speed 0.4
#define Min_distance 1.5
#define Max_distance 5.0
#define Max_rotation_speed 0.75

float linear_speed = 0;
float rotation_speed = 0;

float k_linear_speed = (Max_linear_speed - Min_linear_speed) / (Max_distance - Min_distance);
float h_linear_speed = Min_linear_speed - k_linear_speed * Min_distance;

float k_rotation_speed = 0.004;
float h_rotation_speed_left = 1.2;
float h_rotation_speed_right = 1.36;
 
int ERROR_OFFSET_X_left1 = 100;
int ERROR_OFFSET_X_left2 = 300;
int ERROR_OFFSET_X_right1 = 340;
int ERROR_OFFSET_X_right2 = 540;

cv::Mat rgbimage;
cv::Mat depthimage;
cv::Rect selectRect;
cv::Point origin;
cv::Rect result;

bool select_flag = false;
bool bRenewROI = false;  // the flag to enable the implementation of KCF algorithm for the new chosen ROI
bool bBeginKCF = false;
bool enable_get_depth = false;

bool HOG = true;
bool FIXEDWINDOW = false;
bool MULTISCALE = true;
bool SILENT = true;
bool LAB = false;

// Create KCFTracker object
KCFTracker tracker(HOG, FIXEDWINDOW, MULTISCALE, LAB);

float dist_val[5] ;

void onMouse(int event, int x, int y, int, void*)
{
    if (select_flag)
    {
        selectRect.x = MIN(origin.x, x);        
        selectRect.y = MIN(origin.y, y);
        selectRect.width = abs(x - origin.x);   
        selectRect.height = abs(y - origin.y);
        selectRect &= cv::Rect(0, 0, rgbimage.cols, rgbimage.rows);
    }
    if (event == CV_EVENT_LBUTTONDOWN)
    {
        bBeginKCF = false;  
        select_flag = true; 
        origin = cv::Point(x, y);       
        selectRect = cv::Rect(x, y, 0, 0);  
    }
    else if (event == CV_EVENT_LBUTTONUP)
    {
        select_flag = false;
        bRenewROI = true;
    }
}

class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
	
  char buf[20];


//image_transport::Subscriber depth_sub_;
public:
  ros::Publisher pub;
  ros::Subscriber select_sub;
  ros::Subscriber datafrommobile;
  ros::ServiceClient senddatatomobileclient;
  dji_sdk::SendDataToRemoteDevice senddatatomobileclientsrv;

  ImageConverter()
    : it_(nh_)
  {
    // Subscrive to input video feed and publish output video feed
    image_sub_ = it_.subscribe("/dji_sdk/image_raw", 1, 
      &ImageConverter::imageCb, this);
//    depth_sub_ = it_.subscribe("/camera/depth/image", 1, 
//      &ImageConverter::depthCb, this);

	select_sub=nh_.subscribe("/sendselect/msg",1000,&ImageConverter::getselecthandle,this);


    pub = nh_.advertise<kcf::Sendselect>("/sendselect/cmd_vel", 1000,this);

	datafrommobile = nh_.subscribe("dji_sdk/data_received_from_remote_device",100,&ImageConverter::datafrommobilehandle,this);

	senddatatomobileclient=nh_.serviceClient<dji_sdk::SendDataToRemoteDevice>("dji_sdk/send_data_to_remote_device");

 //   cv::namedWindow(RGB_WINDOW);
    //cv::namedWindow(DEPTH_WINDOW);
  }

  ~ImageConverter()
  {
  //  cv::destroyWindow(RGB_WINDOW);
    //cv::destroyWindow(DEPTH_WINDOW);
  }
	
  void datafrommobilehandle(const dji_sdk::TransparentTransmissionData& msg)
  {
	if(msg.data[0]!=0&&msg.data[1]!=0)
	{
        selectRect.x = (msg.data[0]*100+msg.data[1])/1.5;        
        selectRect.y = (msg.data[2]*100+msg.data[3])/1.5+30;
        selectRect.width = (msg.data[4]*100+msg.data[5])/1.5;   
        selectRect.height = (msg.data[6]*100+msg.data[7])/1.5;

		bRenewROI=true;

		ROS_INFO("data %d %d %d %d",selectRect.x,selectRect.y,selectRect.width,selectRect.height);
    //    bRenewROI = true;
		cout<<"data from mobile  message time:";
		time_t tt=time(NULL);
		tm* t=localtime(&tt);
		cout<<"nowtime: "<<t->tm_year+1900<<"-"<<t->tm_mon+1<<"-"<<t->tm_mday<<" "<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec<<endl;
	}
  }


  void getselecthandle(const kcf::Sendselect& msg)
  {
	if(msg.x!=0&&msg.y!=0)
	{
        selectRect.x = msg.x;        
        selectRect.y = msg.y;
        selectRect.width = msg.width;   
        selectRect.height = msg.height;
        bRenewROI = true;
//		cout<<"get select rect message time:";
//		time_t tt=time(NULL);
//		tm* t=localtime(&tt);
//		cout<<"nowtime: "<<t->tm_year+1900<<"-"<<t->tm_mon+1<<"-"<<t->tm_mday<<" "<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec<<endl;
	}
  }


  void imageCb(const sensor_msgs::ImageConstPtr& msg)
  {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    cv_ptr->image.copyTo(rgbimage);

    cv::setMouseCallback(RGB_WINDOW, onMouse, 0);

    if(bRenewROI)
    {
        // if (selectRect.width <= 0 || selectRect.height <= 0)
        // {
        //     bRenewROI = false;
        //     //continue;
        // }
        tracker.init(selectRect, rgbimage);
        bBeginKCF = true;
        bRenewROI = false;
        enable_get_depth = false;
    }
    //启动跟踪算法
    if(bBeginKCF)
    {
        result = tracker.update(rgbimage);
     //   cv::rectangle(rgbimage, result, cv::Scalar( 0, 255, 255 ), 1, 8 );
        enable_get_depth = true;
    }
    else
	{
     //   cv::rectangle(rgbimage, selectRect, cv::Scalar(255, 0, 0), 2, 8, 0);
		cout<<"not beigin. bBeginKCF is false"<<endl;
	}


	if(result.x!=0||result.y!=0)
	{

		senddatatomobileclientsrv.request.data[0]=result.x/100;
		senddatatomobileclientsrv.request.data[1]=result.x%100;
		senddatatomobileclientsrv.request.data[2]=result.y/100;
		senddatatomobileclientsrv.request.data[3]=result.y%100;
		senddatatomobileclientsrv.request.data[4]=result.width/100;
		senddatatomobileclientsrv.request.data[5]=result.width%100;
		senddatatomobileclientsrv.request.data[6]=result.height/100;
		senddatatomobileclientsrv.request.data[7]=result.height%100;



//		senddatatomobileclientsrv.request.data=new char(50);

//	    strcpy(senddatatomobileclientsrv.request.data,buf);
//		cout<<" test : "<<senddatatomobileclientsrv.request.data<<endl;
	/*	senddatatomobileclientsrv.request.data[20]='1';
		senddatatomobileclientsrv.request.data[21]='2';
		senddatatomobileclientsrv.request.data[22]='3';
		senddatatomobileclientsrv.request.data[23]='4';
*/
/*		for(int j=0;j<50;j++)
		{
			senddatatomobileclientsrv.request.data[j]=j;
		}
*/
		for(int i=0;i<8;i++)
		{
			cout<<senddatatomobileclientsrv.request.data[i]<<" ";
		}


		senddatatomobileclient.call(senddatatomobileclientsrv);

		if(senddatatomobileclientsrv.response.result)
		{
			ROS_INFO("send data to mobile success");
		}
		else
		{
			ROS_INFO("send data to mobile fail");
		}
	
	}

	
 ////   cv::imshow(RGB_WINDOW, rgbimage);
  //  cv::waitKey(1);
  }
/*
  void depthCb(const sensor_msgs::ImageConstPtr& msg)
  {
  	cv_bridge::CvImagePtr cv_ptr;
  	try
  	{
  		cv_ptr = cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::TYPE_32FC1);
  		cv_ptr->image.copyTo(depthimage);
  	}
  	catch (cv_bridge::Exception& e)
  	{
  		ROS_ERROR("Could not convert from '%s' to 'TYPE_32FC1'.", msg->encoding.c_str());
  	}

    if(enable_get_depth)
    {
      dist_val[0] = depthimage.at<float>(result.y+result.height/3 , result.x+result.width/3) ;
      dist_val[1] = depthimage.at<float>(result.y+result.height/3 , result.x+2*result.width/3) ;
      dist_val[2] = depthimage.at<float>(result.y+2*result.height/3 , result.x+result.width/3) ;
      dist_val[3] = depthimage.at<float>(result.y+2*result.height/3 , result.x+2*result.width/3) ;
      dist_val[4] = depthimage.at<float>(result.y+result.height/2 , result.x+result.width/2) ;

      float distance = 0;
      int num_depth_points = 5;
      for(int i = 0; i < 5; i++)
      {
        if(dist_val[i] > 0.4 && dist_val[i] < 10.0)
          distance += dist_val[i];
        else
          num_depth_points--;
      }
      distance /= num_depth_points;

      //calculate linear speed
      if(distance > Min_distance)
        linear_speed = distance * k_linear_speed + h_linear_speed;
      else
        linear_speed = 0;

      if(linear_speed > Max_linear_speed)
        linear_speed = Max_linear_speed;

      //calculate rotation speed
      int center_x = result.x + result.width/2;
      if(center_x < ERROR_OFFSET_X_left1) 
        rotation_speed =  Max_rotation_speed;
      else if(center_x > ERROR_OFFSET_X_left1 && center_x < ERROR_OFFSET_X_left2)
        rotation_speed = -k_rotation_speed * center_x + h_rotation_speed_left;
      else if(center_x > ERROR_OFFSET_X_right1 && center_x < ERROR_OFFSET_X_right2)
        rotation_speed = -k_rotation_speed * center_x + h_rotation_speed_right;
      else if(center_x > ERROR_OFFSET_X_right2)
        rotation_speed = -Max_rotation_speed;
      else 
        rotation_speed = 0;

      std::cout <<  "linear_speed = " << linear_speed << "  rotation_speed = " << rotation_speed << std::endl;

      // std::cout <<  dist_val[0]  << " / " <<  dist_val[1] << " / " << dist_val[2] << " / " << dist_val[3] <<  " / " << dist_val[4] << std::endl;
      // std::cout <<  "distance = " << distance << std::endl;
    }

  	//cv::imshow(DEPTH_WINDOW, depthimage);
  	cv::waitKey(1);
  }*/
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "kcf_kcf_node");
	ImageConverter ic;
  
	while(ros::ok())
	{
		ros::spinOnce();

		kcf::Sendselect sendrect;
		sendrect.x=result.x;
		sendrect.y=result.y;
		sendrect.width=result.width;
		sendrect.height=result.height;

		if((sendrect.x!=0)&&(sendrect.y!=0))
		{
//	ROS_INFO_STREAM("x: "<<sendrect.x<<" y: "<<sendrect.y<<" width: "<<sendrect.width<<" height: "<<sendrect.height);
		time_t tt=time(NULL);
		tm* t=localtime(&tt);
//cout<<"time before publish "<<t->tm_year+1900<<"-"<<t->tm_mon+1<<"-"<<t->tm_mday<<" "<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec;
			ic.pub.publish(sendrect);
		t=localtime(&tt);
//cout<<"time after publish "<<t->tm_year+1900<<"-"<<t->tm_mon+1<<"-"<<t->tm_mday<<" "<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec;
		}


	//	if (cvWaitKey(33) == 'q')
    //  break;
	}

	return 0;
}

