//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: planPublisher_test.h
//
// Code generated for Simulink model 'planPublisher_test'.
//
// Model version                  : 2.20
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Jul 15 19:03:33 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_planPublisher_test_h_
#define RTW_HEADER_planPublisher_test_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "planPublisher_test_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
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

// Block signals (default storage)
typedef struct {
  SL_Bus_planPublisher_test_nav_msgs_Path pathMsg;// '<S2>/MATLAB Function'
  real_T OutportBufferForEnablesignal; // '<S2>/Constant'
} B_planPublisher_test_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Curr_T obj; // '<S2>/Current Time'
  ros_slroscpp_internal_block_P_T obj_d;// '<S5>/SinkBlock'
  real_T Delay_DSTATE;                 // '<S1>/Delay'
  real_T Delay_DSTATE_j;               // '<S2>/Delay'
} DW_planPublisher_test_T;

// Parameters (default storage)
struct P_planPublisher_test_T_ {
  real_T desired_traj[308];            // Variable: desired_traj
                                          //  Referenced by: '<S1>/Desired trajectory'

  SL_Bus_planPublisher_test_nav_msgs_Path Constant_Value;// Computed Parameter: Constant_Value
                                                            //  Referenced by: '<S3>/Constant'

  real_T Constant_Value_f;             // Expression: 0
                                          //  Referenced by: '<S2>/Constant'

  real_T Delay_InitialCondition;       // Expression: 0
                                          //  Referenced by: '<S2>/Delay'

  real_T Delay_InitialCondition_e;     // Expression: 1.0
                                          //  Referenced by: '<S1>/Delay'

  real_T Publishingdelay_Time;         // Expression: 5
                                          //  Referenced by: '<Root>/Publishing delay'

  real_T Publishingdelay_Y0;           // Expression: 0
                                          //  Referenced by: '<Root>/Publishing delay'

  real_T Publishingdelay_YFinal;       // Expression: 1
                                          //  Referenced by: '<Root>/Publishing delay'

  uint8_T frame_id_Value[4];           // Expression: uint8('odom')
                                          //  Referenced by: '<S1>/frame_id'

};

// Real-time Model Data Structure
struct tag_RTM_planPublisher_test_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_planPublisher_test_T planPublisher_test_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_planPublisher_test_T planPublisher_test_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_planPublisher_test_T planPublisher_test_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void planPublisher_test_initialize(void);
  extern void planPublisher_test_step(void);
  extern void planPublisher_test_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_planPublisher_test_T *const planPublisher_test_M;

#ifdef __cplusplus

}
#endif

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
//  '<Root>' : 'planPublisher_test'
//  '<S1>'   : 'planPublisher_test/Single plan message publisher'
//  '<S2>'   : 'planPublisher_test/Single plan message publisher/Path publisher Single execution'
//  '<S3>'   : 'planPublisher_test/Single plan message publisher/Path publisher Single execution/Blank Message'
//  '<S4>'   : 'planPublisher_test/Single plan message publisher/Path publisher Single execution/MATLAB Function'
//  '<S5>'   : 'planPublisher_test/Single plan message publisher/Path publisher Single execution/Publish'

#endif                                 // RTW_HEADER_planPublisher_test_h_

//
// File trailer for generated code.
//
// [EOF]
//
