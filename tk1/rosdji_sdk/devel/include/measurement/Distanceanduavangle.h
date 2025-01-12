// Generated by gencpp from file measurement/Distanceanduavangle.msg
// DO NOT EDIT!


#ifndef MEASUREMENT_MESSAGE_DISTANCEANDUAVANGLE_H
#define MEASUREMENT_MESSAGE_DISTANCEANDUAVANGLE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace measurement
{
template <class ContainerAllocator>
struct Distanceanduavangle_
{
  typedef Distanceanduavangle_<ContainerAllocator> Type;

  Distanceanduavangle_()
    : distance(0.0)
    , uavangle(0.0)  {
    }
  Distanceanduavangle_(const ContainerAllocator& _alloc)
    : distance(0.0)
    , uavangle(0.0)  {
  (void)_alloc;
    }



   typedef double _distance_type;
  _distance_type distance;

   typedef double _uavangle_type;
  _uavangle_type uavangle;




  typedef boost::shared_ptr< ::measurement::Distanceanduavangle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::measurement::Distanceanduavangle_<ContainerAllocator> const> ConstPtr;

}; // struct Distanceanduavangle_

typedef ::measurement::Distanceanduavangle_<std::allocator<void> > Distanceanduavangle;

typedef boost::shared_ptr< ::measurement::Distanceanduavangle > DistanceanduavanglePtr;
typedef boost::shared_ptr< ::measurement::Distanceanduavangle const> DistanceanduavangleConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::measurement::Distanceanduavangle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::measurement::Distanceanduavangle_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace measurement

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'measurement': ['/home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/measurement/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::measurement::Distanceanduavangle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::measurement::Distanceanduavangle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::measurement::Distanceanduavangle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::measurement::Distanceanduavangle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::measurement::Distanceanduavangle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::measurement::Distanceanduavangle_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::measurement::Distanceanduavangle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a023f694bd6f70a056da69c77b7bd085";
  }

  static const char* value(const ::measurement::Distanceanduavangle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa023f694bd6f70a0ULL;
  static const uint64_t static_value2 = 0x56da69c77b7bd085ULL;
};

template<class ContainerAllocator>
struct DataType< ::measurement::Distanceanduavangle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "measurement/Distanceanduavangle";
  }

  static const char* value(const ::measurement::Distanceanduavangle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::measurement::Distanceanduavangle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 distance\n\
float64 uavangle\n\
";
  }

  static const char* value(const ::measurement::Distanceanduavangle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::measurement::Distanceanduavangle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.distance);
      stream.next(m.uavangle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Distanceanduavangle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::measurement::Distanceanduavangle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::measurement::Distanceanduavangle_<ContainerAllocator>& v)
  {
    s << indent << "distance: ";
    Printer<double>::stream(s, indent + "  ", v.distance);
    s << indent << "uavangle: ";
    Printer<double>::stream(s, indent + "  ", v.uavangle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MEASUREMENT_MESSAGE_DISTANCEANDUAVANGLE_H
