#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "planPublisher_test_RRT";

// For Block planPublisher_test_RRT/Single plan message publisher/Path publisher Single execution/Publish
SimulinkPublisher<nav_msgs::Path, SL_Bus_planPublisher_test_RRT_nav_msgs_Path> Pub_planPublisher_test_RRT_5;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

