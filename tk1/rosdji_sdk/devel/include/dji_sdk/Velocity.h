// Generated by gencpp from file dji_sdk/Velocity.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_VELOCITY_H
#define DJI_SDK_MESSAGE_VELOCITY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace dji_sdk
{
template <class ContainerAllocator>
struct Velocity_
{
  typedef Velocity_<ContainerAllocator> Type;

  Velocity_()
    : header()
    , ts(0)
    , vx(0.0)
    , vy(0.0)
    , vz(0.0)
    , health_flag(0)  {
    }
  Velocity_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , ts(0)
    , vx(0.0)
    , vy(0.0)
    , vz(0.0)
    , health_flag(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _ts_type;
  _ts_type ts;

   typedef float _vx_type;
  _vx_type vx;

   typedef float _vy_type;
  _vy_type vy;

   typedef float _vz_type;
  _vz_type vz;

   typedef uint8_t _health_flag_type;
  _health_flag_type health_flag;




  typedef boost::shared_ptr< ::dji_sdk::Velocity_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::Velocity_<ContainerAllocator> const> ConstPtr;

}; // struct Velocity_

typedef ::dji_sdk::Velocity_<std::allocator<void> > Velocity;

typedef boost::shared_ptr< ::dji_sdk::Velocity > VelocityPtr;
typedef boost::shared_ptr< ::dji_sdk::Velocity const> VelocityConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::Velocity_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::Velocity_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/dji_sdk/msg', '/home/ubuntu/cc/rosdji_sdk/devel/share/dji_sdk/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::Velocity_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::Velocity_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::Velocity_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::Velocity_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::Velocity_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::Velocity_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::Velocity_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a89d7216b2636ddc4fc4375ae77dc15c";
  }

  static const char* value(const ::dji_sdk::Velocity_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa89d7216b2636ddcULL;
  static const uint64_t static_value2 = 0x4fc4375ae77dc15cULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::Velocity_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/Velocity";
  }

  static const char* value(const ::dji_sdk::Velocity_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::Velocity_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
int32 ts\n\
float32 vx\n\
float32 vy\n\
float32 vz\n\
uint8 health_flag\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::dji_sdk::Velocity_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::Velocity_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.ts);
      stream.next(m.vx);
      stream.next(m.vy);
      stream.next(m.vz);
      stream.next(m.health_flag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Velocity_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::Velocity_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::Velocity_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "ts: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ts);
    s << indent << "vx: ";
    Printer<float>::stream(s, indent + "  ", v.vx);
    s << indent << "vy: ";
    Printer<float>::stream(s, indent + "  ", v.vy);
    s << indent << "vz: ";
    Printer<float>::stream(s, indent + "  ", v.vz);
    s << indent << "health_flag: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.health_flag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_VELOCITY_H
