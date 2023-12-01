#include "serial.hpp"

GimbalVel gimbalvel;
BaseVel basevel;

/**
 * @brief 将云台速度信息发送给下位机
 * @author zhuyiming
 * 
 * @param msg 云台速度信息
 */
void gimbal_velcmd_cb(const geometry_msgs::Twist::ConstPtr &msg)
{
    // debug
    ROS_INFO("gimbal: %.2lf, %.2lf, %.2lf", msg->angular.x, msg->angular.y, msg->angular.z);

    gimbalvel.roll = msg->angular.x;
    gimbalvel.yaw = msg->angular.y;
    gimbalvel.pitch = msg->angular.z;

    // 发送 gimbalvel结构体
}

/**
 * @brief 将底盘速度信息发送给下位机
 * @author zhuyiming
 * 
 * @param msg 底盘速度信息
 */
void base_velcmd_cb(const geometry_msgs::Twist::ConstPtr &msg)
{
    // debug
    ROS_INFO("base: %.2lf, %.2lf, %.2lf, %.2lf", msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.y);

    basevel.velx = msg->linear.x;
    basevel.vely = msg->linear.y;
    basevel.velz = msg->linear.z;
    basevel.yaw = msg->angular.y;

    //发送basevel结构体
}
