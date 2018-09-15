;; Auto-generated. Do not edit!


(when (boundp 'centre::event)
  (if (not (find-package "CENTRE"))
    (make-package "CENTRE"))
  (shadow 'event (find-package "CENTRE")))
(unless (find-package "CENTRE::EVENT")
  (make-package "CENTRE::EVENT"))

(in-package "ROS")
;;//! \htmlinclude event.msg.html


(defclass centre::event
  :super ros::object
  :slots (_eventID _data ))

(defmethod centre::event
  (:init
   (&key
    ((:eventID __eventID) 0)
    ((:data __data) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _eventID (round __eventID))
   (setq _data __data)
   self)
  (:eventID
   (&optional __eventID)
   (if __eventID (setq _eventID __eventID)) _eventID)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; uint32 _eventID
    4
    ;; uint8[] _data
    (* 1    (length _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _eventID
       (write-long _eventID s)
     ;; uint8[] _data
     (write-long (length _data) s)
     (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _eventID
     (setq _eventID (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8[] _data
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _data (make-array n :element-type :char))
     (replace _data buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(setf (get centre::event :md5sum-) "306c620ab5bfeb5b7505399af72d2b3e")
(setf (get centre::event :datatype-) "centre/event")
(setf (get centre::event :definition-)
      "uint32 eventID
uint8[] data

")



(provide :centre/event "306c620ab5bfeb5b7505399af72d2b3e")


