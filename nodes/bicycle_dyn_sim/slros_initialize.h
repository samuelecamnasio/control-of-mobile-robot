#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block bicycle_dyn_sim/cmd_vel subscriber/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_bicycle_dyn_sim_geometry_msgs_Twist> Sub_bicycle_dyn_sim_17;

// For Block bicycle_dyn_sim/Time publisher/Publish
extern SimulinkPublisher<rosgraph_msgs::Clock, SL_Bus_bicycle_dyn_sim_rosgraph_msgs_Clock> Pub_bicycle_dyn_sim_134;

// For Block bicycle_dyn_sim/odom and tf publishers1/Publish
extern SimulinkPublisher<nav_msgs::Odometry, SL_Bus_bicycle_dyn_sim_nav_msgs_Odometry> Pub_bicycle_dyn_sim_126;

// For Block bicycle_dyn_sim/odom and tf publishers1/Publish1
extern SimulinkPublisher<tf2_msgs::TFMessage, SL_Bus_bicycle_dyn_sim_tf2_msgs_TFMessage> Pub_bicycle_dyn_sim_127;

// For Block bicycle_dyn_sim/odom and tf publishers1/Publish2
extern SimulinkPublisher<nav_msgs::Odometry, SL_Bus_bicycle_dyn_sim_nav_msgs_Odometry> Pub_bicycle_dyn_sim_128;

void slros_node_init(int argc, char** argv);

#endif
