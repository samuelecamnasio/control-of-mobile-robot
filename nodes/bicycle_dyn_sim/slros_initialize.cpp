#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "bicycle_dyn_sim";

// For Block bicycle_dyn_sim/cmd_vel subscriber/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_bicycle_dyn_sim_geometry_msgs_Twist> Sub_bicycle_dyn_sim_17;

// For Block bicycle_dyn_sim/Time publisher/Publish
SimulinkPublisher<rosgraph_msgs::Clock, SL_Bus_bicycle_dyn_sim_rosgraph_msgs_Clock> Pub_bicycle_dyn_sim_134;

// For Block bicycle_dyn_sim/odom and tf publishers1/Publish
SimulinkPublisher<nav_msgs::Odometry, SL_Bus_bicycle_dyn_sim_nav_msgs_Odometry> Pub_bicycle_dyn_sim_126;

// For Block bicycle_dyn_sim/odom and tf publishers1/Publish1
SimulinkPublisher<tf2_msgs::TFMessage, SL_Bus_bicycle_dyn_sim_tf2_msgs_TFMessage> Pub_bicycle_dyn_sim_127;

// For Block bicycle_dyn_sim/odom and tf publishers1/Publish2
SimulinkPublisher<nav_msgs::Odometry, SL_Bus_bicycle_dyn_sim_nav_msgs_Odometry> Pub_bicycle_dyn_sim_128;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

