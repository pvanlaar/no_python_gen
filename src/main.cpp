#include "ros/ros.h"
#include "no_python_gen/ExampleSrv.h"

bool callback(no_python_gen::ExampleSrvRequest&, no_python_gen::ExampleSrvResponse&) {
    return true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "example_publisher");
    auto nodeHandle = ros::NodeHandle{"~"};
    auto spinner = ros::AsyncSpinner{4};
    spinner.start();

    auto server = nodeHandle.advertiseService("/example_srv", callback);

    // auto publisher = nodeHandle.advertise<no_python_gen::ExampleMsg>("/example_topic", 1);

    ros::waitForShutdown();
}