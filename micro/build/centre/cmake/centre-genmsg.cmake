# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "centre: 1 messages, 0 services")

set(MSG_I_FLAGS "-Icentre:/home/wgx/Downloads/qeyy/src/micro/src/centre/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(centre_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg" NAME_WE)
add_custom_target(_centre_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "centre" "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(centre
  "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/centre
)

### Generating Services

### Generating Module File
_generate_module_cpp(centre
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/centre
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(centre_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(centre_generate_messages centre_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg" NAME_WE)
add_dependencies(centre_generate_messages_cpp _centre_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(centre_gencpp)
add_dependencies(centre_gencpp centre_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS centre_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(centre
  "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/centre
)

### Generating Services

### Generating Module File
_generate_module_eus(centre
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/centre
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(centre_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(centre_generate_messages centre_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg" NAME_WE)
add_dependencies(centre_generate_messages_eus _centre_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(centre_geneus)
add_dependencies(centre_geneus centre_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS centre_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(centre
  "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/centre
)

### Generating Services

### Generating Module File
_generate_module_lisp(centre
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/centre
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(centre_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(centre_generate_messages centre_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg" NAME_WE)
add_dependencies(centre_generate_messages_lisp _centre_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(centre_genlisp)
add_dependencies(centre_genlisp centre_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS centre_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(centre
  "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/centre
)

### Generating Services

### Generating Module File
_generate_module_nodejs(centre
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/centre
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(centre_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(centre_generate_messages centre_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg" NAME_WE)
add_dependencies(centre_generate_messages_nodejs _centre_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(centre_gennodejs)
add_dependencies(centre_gennodejs centre_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS centre_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(centre
  "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/centre
)

### Generating Services

### Generating Module File
_generate_module_py(centre
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/centre
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(centre_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(centre_generate_messages centre_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wgx/Downloads/qeyy/src/micro/src/centre/msg/event.msg" NAME_WE)
add_dependencies(centre_generate_messages_py _centre_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(centre_genpy)
add_dependencies(centre_genpy centre_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS centre_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/centre)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/centre
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(centre_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/centre)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/centre
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(centre_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/centre)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/centre
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(centre_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/centre)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/centre
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(centre_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/centre)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/centre\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/centre
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(centre_generate_messages_py std_msgs_generate_messages_py)
endif()
