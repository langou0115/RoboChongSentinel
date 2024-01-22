#ifndef _SERIAL_H_
#define _SERIAL_H_
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

/**
 * 云台只需要发送roll yaw pitch
*/
struct GimbalVel
{
    double roll;
    double yaw;
    double pitch;
};

/**
 * 发送底盘的速度，vel是线速度，roll yaw pitch是角速度
*/
struct BaseVel{
    double vel_x;
    double vel_y;
    double vel_z;
    double yaw;
};

void gimbalVelcmdCb(const geometry_msgs::Twist::ConstPtr& msg);
void baseVelcmdCb(const geometry_msgs::Twist::ConstPtr& msg);

#endif // !_SERIAL_H_
