//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: bicycle_kin_sim_private.h
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
#ifndef RTW_HEADER_bicycle_kin_sim_private_h_
#define RTW_HEADER_bicycle_kin_sim_private_h_
#include "rtwtypes.h"
#include "bicycle_kin_sim.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern void bicycle_kin_sim_MATLABFunction(real_T rtu_time, const
  SL_Bus_bicycle_kin_sim_nav_msgs_Odometry *rtu_blankMsg, const uint8_T
  rtu_frame_id[4], const uint8_T rtu_child_frame_id[9], real_T rtu_x, real_T
  rtu_y, real_T rtu_theta, SL_Bus_bicycle_kin_sim_nav_msgs_Odometry *rty_odomMsg);

// private model entry point functions
extern void bicycle_kin_sim_derivatives(void);

#endif                                 // RTW_HEADER_bicycle_kin_sim_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
