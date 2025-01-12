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
#include "../include/dectrect.h"
#include "../include/flage.h"
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


#define TRANSFORMTOMOBILE_MAX 6

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
bool dectstartflag = false;

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
  ros::Publisher startflag_pub;
  ros::Subscriber select_sub;
  ros::Subscriber datafrommobile;
  ros::Subscriber dectrect_sub;
  ros::ServiceClient senddatatomobileclient;
  dji_sdk::SendDataToRemoteDevice senddatatomobileclientsrv[14];

  ImageConverter()
    : it_(nh_)
  { 
    // Subscrive to input video feed and publish output video feed
    image_sub_ = it_.subscribe("/dji_sdk/image_raw", 1, 
      &ImageConverter::imageCb, this);
//    depth_sub_ = it_.subscribe("/camera/depth/image", 1, 
//      &ImageConverter::depthCb, this);

	select_sub=nh_.subscribe("/sendselect/msg",100,&ImageConverter::getselecthandle,this);
      dectrect_sub=nh_.subscribe("jetson/chatter",10,&ImageConverter::senddatatomobile_dect,this);


    pub = nh_.advertise<kcf::Sendselect>("/sendselect/cmd_vel", 1000,this);

    startflag_pub = nh_.advertise<jetson::flage>("jetson/flag",2,this);

	datafrommobile = nh_.subscribe("dji_sdk/data_received_from_remote_device",100,&ImageConverter::datafrommobilehandle,this);

	senddatatomobileclient=nh_.serviceClient<dji_sdk::SendDataToRemoteDevice>("dji_sdk/send_data_to_remote_device");

    cv::namedWindow(RGB_WINDOW);
    //cv::namedWindow(DEPTH_WINDOW);
  }

  ~ImageConverter()
  {
    cv::destroyWindow(RGB_WINDOW);
    //cv::destroyWindow(DEPTH_WINDOW);
  }
	
 // bool senddatetomobile_dect(){
    void senddatatomobile_dect(const jetson::rect& msg)
  //  void func(const jetson::Sendselect& msg)
    { 
		if(dectstartflag)
		{ 
			int dectcount = (int)msg.x.size(); 
		   int remainder = dectcount % TRANSFORMTOMOBILE_MAX;
		   int merchant = dectcount / TRANSFORMTOMOBILE_MAX; 
		   int loopcount =0;

		   if(remainder!=0)
			   loopcount = TRANSFORMTOMOBILE_MAX * (merchant +1);
		   else
			   loopcount = dectcount;


		   if(dectcount<=6)
		{
            ROS_INFO_STREAM("dectcount (less 6) "<<dectcount);
			for(int i=0,temp=0;i<dectcount;i++,temp++)
			{

					ROS_INFO_STREAM("msg "<<msg.x[i]<<" "<<msg.y[i]<<" "<<msg.width[i]<<" "<<msg.heigth[i]);
			    	senddatatomobileclientsrv[0].request.data[temp*8+0]=msg.x[i]/100;
			//		ROS_INFO_STREAM(" 0 ="<<(int)senddatatomobileclientsrv[j].request.data[temp*8+0]);

		//			ROS_INFO_STREAM("0");
					senddatatomobileclientsrv[0].request.data[temp*8+1]=msg.x[i]%100;
			//		ROS_INFO_STREAM(" 1 ="<<(int)senddatatomobileclientsrv[j].request.data[temp*8+1]);
		//			ROS_INFO_STREAM("1");
					senddatatomobileclientsrv[0].request.data[temp*8+2]=msg.y[i]/100;
		//			ROS_INFO_STREAM("2");
					senddatatomobileclientsrv[0].request.data[temp*8+3]=msg.y[i]%100;
		//			ROS_INFO_STREAM("3");
					senddatatomobileclientsrv[0].request.data[temp*8+4]=msg.width[i]/100;
		//			ROS_INFO_STREAM("4");
					senddatatomobileclientsrv[0].request.data[temp*8+5]=msg.width[i]%100;
		//			ROS_INFO_STREAM("5");
					senddatatomobileclientsrv[0].request.data[temp*8+6]=msg.heigth[i]/100;
		//			ROS_INFO_STREAM("6");
					senddatatomobileclientsrv[0].request.data[temp*8+7]=msg.heigth[i]%100;

			}
            for(int temp=dectcount;temp<6;temp++)
            {
                    ROS_INFO_STREAM("temp = "<<temp);

					senddatatomobileclientsrv[0].request.data[temp*8+0]= 0 ;
		//			ROS_INFO_STREAM("0");
					senddatatomobileclientsrv[0].request.data[temp*8+1]= 0;
		//			ROS_INFO_STREAM("1");
					senddatatomobileclientsrv[0].request.data[temp*8+2]= 0;
		//			ROS_INFO_STREAM("2");
					senddatatomobileclientsrv[0].request.data[temp*8+3]= 0;
		//			ROS_INFO_STREAM("3");
					senddatatomobileclientsrv[0].request.data[temp*8+4]= 0;
		//			ROS_INFO_STREAM("4");
					senddatatomobileclientsrv[0].request.data[temp*8+5]= 0;
		//			ROS_INFO_STREAM("5");
					senddatatomobileclientsrv[0].request.data[temp*8+6]= 0;
		//			ROS_INFO_STREAM("6");
					senddatatomobileclientsrv[0].request.data[temp*8+7]= 0;
            }

					senddatatomobileclientsrv[0].request.data[48]=(int)dectcount;
					senddatatomobileclientsrv[0].request.data[49]=(int)0;
ROS_INFO_STREAM("[48]"<<(int)senddatatomobileclientsrv[0].request.data[48]<<" [49]= "<<(int)(senddatatomobileclientsrv[0].request.data[49]));

					senddatatomobileclient.call(senddatatomobileclientsrv[0]);
					return ;
			
		}





		   ROS_INFO_STREAM(msg.x[0]<<" "<<msg.y[0]<<" "<<msg.width[0]<<" "<<msg.heigth[0]);
		   

			ROS_INFO_STREAM("dectcount(more 6) = "<<dectcount<<"   remainder = "<<remainder<<"   merchant = "<<merchant);



			for(int i=0,j=0,temp=0;i<loopcount;i++){
	  //          cout<<msg.x[i]<<endl;
			 //   senddatatomobileclientsrv.request.data[i*8+0]=msg.x[i]/100;
			 //   senddatatomobileclientsrv.request.data[i*8+1]=msg.x[i]%100;
			 //   senddatatomobileclientsrv.request.data[i*8+2]=msg.y[i]/100;
			 //   senddatatomobileclientsrv.request.data[i*8+3]=msg.y[i]%100;
			//    senddatatomobileclientsrv.request.data[i*8+4]=msg.width[i]/100;
			//    senddatatomobileclientsrv.request.data[i*8+5]=msg.width[i]%100;
			//    senddatatomobileclientsrv.request.data[i*8+6]=msg.height[i]/100;
			//    senddatatomobileclientsrv.request.data[i*8+7]=msg.height[i]%100;

		//		ROS_INFO_STREAM("i = "<<i);
				if( i < dectcount)
				{
				//	ROS_INFO_STREAM(msg.x[i]<<" "<<msg.y[i]<<" "<<msg.width[i]<<" "<<msg.height[i]);
			/*		senddatatomobileclientsrv[j].request.data[temp*8+0]=(char)msg.x[i]/100;
		//			ROS_INFO_STREAM("0");
					senddatatomobileclientsrv[j].request.data[temp*8+1]=(char)msg.x[i]%100;
		//			ROS_INFO_STREAM("1");
					senddatatomobileclientsrv[j].request.data[temp*8+2]=(char)msg.y[i]/100;
		//			ROS_INFO_STREAM("2");
					senddatatomobileclientsrv[j].request.data[temp*8+3]=(char)msg.y[i]%100;
		//			ROS_INFO_STREAM("3");
					senddatatomobileclientsrv[j].request.data[temp*8+4]=(char)msg.width[i]/100;
		//			ROS_INFO_STREAM("4");
					senddatatomobileclientsrv[j].request.data[temp*8+5]=(char)msg.width[i]%100;
		//			ROS_INFO_STREAM("5");
					senddatatomobileclientsrv[j].request.data[temp*8+6]=(char)msg.height[i]/100;
		//			ROS_INFO_STREAM("6");
					senddatatomobileclientsrv[j].request.data[temp*8+7]=(char)msg.height[i]%100;
	*/


					senddatatomobileclientsrv[j].request.data[temp*8+0]=msg.x[i]/100;
			//		ROS_INFO_STREAM(" 0 ="<<(int)senddatatomobileclientsrv[j].request.data[temp*8+0]);

		//			ROS_INFO_STREAM("0");
					senddatatomobileclientsrv[j].request.data[temp*8+1]=msg.x[i]%100;
			//		ROS_INFO_STREAM(" 1 ="<<(int)senddatatomobileclientsrv[j].request.data[temp*8+1]);
		//			ROS_INFO_STREAM("1");
					senddatatomobileclientsrv[j].request.data[temp*8+2]=msg.y[i]/100;
		//			ROS_INFO_STREAM("2");
					senddatatomobileclientsrv[j].request.data[temp*8+3]=msg.y[i]%100;
		//			ROS_INFO_STREAM("3");
					senddatatomobileclientsrv[j].request.data[temp*8+4]=msg.width[i]/100;
		//			ROS_INFO_STREAM("4");
					senddatatomobileclientsrv[j].request.data[temp*8+5]=msg.width[i]%100;
		//			ROS_INFO_STREAM("5");
					senddatatomobileclientsrv[j].request.data[temp*8+6]=msg.heigth[i]/100;
		//			ROS_INFO_STREAM("6");
					senddatatomobileclientsrv[j].request.data[temp*8+7]=msg.heigth[i]%100;
				}
				else
				{
					
				//	ROS_INFO_STREAM("dectcount -i "<<(dectcount -i));

					senddatatomobileclientsrv[j].request.data[temp*8+0]= 0 ;
		//			ROS_INFO_STREAM("0");
					senddatatomobileclientsrv[j].request.data[temp*8+1]= 0;
		//			ROS_INFO_STREAM("1");
					senddatatomobileclientsrv[j].request.data[temp*8+2]= 0;
		//			ROS_INFO_STREAM("2");
					senddatatomobileclientsrv[j].request.data[temp*8+3]= 0;
		//			ROS_INFO_STREAM("3");
					senddatatomobileclientsrv[j].request.data[temp*8+4]= 0;
		//			ROS_INFO_STREAM("4");
					senddatatomobileclientsrv[j].request.data[temp*8+5]= 0;
		//			ROS_INFO_STREAM("5");
					senddatatomobileclientsrv[j].request.data[temp*8+6]= 0;
		//			ROS_INFO_STREAM("6");
					senddatatomobileclientsrv[j].request.data[temp*8+7]= 0;
				}

				temp++;
				if((i+1)%6==0)
				{


					senddatatomobileclientsrv[j].request.data[48]=(int)dectcount;
					senddatatomobileclientsrv[j].request.data[49]=(int)(dectcount-i);
					//ROS_INFO_STREAM("decount-i "<<(dectcount -i));
					ROS_INFO_STREAM("[48]"<<(int)senddatatomobileclientsrv[j].request.data[48]<<" [49]= "<<(int)(senddatatomobileclientsrv[j].request.data[49]));

					senddatatomobileclient.call(senddatatomobileclientsrv[j]);
					j++;
					temp=0;
				}
			/*	else if(i == (dectcount-1))
				{
					ROS_INFO_STREAM("decount-i "<<(dectcount -i));
				}
			*/	
		//		ROS_INFO_STREAM("j= "<<j);
			//	ROS_INFO_STREAM("sizeof(senddatatomobileclientsrv) = "<<sizeof(senddatatomobileclientsrv));
			}

		//	senddatatomobileclient.call(senddatatomobileclientsrv);
		//	ROS_INFO_STREAM("count "<<dectcount);

	/* 
			if(senddatatomobileclientsrv[5].response.result)
				ROS_INFO_STREAM("send dect date to mobile success");
			else
				ROS_INFO_STREAM("send dect date to mobile error");
	*/
		}

    }


  void datafrommobilehandle(const dji_sdk::TransparentTransmissionData& msg)
  { 
    //start dect flag  
	if((int)msg.data[8]==88){
        jetson::flage myflag;
        myflag.flagTest = 1;

        ROS_INFO_STREAM("myflag : "<<myflag);
        startflag_pub.publish(myflag);
        
        
		dectstartflag = true;
		ROS_INFO_STREAM("dectstartflag :"<<dectstartflag+" msg.data[8] =  "<<(int)msg.data[8]);
	}
	//if(msg.data[0]!=0&&msg.data[1]!=0)
	
/*	else if((int)msg.data[8]==66)
	{ 
		dectstartflag  = false;
		ROS_INFO_STREAM("dectstartflag :"<<dectstartflag+" msg.data[8] =  "<<(int)msg.data[8]);
		return ;
	}*/
    //stop dect flag
	else if((int)msg.data[8]==66)
	{
        jetson::flage myflag;
        myflag.flagTest = 0;

        ROS_INFO_STREAM("myflag : "<<myflag);
        startflag_pub.publish(myflag);
		dectstartflag  = false;
		ROS_INFO_STREAM("dectstartflag :"<<dectstartflag+" msg.data[8] =  "<<(int)msg.data[8]);



        selectRect.x = (msg.data[0]*100+msg.data[1])/1.5;        
        selectRect.y = (msg.data[2]*100+msg.data[3])/1.5;
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

    if(bBeginKCF)
    { 
        result = tracker.update(rgbimage);
        cv::rectangle(rgbimage, result, cv::Scalar( 0, 255, 255 ), 1, 8 );
        enable_get_depth = true;
        senddatetomobile_kcf(result);
    }
    else
	{ 
        cv::rectangle(rgbimage, selectRect, cv::Scalar(255, 0, 0), 2, 8, 0);
	//	cout<<"not beigin. bBeginKCF is false"<<endl;
	}

	
    cv::imshow(RGB_WINDOW, rgbimage);
    cv::waitKey(1);
  }

    //send kcf date to mobile 
  bool senddatetomobile_kcf(cv::Rect resultrect){
	    ROS_INFO_STREAM("x = "<<resultrect.x<<" y = "<<resultrect.y<<" width = "<<result.width<<" height = "<<result.height);

		senddatatomobileclientsrv[0].request.data[0]=resultrect.x/100;
		senddatatomobileclientsrv[0].request.data[1]=resultrect.x%100;
		senddatatomobileclientsrv[0].request.data[2]=resultrect.y/100;
		senddatatomobileclientsrv[0].request.data[3]=resultrect.y%100;
		senddatatomobileclientsrv[0].request.data[4]=resultrect.width/100;
		senddatatomobileclientsrv[0].request.data[5]=resultrect.width%100;
		senddatatomobileclientsrv[0].request.data[6]=resultrect.height/100;
		senddatatomobileclientsrv[0].request.data[7]=resultrect.height%100;

        for(int i=8;i<48;i++)
		    senddatatomobileclientsrv[0].request.data[i]=0;


		senddatatomobileclientsrv[0].request.data[48]=1;
		senddatatomobileclientsrv[0].request.data[49]=80;

        //send date to mobile
		senddatatomobileclient.call(senddatatomobileclientsrv[0]);

		if(senddatatomobileclientsrv[0].response.result){

        //    ROS_INFO_STREAM("send dect date to mobile success");
	//	ROS_INFO_STREAM("[49] = "<<(int)senddatatomobileclientsrv[0].request.data[49]);
            return true;
		}
        else{
        //    ROS_INFO_STREAM("send dect date to mobile error");
            return false;
		}
		//	return true;
	  
  }

    //send dect date to mobile 
 /* bool senddatetomobile_dect(){

  }*/



};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "kcf_detect_node");
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
	//	time_t tt=time(NULL);
	//	tm* t=localtime(&tt);
//cout<<"time before publish "<<t->tm_year+1900<<"-"<<t->tm_mon+1<<"-"<<t->tm_mday<<" "<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec;
			ic.pub.publish(sendrect);
	//	t=localtime(&tt);
//cout<<"time after publish "<<t->tm_year+1900<<"-"<<t->tm_mon+1<<"-"<<t->tm_mday<<" "<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec;
		}
 

	//	if (cvWaitKey(33) == 'q')
    //  break;
	}

	return 0;
}

