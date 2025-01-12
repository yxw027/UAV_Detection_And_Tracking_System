// Generated by gencpp from file dji_sdk/MissionStatusHotpoint.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_MISSIONSTATUSHOTPOINT_H
#define DJI_SDK_MESSAGE_MISSIONSTATUSHOTPOINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dji_sdk
{
template <class ContainerAllocator>
struct MissionStatusHotpoint_
{
  typedef MissionStatusHotpoint_<ContainerAllocator> Type;

  MissionStatusHotpoint_()
    : mission_type(0)
    , mission_status(0)
    , hotpoint_radius(0)
    , error_code(0)
    , hotpoint_velocity(0)  {
    }
  MissionStatusHotpoint_(const ContainerAllocator& _alloc)
    : mission_type(0)
    , mission_status(0)
    , hotpoint_radius(0)
    , error_code(0)
    , hotpoint_velocity(0)  {
  (void)_alloc;
    }



   typedef uint8_t _mission_type_type;
  _mission_type_type mission_type;

   typedef uint8_t _mission_status_type;
  _mission_status_type mission_status;

   typedef uint16_t _hotpoint_radius_type;
  _hotpoint_radius_type hotpoint_radius;

   typedef uint8_t _error_code_type;
  _error_code_type error_code;

   typedef uint8_t _hotpoint_velocity_type;
  _hotpoint_velocity_type hotpoint_velocity;




  typedef boost::shared_ptr< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> const> ConstPtr;

}; // struct MissionStatusHotpoint_

typedef ::dji_sdk::MissionStatusHotpoint_<std::allocator<void> > MissionStatusHotpoint;

typedef boost::shared_ptr< ::dji_sdk::MissionStatusHotpoint > MissionStatusHotpointPtr;
typedef boost::shared_ptr< ::dji_sdk::MissionStatusHotpoint const> MissionStatusHotpointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/dji_sdk/msg', '/home/ubuntu/cc/rosdji_sdk/devel/share/dji_sdk/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8139577a287bd3bb109446868782e2f7";
  }

  static const char* value(const ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8139577a287bd3bbULL;
  static const uint64_t static_value2 = 0x109446868782e2f7ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/MissionStatusHotpoint";
  }

  static const char* value(const ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 mission_type\n\
uint8 mission_status\n\
uint16 hotpoint_radius\n\
uint8 error_code\n\
uint8 hotpoint_velocity\n\
";
  }

  static const char* value(const ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mission_type);
      stream.next(m.mission_status);
      stream.next(m.hotpoint_radius);
      stream.next(m.error_code);
      stream.next(m.hotpoint_velocity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MissionStatusHotpoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::MissionStatusHotpoint_<ContainerAllocator>& v)
  {
    s << indent << "mission_type: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mission_type);
    s << indent << "mission_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mission_status);
    s << indent << "hotpoint_radius: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.hotpoint_radius);
    s << indent << "error_code: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.error_code);
    s << indent << "hotpoint_velocity: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.hotpoint_velocity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_MISSIONSTATUSHOTPOINT_H
