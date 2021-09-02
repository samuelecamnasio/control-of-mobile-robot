//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: planPublisher_test_RRT_types.h
//
// Code generated for Simulink model 'planPublisher_test_RRT'.
//
// Model version                  : 2.32
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Jul 15 19:04:00 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_planPublisher_test_RRT_types_h_
#define RTW_HEADER_planPublisher_test_RRT_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_planPublisher_test_RRT_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_planPublisher_test_RRT_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
} SL_Bus_planPublisher_test_RRT_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_planPublisher_test_RRT_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_planPublisher_test_RRT_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_planPublisher_test_RRT_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_planPublisher_test_RRT_geometry_msgs_Quaternion Orientation;
} SL_Bus_planPublisher_test_RRT_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_geometry_msgs_PoseStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_geometry_msgs_PoseStamped_

// MsgType=geometry_msgs/PoseStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_planPublisher_test_RRT_std_msgs_Header Header;

  // MsgType=geometry_msgs/Pose
  SL_Bus_planPublisher_test_RRT_geometry_msgs_Pose Pose;
} SL_Bus_planPublisher_test_RRT_geometry_msgs_PoseStamped;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_nav_msgs_Path_
#define DEFINED_TYPEDEF_FOR_SL_Bus_planPublisher_test_RRT_nav_msgs_Path_

// MsgType=nav_msgs/Path
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_planPublisher_test_RRT_std_msgs_Header Header;

  // MsgType=geometry_msgs/PoseStamped:IsVarLen=1:VarLenCategory=data:VarLenElem=Poses_SL_Info:TruncateAction=warn 
  SL_Bus_planPublisher_test_RRT_geometry_msgs_PoseStamped Poses[25];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Poses
  SL_Bus_ROSVariableLengthArrayInfo Poses_SL_Info;
} SL_Bus_planPublisher_test_RRT_nav_msgs_Path;

#endif

#ifndef struct_tag_KSdGoEc2IyOHz4CLi4rcCD
#define struct_tag_KSdGoEc2IyOHz4CLi4rcCD

struct tag_KSdGoEc2IyOHz4CLi4rcCD
{
  int32_T __dummy;
};

#endif                                 //struct_tag_KSdGoEc2IyOHz4CLi4rcCD

#ifndef typedef_f_robotics_slcore_internal_bl_T
#define typedef_f_robotics_slcore_internal_bl_T

typedef tag_KSdGoEc2IyOHz4CLi4rcCD f_robotics_slcore_internal_bl_T;

#endif                                 //typedef_f_robotics_slcore_internal_bl_T

#ifndef struct_tag_3Hmw7UcxkCbDeuTJoUkJ0G
#define struct_tag_3Hmw7UcxkCbDeuTJoUkJ0G

struct tag_3Hmw7UcxkCbDeuTJoUkJ0G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                 //struct_tag_3Hmw7UcxkCbDeuTJoUkJ0G

#ifndef typedef_ros_slros_internal_block_Curr_T
#define typedef_ros_slros_internal_block_Curr_T

typedef tag_3Hmw7UcxkCbDeuTJoUkJ0G ros_slros_internal_block_Curr_T;

#endif                                 //typedef_ros_slros_internal_block_Curr_T

#ifndef struct_tag_D6QYIVJDjoKN0blLVEpT8F
#define struct_tag_D6QYIVJDjoKN0blLVEpT8F

struct tag_D6QYIVJDjoKN0blLVEpT8F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_D6QYIVJDjoKN0blLVEpT8F

#ifndef typedef_ros_slroscpp_internal_block_P_T
#define typedef_ros_slroscpp_internal_block_P_T

typedef tag_D6QYIVJDjoKN0blLVEpT8F ros_slroscpp_internal_block_P_T;

#endif                                 //typedef_ros_slroscpp_internal_block_P_T

// Parameters (default storage)
typedef struct P_planPublisher_test_RRT_T_ P_planPublisher_test_RRT_T;

// Forward declaration for rtModel
typedef struct tag_RTM_planPublisher_test_RR_T RT_MODEL_planPublisher_test_R_T;

#endif                            // RTW_HEADER_planPublisher_test_RRT_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
