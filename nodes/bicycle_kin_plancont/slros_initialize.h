#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block bicycle_kin_planCont/Pose subscriber/Subscribe
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_bicycle_kin_planCont_nav_msgs_Odometry> Sub_bicycle_kin_planCont_53;

// For Block bicycle_kin_planCont/Trajectory interpolator/Subscribe
extern SimulinkSubscriber<nav_msgs::Path, SL_Bus_bicycle_kin_planCont_nav_msgs_Path> Sub_bicycle_kin_planCont_64;

// For Block bicycle_kin_planCont/Command publisher/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_bicycle_kin_planCont_geometry_msgs_Twist> Pub_bicycle_kin_planCont_9;

// For Block bicycle_kin_planCont/Trajectory interpolator/history objective publisher/Publish
extern SimulinkPublisher<geometry_msgs::PointStamped, SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped> Pub_bicycle_kin_planCont_213;

// For Block bicycle_kin_planCont/Trajectory interpolator/step interpolated objective publisher/Publish
extern SimulinkPublisher<geometry_msgs::PointStamped, SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped> Pub_bicycle_kin_planCont_195;

// For Block bicycle_kin_planCont/Trajectory interpolator/step objective publisher/Publish
extern SimulinkPublisher<geometry_msgs::PointStamped, SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped> Pub_bicycle_kin_planCont_169;

void slros_node_init(int argc, char** argv);

#endif
