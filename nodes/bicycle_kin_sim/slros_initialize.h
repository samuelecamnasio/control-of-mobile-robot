#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block bicycle_kin_sim/cmd_vel subscriber/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_bicycle_kin_sim_geometry_msgs_Twist> Sub_bicycle_kin_sim_17;

// For Block bicycle_kin_sim/Time publisher/Publish
extern SimulinkPublisher<rosgraph_msgs::Clock, SL_Bus_bicycle_kin_sim_rosgraph_msgs_Clock> Pub_bicycle_kin_sim_34;

// For Block bicycle_kin_sim/odom and tf publishers/Publish
extern SimulinkPublisher<nav_msgs::Odometry, SL_Bus_bicycle_kin_sim_nav_msgs_Odometry> Pub_bicycle_kin_sim_72;

// For Block bicycle_kin_sim/odom and tf publishers/Publish1
extern SimulinkPublisher<tf2_msgs::TFMessage, SL_Bus_bicycle_kin_sim_tf2_msgs_TFMessage> Pub_bicycle_kin_sim_85;

// For Block bicycle_kin_sim/odom and tf publishers/Publish2
extern SimulinkPublisher<nav_msgs::Odometry, SL_Bus_bicycle_kin_sim_nav_msgs_Odometry> Pub_bicycle_kin_sim_118;

void slros_node_init(int argc, char** argv);

#endif
