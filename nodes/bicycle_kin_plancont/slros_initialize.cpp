#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "bicycle_kin_planCont";

// For Block bicycle_kin_planCont/Pose subscriber/Subscribe
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_bicycle_kin_planCont_nav_msgs_Odometry> Sub_bicycle_kin_planCont_53;

// For Block bicycle_kin_planCont/Trajectory interpolator/Subscribe
SimulinkSubscriber<nav_msgs::Path, SL_Bus_bicycle_kin_planCont_nav_msgs_Path> Sub_bicycle_kin_planCont_64;

// For Block bicycle_kin_planCont/Command publisher/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_bicycle_kin_planCont_geometry_msgs_Twist> Pub_bicycle_kin_planCont_9;

// For Block bicycle_kin_planCont/Trajectory interpolator/history objective publisher/Publish
SimulinkPublisher<geometry_msgs::PointStamped, SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped> Pub_bicycle_kin_planCont_213;

// For Block bicycle_kin_planCont/Trajectory interpolator/step interpolated objective publisher/Publish
SimulinkPublisher<geometry_msgs::PointStamped, SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped> Pub_bicycle_kin_planCont_195;

// For Block bicycle_kin_planCont/Trajectory interpolator/step objective publisher/Publish
SimulinkPublisher<geometry_msgs::PointStamped, SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped> Pub_bicycle_kin_planCont_169;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

