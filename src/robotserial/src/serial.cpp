#include "serial.hpp"

GimbalVel gimbal_vel;
BaseVel base_vel;

/**
 * @brief 将云台速度信息发送给下位机
 * @author zhuyiming
 * 
 * @param msg 云台速度信息
 */
void gimbalVelcmdCb(const geometry_msgs::Twist::ConstPtr &msg)
{
    // debug
    ROS_INFO("gimbal: %.2lf, %.2lf, %.2lf", msg->angular.x, msg->angular.y, msg->angular.z);

    gimbal_vel.roll = msg->angular.x;
    gimbal_vel.yaw = msg->angular.y;
    gimbal_vel.pitch = msg->angular.z;

    // 发送 gimbalvel结构体
}

/**
 * @brief 将底盘速度信息发送给下位机
 * @author zhuyiming
 * 
 * @param msg 底盘速度信息
 */
void baseVelcmdCb(const geometry_msgs::Twist::ConstPtr &msg)
{
    // debug
    ROS_INFO("base: %.2lf, %.2lf, %.2lf, %.2lf", msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.y);

    base_vel.vel_x = msg->linear.x;
    base_vel.vel_y = msg->linear.y;
    base_vel.vel_z = msg->linear.z;
    base_vel.yaw = msg->angular.y;

    //发送basevel结构体
}
