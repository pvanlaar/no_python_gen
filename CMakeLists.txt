cmake_minimum_required(VERSION 3.0.2)
project(no_python_gen)

find_package(catkin REQUIRED COMPONENTS 
    roscpp
    message_generation 
    std_msgs
)

add_service_files(
  FILES
  ExampleSrv.srv
)

generate_messages(
  LANGS
    gencpp # no generation for python and other languages than c++
)

catkin_package(
 CATKIN_DEPENDS 
    std_msgs
    message_runtime
)

###########
## Build ##
###########

add_executable(example_publisher
    src/main.cpp
)

target_include_directories(example_publisher
PRIVATE
    ${catkin_INCLUDE_DIRS}
)

target_link_libraries(example_publisher
PRIVATE
    ${catkin_LIBRARIES}
)

add_dependencies(example_publisher ${PROJECT_NAME}_generate_messages_cpp)
