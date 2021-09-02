#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block planPublisher_test/Single plan message publisher/Path publisher Single execution/Publish
extern SimulinkPublisher<nav_msgs::Path, SL_Bus_planPublisher_test_nav_msgs_Path> Pub_planPublisher_test_5;

void slros_node_init(int argc, char** argv);

#endif
