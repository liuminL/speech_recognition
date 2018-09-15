
(cl:in-package :asdf)

(defsystem "centre-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "event" :depends-on ("_package_event"))
    (:file "_package_event" :depends-on ("_package"))
  ))