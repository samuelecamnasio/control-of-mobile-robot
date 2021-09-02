//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: bicycle_kin_planCont.h
//
// Code generated for Simulink model 'bicycle_kin_planCont'.
//
// Model version                  : 2.133
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Jul 15 19:02:02 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_bicycle_kin_planCont_h_
#define RTW_HEADER_bicycle_kin_planCont_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "slros_initialize.h"
#include "bicycle_kin_planCont_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_bicycle_kin_planCont_nav_msgs_Path In1;// '<S19>/In1'
  SL_Bus_bicycle_kin_planCont_nav_msgs_Path b_varargout_2;
  SL_Bus_bicycle_kin_planCont_geometry_msgs_PoseStamped b_varargout_2_Poses[25];
  SL_Bus_bicycle_kin_planCont_nav_msgs_Odometry In1_b;// '<S9>/In1'
  SL_Bus_bicycle_kin_planCont_nav_msgs_Odometry b_varargout_2_m;
  real_T t[25];                        // '<S15>/MATLAB Function'
  real_T x[25];                        // '<S15>/MATLAB Function'
  real_T y[25];                        // '<S15>/MATLAB Function'
  SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped outMsg;// '<S17>/MATLAB Function1' 
  uint8_T b_varargout_2_Header_FrameId[128];
  SL_Bus_bicycle_kin_planCont_geometry_msgs_Twist BusAssignment;// '<S1>/Bus Assignment' 
  real_T CurrentTime;                  // '<S15>/Current Time'
  real_T m;
  real_T xi;
  real_T d_a;
  real_T b_varargout_2_Header_Stamp_Sec;
  real_T history_y;                    // '<S4>/MATLAB Function'
  real_T history_x;                    // '<S4>/MATLAB Function'
  real_T y_obj;                        // '<S4>/MATLAB Function'
  real_T x_obj;                        // '<S4>/MATLAB Function'
  real_T theta;                        // '<S2>/Conversion'
  real_T v_y;                          // '<S4>/MATLAB Function'
  uint32_T num_poses;                  // '<S15>/MATLAB Function'
} B_bicycle_kin_planCont_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Curr_T obj; // '<S15>/Current Time'
  ros_slros_internal_block_Curr_T obj_o;// '<S4>/Current Time'
  ros_slroscpp_internal_block_P_T obj_p;// '<S29>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_p3;// '<S26>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_m;// '<S23>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_n;// '<S6>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S14>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_pt;// '<S8>/SourceBlock'
  real_T UnitDelay1_DSTATE;            // '<S4>/Unit Delay1'
  real_T UnitDelay3_DSTATE;            // '<S4>/Unit Delay3'
  real_T UnitDelay2_DSTATE;            // '<S4>/Unit Delay2'
  real_T UnitDelay4_DSTATE;            // '<S4>/Unit Delay4'
} DW_bicycle_kin_planCont_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;// '<S4>/Triggered Subsystem'
} PrevZCX_bicycle_kin_planCont_T;

// Parameters (default storage)
struct P_bicycle_kin_planCont_T_ {
  real_T Bicyclekinematicfeedbacklineari;
                              // Mask Parameter: Bicyclekinematicfeedbacklineari
                                 //  Referenced by: '<S10>/Centre-Front Distance'

  real_T Proportionalbasedonfeedbackline;
                              // Mask Parameter: Proportionalbasedonfeedbackline
                                 //  Referenced by: '<S3>/point distance'

  real_T Proportionalbasedonfeedbackli_b;
                              // Mask Parameter: Proportionalbasedonfeedbackli_b
                                 //  Referenced by: '<S3>/Constant'

  real_T Trajectoryinterpolator_R;   // Mask Parameter: Trajectoryinterpolator_R
                                        //  Referenced by: '<S4>/Constant2'

  real_T Bicyclekinematicfeedbacklinea_l;
                              // Mask Parameter: Bicyclekinematicfeedbacklinea_l
                                 //  Referenced by: '<S10>/Rear-Centre Distance'

  SL_Bus_bicycle_kin_planCont_nav_msgs_Path Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S19>/Out1'

  SL_Bus_bicycle_kin_planCont_nav_msgs_Path Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S14>/Constant'

  SL_Bus_bicycle_kin_planCont_nav_msgs_Odometry Out1_Y0_l;// Computed Parameter: Out1_Y0_l
                                                             //  Referenced by: '<S9>/Out1'

  SL_Bus_bicycle_kin_planCont_nav_msgs_Odometry Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                                    //  Referenced by: '<S8>/Constant'

  SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                                      //  Referenced by: '<S21>/Constant'

  SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                      //  Referenced by: '<S24>/Constant'

  SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                      //  Referenced by: '<S27>/Constant'

  SL_Bus_bicycle_kin_planCont_geometry_msgs_Twist Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                      //  Referenced by: '<S5>/Constant'

  real_T startTime_Y0;                 // Computed Parameter: startTime_Y0
                                          //  Referenced by: '<S15>/startTime'

  real_T t_Y0;                         // Computed Parameter: t_Y0
                                          //  Referenced by: '<S15>/t'

  real_T x_Y0;                         // Computed Parameter: x_Y0
                                          //  Referenced by: '<S15>/x'

  real_T y_Y0;                         // Computed Parameter: y_Y0
                                          //  Referenced by: '<S15>/y'

  real_T UnitDelay1_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S4>/Unit Delay1'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S4>/Unit Delay'

  real_T UnitDelay3_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S4>/Unit Delay3'

  real_T UnitDelay2_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S4>/Unit Delay2'

  real_T UnitDelay4_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S4>/Unit Delay4'

  real_T Constant_Value_b;             // Expression: 0
                                          //  Referenced by: '<S10>/Constant'

  uint32_T numPoses_Y0;                // Computed Parameter: numPoses_Y0
                                          //  Referenced by: '<S15>/numPoses'

  uint8_T frame_id_Value[4];           // Expression: uint8('odom')
                                          //  Referenced by: '<S16>/frame_id'

  uint8_T frame_id_Value_m[4];         // Expression: uint8('odom')
                                          //  Referenced by: '<S17>/frame_id'

  uint8_T frame_id_Value_d[4];         // Expression: uint8('odom')
                                          //  Referenced by: '<S18>/frame_id'

};

// Real-time Model Data Structure
struct tag_RTM_bicycle_kin_planCont_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_bicycle_kin_planCont_T bicycle_kin_planCont_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_bicycle_kin_planCont_T bicycle_kin_planCont_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_bicycle_kin_planCont_T bicycle_kin_planCont_DW;

// Zero-crossing (trigger) state
extern PrevZCX_bicycle_kin_planCont_T bicycle_kin_planCont_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void bicycle_kin_planCont_initialize(void);
  extern void bicycle_kin_planCont_step(void);
  extern void bicycle_kin_planCont_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_bicycle_kin_planCont_T *const bicycle_kin_planCont_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/vx' : Unused code path elimination
//  Block '<Root>/vx1' : Unused code path elimination
//  Block '<Root>/vx2' : Unused code path elimination
//  Block '<Root>/vy' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'bicycle_kin_planCont'
//  '<S1>'   : 'bicycle_kin_planCont/Command publisher'
//  '<S2>'   : 'bicycle_kin_planCont/Pose subscriber'
//  '<S3>'   : 'bicycle_kin_planCont/Proportional based on feedback linearization'
//  '<S4>'   : 'bicycle_kin_planCont/Trajectory interpolator'
//  '<S5>'   : 'bicycle_kin_planCont/Command publisher/Blank Message'
//  '<S6>'   : 'bicycle_kin_planCont/Command publisher/Publish'
//  '<S7>'   : 'bicycle_kin_planCont/Pose subscriber/Conversion'
//  '<S8>'   : 'bicycle_kin_planCont/Pose subscriber/Subscribe'
//  '<S9>'   : 'bicycle_kin_planCont/Pose subscriber/Subscribe/Enabled Subsystem'
//  '<S10>'  : 'bicycle_kin_planCont/Proportional based on feedback linearization/Bicycle kinematic feedback linearization'
//  '<S11>'  : 'bicycle_kin_planCont/Proportional based on feedback linearization/Proportional + velocity feed forward'
//  '<S12>'  : 'bicycle_kin_planCont/Proportional based on feedback linearization/Bicycle kinematic feedback linearization/Bicycle kinematic feedback linearization'
//  '<S13>'  : 'bicycle_kin_planCont/Trajectory interpolator/MATLAB Function'
//  '<S14>'  : 'bicycle_kin_planCont/Trajectory interpolator/Subscribe'
//  '<S15>'  : 'bicycle_kin_planCont/Trajectory interpolator/Triggered Subsystem'
//  '<S16>'  : 'bicycle_kin_planCont/Trajectory interpolator/history objective publisher'
//  '<S17>'  : 'bicycle_kin_planCont/Trajectory interpolator/step interpolated objective publisher'
//  '<S18>'  : 'bicycle_kin_planCont/Trajectory interpolator/step objective publisher'
//  '<S19>'  : 'bicycle_kin_planCont/Trajectory interpolator/Subscribe/Enabled Subsystem'
//  '<S20>'  : 'bicycle_kin_planCont/Trajectory interpolator/Triggered Subsystem/MATLAB Function'
//  '<S21>'  : 'bicycle_kin_planCont/Trajectory interpolator/history objective publisher/Blank Message'
//  '<S22>'  : 'bicycle_kin_planCont/Trajectory interpolator/history objective publisher/MATLAB Function1'
//  '<S23>'  : 'bicycle_kin_planCont/Trajectory interpolator/history objective publisher/Publish'
//  '<S24>'  : 'bicycle_kin_planCont/Trajectory interpolator/step interpolated objective publisher/Blank Message'
//  '<S25>'  : 'bicycle_kin_planCont/Trajectory interpolator/step interpolated objective publisher/MATLAB Function1'
//  '<S26>'  : 'bicycle_kin_planCont/Trajectory interpolator/step interpolated objective publisher/Publish'
//  '<S27>'  : 'bicycle_kin_planCont/Trajectory interpolator/step objective publisher/Blank Message'
//  '<S28>'  : 'bicycle_kin_planCont/Trajectory interpolator/step objective publisher/MATLAB Function1'
//  '<S29>'  : 'bicycle_kin_planCont/Trajectory interpolator/step objective publisher/Publish'

#endif                                 // RTW_HEADER_bicycle_kin_planCont_h_

//
// File trailer for generated code.
//
// [EOF]
//
