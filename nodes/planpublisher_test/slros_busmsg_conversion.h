#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <nav_msgs/Path.h>
#include <ros/time.h>
#include <std_msgs/Header.h>
#include "planPublisher_test_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_planPublisher_test_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_planPublisher_test_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_planPublisher_test_geometry_msgs_Pose const* busPtr);
void convertToBus(SL_Bus_planPublisher_test_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr);

void convertFromBus(geometry_msgs::PoseStamped* msgPtr, SL_Bus_planPublisher_test_geometry_msgs_PoseStamped const* busPtr);
void convertToBus(SL_Bus_planPublisher_test_geometry_msgs_PoseStamped* busPtr, geometry_msgs::PoseStamped const* msgPtr);

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_planPublisher_test_geometry_msgs_Quaternion const* busPtr);
void convertToBus(SL_Bus_planPublisher_test_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convertFromBus(nav_msgs::Path* msgPtr, SL_Bus_planPublisher_test_nav_msgs_Path const* busPtr);
void convertToBus(SL_Bus_planPublisher_test_nav_msgs_Path* busPtr, nav_msgs::Path const* msgPtr);

void convertFromBus(ros::Time* msgPtr, SL_Bus_planPublisher_test_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_planPublisher_test_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_planPublisher_test_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_planPublisher_test_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
