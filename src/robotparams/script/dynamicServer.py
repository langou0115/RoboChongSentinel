#!/usr/bin/env python3

import rospy
from dynamic_reconfigure.server import Server
from robotparams.cfg import dynamictoolsConfig

# 将更改的参数同步到参数服务器中
def dynamic_reconfigure_callback(config, level):
    # Update rosparam values based on dynamic reconfigure
    rospy.set_param('gimbalPx', config.gimbalPx)
    rospy.set_param('gimbalIx', config.gimbalIx)
    rospy.set_param('gimbalDx', config.gimbalDx)

    rospy.set_param('gimbalPy', config.gimbalPy)
    rospy.set_param('gimbalIy', config.gimbalIy)
    rospy.set_param('gimbalDy', config.gimbalDy)

    rospy.set_param('gimbalPz', config.gimbalPz)
    rospy.set_param('gimbalIz', config.gimbalIz)
    rospy.set_param('gimbalDz', config.gimbalDz)

    return config

if __name__ == "__main__":
    rospy.init_node('dynamic_reconfig_to_rosparam_node')

    # Set up dynamic reconfigure server
    srv = Server(dynamictoolsConfig, dynamic_reconfigure_callback)

    rospy.spin()
