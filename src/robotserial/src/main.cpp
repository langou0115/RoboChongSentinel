#include "ros/ros.h"
#include "serial.hpp"

int main(int argc, char** argv) 
{
     setlocale(LC_ALL,"");

    ros::init(argc,argv,"robot_serial");
    ros::NodeHandle nh;

    // 订阅的话题
    ros::Subscriber sub_gimbal_vel = nh.subscribe("robot_gimbal_vel", 100, gimbalVelcmdCb);
    ros::Subscriber sub_base_vel = nh.subscribe("robot_base_vel", 100, baseVelcmdCb);

    ros::spin();
    return 0;
}