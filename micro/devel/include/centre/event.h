// Generated by gencpp from file centre/event.msg
// DO NOT EDIT!


#ifndef CENTRE_MESSAGE_EVENT_H
#define CENTRE_MESSAGE_EVENT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace centre
{
template <class ContainerAllocator>
struct event_
{
  typedef event_<ContainerAllocator> Type;

  event_()
    : eventID(0)
    , data()  {
    }
  event_(const ContainerAllocator& _alloc)
    : eventID(0)
    , data(_alloc)  {
  (void)_alloc;
    }



   typedef uint32_t _eventID_type;
  _eventID_type eventID;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::centre::event_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::centre::event_<ContainerAllocator> const> ConstPtr;

}; // struct event_

typedef ::centre::event_<std::allocator<void> > event;

typedef boost::shared_ptr< ::centre::event > eventPtr;
typedef boost::shared_ptr< ::centre::event const> eventConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::centre::event_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::centre::event_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace centre

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'centre': ['/home/wgx/Downloads/qeyy/src/micro/src/centre/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::centre::event_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::centre::event_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::centre::event_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::centre::event_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::centre::event_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::centre::event_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::centre::event_<ContainerAllocator> >
{
  static const char* value()
  {
    return "306c620ab5bfeb5b7505399af72d2b3e";
  }

  static const char* value(const ::centre::event_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x306c620ab5bfeb5bULL;
  static const uint64_t static_value2 = 0x7505399af72d2b3eULL;
};

template<class ContainerAllocator>
struct DataType< ::centre::event_<ContainerAllocator> >
{
  static const char* value()
  {
    return "centre/event";
  }

  static const char* value(const ::centre::event_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::centre::event_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 eventID\n\
uint8[] data\n\
";
  }

  static const char* value(const ::centre::event_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::centre::event_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.eventID);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct event_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::centre::event_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::centre::event_<ContainerAllocator>& v)
  {
    s << indent << "eventID: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.eventID);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CENTRE_MESSAGE_EVENT_H