//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: bicycle_kin_planCont_private.h
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
#ifndef RTW_HEADER_bicycle_kin_planCont_private_h_
#define RTW_HEADER_bicycle_kin_planCont_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "bicycle_kin_planCont.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void bicycle_kin_pla_MATLABFunction1(const
  SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped *rtu_blankMsg, real_T
  rtu_time, const uint8_T rtu_frame_id[4], real_T rtu_x, real_T rtu_y,
  SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped *rty_outMsg);

#endif                            // RTW_HEADER_bicycle_kin_planCont_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
