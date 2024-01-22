#!/usr/bin/env python3

import rospy
from dynamic_reconfigure.server import Server
from robotparams.cfg import dynamictoolsConfig

# 将更改的参数同步到参数服务器中
def dynamic_reconfigure_callback(config, level):
    # Update rosparam values based on dynamic reconfigure
    rospy.set_param('gimbal_px', config.gimbal_px)
    rospy.set_param('gimbal_ix', config.gimbal_ix)
    rospy.set_param('gimbal_dx', config.gimbal_dx)

    rospy.set_param('gimbal_py', config.gimbal_py)
    rospy.set_param('gimbal_iy', config.gimbal_iy)
    rospy.set_param('gimbal_dy', config.gimbal_dy)

    rospy.set_param('gimbal_pz', config.gimbal_pz)
    rospy.set_param('gimbal_iz', config.gimbal_iz)
    rospy.set_param('gimbal_dz', config.gimbal_dz)

    return config

if __name__ == "__main__":
    rospy.init_node('dynamic_reconfig_to_rosparam_node')

    # Set up dynamic reconfigure server
    srv = Server(dynamictoolsConfig, dynamic_reconfigure_callback)

    rospy.spin()
