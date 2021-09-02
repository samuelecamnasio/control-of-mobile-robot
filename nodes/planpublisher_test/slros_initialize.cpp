#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "planPublisher_test";

// For Block planPublisher_test/Single plan message publisher/Path publisher Single execution/Publish
SimulinkPublisher<nav_msgs::Path, SL_Bus_planPublisher_test_nav_msgs_Path> Pub_planPublisher_test_5;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

