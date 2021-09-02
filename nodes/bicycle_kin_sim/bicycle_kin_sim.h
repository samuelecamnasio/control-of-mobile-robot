//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: bicycle_kin_sim.h
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
#ifndef RTW_HEADER_bicycle_kin_sim_h_
#define RTW_HEADER_bicycle_kin_sim_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "bicycle_kin_sim_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_bicycle_kin_sim_tf2_msgs_TFMessage tf2Msg;// '<S4>/MATLAB Function1'
  SL_Bus_bicycle_kin_sim_nav_msgs_Odometry rtb_odomMsg_m;
  SL_Bus_bicycle_kin_sim_geometry_msgs_Twist In1;// '<S10>/In1'
  SL_Bus_bicycle_kin_sim_geometry_msgs_Twist b_varargout_2;
  real_T State[3];                     // '<S1>/State'
  real_T dstate[3];                    // '<S1>/Bicycle kinematics'
  SL_Bus_bicycle_kin_sim_rosgraph_msgs_Clock timeMsg;// '<S2>/MATLAB Function'
} B_bicycle_kin_sim_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slroscpp_internal_block_P_T obj; // '<S18>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_k;// '<S17>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_l;// '<S16>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_e;// '<S8>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_j;// '<S9>/SourceBlock'
  real_T Delay1_DSTATE;                // '<S1>/Delay1'
  real_T Delay_DSTATE;                 // '<S1>/Delay'
  real_T UnitDelay_DSTATE;             // '<S2>/Unit Delay'
} DW_bicycle_kin_sim_T;

// Continuous states (default storage)
typedef struct {
  real_T State_CSTATE[3];              // '<S1>/State'
} X_bicycle_kin_sim_T;

// State derivatives (default storage)
typedef struct {
  real_T State_CSTATE[3];              // '<S1>/State'
} XDot_bicycle_kin_sim_T;

// State disabled
typedef struct {
  boolean_T State_CSTATE[3];           // '<S1>/State'
} XDis_bicycle_kin_sim_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (default storage)
struct P_bicycle_kin_sim_T_ {
  real_T Bicyclekinematicmodel_CFD; // Mask Parameter: Bicyclekinematicmodel_CFD
                                       //  Referenced by: '<S1>/Centre-Front Distance'

  real_T Bicyclekinematicmodel_RCD; // Mask Parameter: Bicyclekinematicmodel_RCD
                                       //  Referenced by: '<S1>/Rear-Centre Distance'

  real_T Bicyclekinematicmodel_state0[3];
                                 // Mask Parameter: Bicyclekinematicmodel_state0
                                    //  Referenced by: '<S1>/State'

  SL_Bus_bicycle_kin_sim_tf2_msgs_TFMessage Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S12>/Constant'

  SL_Bus_bicycle_kin_sim_nav_msgs_Odometry Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                               //  Referenced by: '<S11>/Constant'

  SL_Bus_bicycle_kin_sim_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                        //  Referenced by: '<S10>/Out1'

  SL_Bus_bicycle_kin_sim_geometry_msgs_Twist Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                 //  Referenced by: '<S9>/Constant'

  SL_Bus_bicycle_kin_sim_rosgraph_msgs_Clock Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                                 //  Referenced by: '<S6>/Constant'

  real_T Delay1_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S1>/Delay1'

  real_T Delay_InitialCondition;       // Expression: 0
                                          //  Referenced by: '<S1>/Delay'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S2>/Unit Delay'

  uint8_T frame_id2_Value[9];          // Expression: uint8('base_link')
                                          //  Referenced by: '<S4>/frame_id2'

  uint8_T frame_id_Value[4];           // Expression: uint8('odom')
                                          //  Referenced by: '<S4>/frame_id'

};

// Real-time Model Data Structure
struct tag_RTM_bicycle_kin_sim_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_bicycle_kin_sim_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_bicycle_kin_sim_T bicycle_kin_sim_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_bicycle_kin_sim_T bicycle_kin_sim_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_bicycle_kin_sim_T bicycle_kin_sim_X;

// Block states (default storage)
extern DW_bicycle_kin_sim_T bicycle_kin_sim_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void bicycle_kin_sim_initialize(void);
  extern void bicycle_kin_sim_step(void);
  extern void bicycle_kin_sim_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_bicycle_kin_sim_T *const bicycle_kin_sim_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Reshape' : Reshape block reduction
//  Block '<S1>/Reshape1' : Reshape block reduction
//  Block '<S1>/Reshape2' : Reshape block reduction


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
//  '<Root>' : 'bicycle_kin_sim'
//  '<S1>'   : 'bicycle_kin_sim/Bicycle kinematic model'
//  '<S2>'   : 'bicycle_kin_sim/Time publisher'
//  '<S3>'   : 'bicycle_kin_sim/cmd_vel subscriber'
//  '<S4>'   : 'bicycle_kin_sim/odom and tf publishers'
//  '<S5>'   : 'bicycle_kin_sim/Bicycle kinematic model/Bicycle kinematics'
//  '<S6>'   : 'bicycle_kin_sim/Time publisher/Blank Message'
//  '<S7>'   : 'bicycle_kin_sim/Time publisher/MATLAB Function'
//  '<S8>'   : 'bicycle_kin_sim/Time publisher/Publish'
//  '<S9>'   : 'bicycle_kin_sim/cmd_vel subscriber/Subscribe'
//  '<S10>'  : 'bicycle_kin_sim/cmd_vel subscriber/Subscribe/Enabled Subsystem'
//  '<S11>'  : 'bicycle_kin_sim/odom and tf publishers/Blank Message'
//  '<S12>'  : 'bicycle_kin_sim/odom and tf publishers/Blank Message1'
//  '<S13>'  : 'bicycle_kin_sim/odom and tf publishers/MATLAB Function'
//  '<S14>'  : 'bicycle_kin_sim/odom and tf publishers/MATLAB Function1'
//  '<S15>'  : 'bicycle_kin_sim/odom and tf publishers/MATLAB Function2'
//  '<S16>'  : 'bicycle_kin_sim/odom and tf publishers/Publish'
//  '<S17>'  : 'bicycle_kin_sim/odom and tf publishers/Publish1'
//  '<S18>'  : 'bicycle_kin_sim/odom and tf publishers/Publish2'

#endif                                 // RTW_HEADER_bicycle_kin_sim_h_

//
// File trailer for generated code.
//
// [EOF]
//
