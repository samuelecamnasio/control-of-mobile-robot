//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: bicycle_kin_sim_types.h
//
// Code generated for Simulink model 'bicycle_kin_sim'.
//
// Model version                  : 2.52
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Jul 15 18:51:53 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_bicycle_kin_sim_types_h_
#define RTW_HEADER_bicycle_kin_sim_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_bicycle_kin_sim_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_rosgraph_msgs_Clock_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_rosgraph_msgs_Clock_

// MsgType=rosgraph_msgs/Clock
typedef struct {
  // MsgType=ros_time/Time
  SL_Bus_bicycle_kin_sim_ros_time_Time Clock_;
} SL_Bus_bicycle_kin_sim_rosgraph_msgs_Clock;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_bicycle_kin_sim_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_bicycle_kin_sim_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_bicycle_kin_sim_geometry_msgs_Vector3 Angular;
} SL_Bus_bicycle_kin_sim_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_bicycle_kin_sim_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
} SL_Bus_bicycle_kin_sim_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_bicycle_kin_sim_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_bicycle_kin_sim_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_bicycle_kin_sim_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_bicycle_kin_sim_geometry_msgs_Quaternion Orientation;
} SL_Bus_bicycle_kin_sim_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
typedef struct {
  // MsgType=geometry_msgs/Pose
  SL_Bus_bicycle_kin_sim_geometry_msgs_Pose Pose;
  real_T Covariance[36];
} SL_Bus_bicycle_kin_sim_geometry_msgs_PoseWithCovariance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_TwistWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_TwistWithCovariance_

// MsgType=geometry_msgs/TwistWithCovariance
typedef struct {
  // MsgType=geometry_msgs/Twist
  SL_Bus_bicycle_kin_sim_geometry_msgs_Twist Twist;
  real_T Covariance[36];
} SL_Bus_bicycle_kin_sim_geometry_msgs_TwistWithCovariance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_bicycle_kin_sim_std_msgs_Header Header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_bicycle_kin_sim_geometry_msgs_PoseWithCovariance Pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_bicycle_kin_sim_geometry_msgs_TwistWithCovariance Twist;
} SL_Bus_bicycle_kin_sim_nav_msgs_Odometry;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Transform_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_Transform_

// MsgType=geometry_msgs/Transform
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_bicycle_kin_sim_geometry_msgs_Vector3 Translation;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_bicycle_kin_sim_geometry_msgs_Quaternion Rotation;
} SL_Bus_bicycle_kin_sim_geometry_msgs_Transform;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_TransformStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_geometry_msgs_TransformStamped_

// MsgType=geometry_msgs/TransformStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_bicycle_kin_sim_std_msgs_Header Header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=geometry_msgs/Transform
  SL_Bus_bicycle_kin_sim_geometry_msgs_Transform Transform;
} SL_Bus_bicycle_kin_sim_geometry_msgs_TransformStamped;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_tf2_msgs_TFMessage_
#define DEFINED_TYPEDEF_FOR_SL_Bus_bicycle_kin_sim_tf2_msgs_TFMessage_

// MsgType=tf2_msgs/TFMessage
typedef struct {
  // MsgType=geometry_msgs/TransformStamped:IsVarLen=1:VarLenCategory=data:VarLenElem=Transforms_SL_Info:TruncateAction=warn 
  SL_Bus_bicycle_kin_sim_geometry_msgs_TransformStamped Transforms[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Transforms
  SL_Bus_ROSVariableLengthArrayInfo Transforms_SL_Info;
} SL_Bus_bicycle_kin_sim_tf2_msgs_TFMessage;

#endif

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

#ifndef struct_tag_eFCXAaC7vLdwjksE0MwgOD
#define struct_tag_eFCXAaC7vLdwjksE0MwgOD

struct tag_eFCXAaC7vLdwjksE0MwgOD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_eFCXAaC7vLdwjksE0MwgOD

#ifndef typedef_ros_slroscpp_internal_block_S_T
#define typedef_ros_slroscpp_internal_block_S_T

typedef tag_eFCXAaC7vLdwjksE0MwgOD ros_slroscpp_internal_block_S_T;

#endif                                 //typedef_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_bicycle_kin_sim_T_ P_bicycle_kin_sim_T;

// Forward declaration for rtModel
typedef struct tag_RTM_bicycle_kin_sim_T RT_MODEL_bicycle_kin_sim_T;

#endif                                 // RTW_HEADER_bicycle_kin_sim_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
