; Auto-generated. Do not edit!


(cl:in-package centre-msg)


;//! \htmlinclude event.msg.html

(cl:defclass <event> (roslisp-msg-protocol:ros-message)
  ((eventID
    :reader eventID
    :initarg :eventID
    :type cl:integer
    :initform 0)
   (data
    :reader data
    :initarg :data
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass event (<event>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <event>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'event)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name centre-msg:<event> is deprecated: use centre-msg:event instead.")))

(cl:ensure-generic-function 'eventID-val :lambda-list '(m))
(cl:defmethod eventID-val ((m <event>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader centre-msg:eventID-val is deprecated.  Use centre-msg:eventID instead.")
  (eventID m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <event>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader centre-msg:data-val is deprecated.  Use centre-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <event>) ostream)
  "Serializes a message object of type '<event>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'eventID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'eventID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'eventID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'eventID)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <event>) istream)
  "Deserializes a message object of type '<event>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'eventID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'eventID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'eventID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'eventID)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<event>)))
  "Returns string type for a message object of type '<event>"
  "centre/event")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'event)))
  "Returns string type for a message object of type 'event"
  "centre/event")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<event>)))
  "Returns md5sum for a message object of type '<event>"
  "306c620ab5bfeb5b7505399af72d2b3e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'event)))
  "Returns md5sum for a message object of type 'event"
  "306c620ab5bfeb5b7505399af72d2b3e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<event>)))
  "Returns full string definition for message of type '<event>"
  (cl:format cl:nil "uint32 eventID~%uint8[] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'event)))
  "Returns full string definition for message of type 'event"
  (cl:format cl:nil "uint32 eventID~%uint8[] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <event>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <event>))
  "Converts a ROS message object to a list"
  (cl:list 'event
    (cl:cons ':eventID (eventID msg))
    (cl:cons ':data (data msg))
))
