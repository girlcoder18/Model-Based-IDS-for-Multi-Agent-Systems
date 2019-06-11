#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block triangle/camera/Subscribe1
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_triangle_geometry_msgs_PoseStamped> Sub_triangle_948;

// For Block triangle/camera/Subscribe2
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_triangle_geometry_msgs_PoseStamped> Sub_triangle_949;

// For Block triangle/Command robot/Command Velocity Publisher/Publish2
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_triangle_geometry_msgs_Twist> Pub_triangle_905;

void slros_node_init(int argc, char** argv);

#endif
