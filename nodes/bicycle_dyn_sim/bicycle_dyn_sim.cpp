//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: bicycle_dyn_sim.cpp
//
// Code generated for Simulink model 'bicycle_dyn_sim'.
//
// Model version                  : 2.25
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Jul 15 19:21:50 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "bicycle_dyn_sim.h"
#include "bicycle_dyn_sim_private.h"

// Block signals (default storage)
B_bicycle_dyn_sim_T bicycle_dyn_sim_B;

// Continuous states
X_bicycle_dyn_sim_T bicycle_dyn_sim_X;

// Block states (default storage)
DW_bicycle_dyn_sim_T bicycle_dyn_sim_DW;

// Real-time model
RT_MODEL_bicycle_dyn_sim_T bicycle_dyn_sim_M_ = RT_MODEL_bicycle_dyn_sim_T();
RT_MODEL_bicycle_dyn_sim_T *const bicycle_dyn_sim_M = &bicycle_dyn_sim_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  bicycle_dyn_sim_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  bicycle_dyn_sim_step();
  bicycle_dyn_sim_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  bicycle_dyn_sim_step();
  bicycle_dyn_sim_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Model step function
void bicycle_dyn_sim_step(void)
{
  SL_Bus_bicycle_dyn_sim_rosgraph_msgs_Clock rtb_timeMsg;
  real_T Fyr;
  real_T Fz;
  real_T alpha_f;
  real_T alpha_r;
  real_T rtb_DigitalClock;
  int32_T i;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(bicycle_dyn_sim_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&bicycle_dyn_sim_M->solverInfo,
                          ((bicycle_dyn_sim_M->Timing.clockTick0+1)*
      bicycle_dyn_sim_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(bicycle_dyn_sim_M)) {
    bicycle_dyn_sim_M->Timing.t[0] = rtsiGetT(&bicycle_dyn_sim_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(bicycle_dyn_sim_M)) {
    // Outputs for Atomic SubSystem: '<S3>/Subscribe'
    // MATLABSystem: '<S9>/SourceBlock' incorporates:
    //   Inport: '<S10>/In1'

    b_varargout_1 = Sub_bicycle_dyn_sim_17.getLatestMessage
      (&bicycle_dyn_sim_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    if (b_varargout_1) {
      bicycle_dyn_sim_B.In1 = bicycle_dyn_sim_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S9>/SourceBlock'
    // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/Subscribe'

    // MATLAB Function: '<S1>/Bicycle dynamics' incorporates:
    //   Constant: '<S1>/Centre-Front Distance'
    //   Constant: '<S1>/Cornering stiffness front'
    //   Constant: '<S1>/Cornering stiffness rear'
    //   Constant: '<S1>/Inertia'
    //   Constant: '<S1>/Linear Model'
    //   Constant: '<S1>/Rear-Centre Distance'
    //   Constant: '<S1>/Vehicle mass'
    //   Constant: '<S1>/friction coefficent'
    //   Delay: '<S1>/Delay1'
    //   Delay: '<S1>/Delay2'
    //   Delay: '<S1>/Delay3'

    if (bicycle_dyn_sim_B.In1.Linear.X == 0.0) {
      alpha_f = 0.0;
      alpha_r = 0.0;
    } else {
      alpha_f = (bicycle_dyn_sim_P.Bicycledynamicmodel_CFD *
                 bicycle_dyn_sim_DW.Delay3_DSTATE /
                 bicycle_dyn_sim_B.In1.Linear.X +
                 bicycle_dyn_sim_DW.Delay1_DSTATE) -
        bicycle_dyn_sim_B.In1.Angular.Z;
      alpha_r = bicycle_dyn_sim_DW.Delay1_DSTATE -
        bicycle_dyn_sim_P.Bicycledynamicmodel_RCD *
        bicycle_dyn_sim_DW.Delay3_DSTATE / bicycle_dyn_sim_B.In1.Linear.X;
    }

    Fz = bicycle_dyn_sim_P.Bicycledynamicmodel_m * 9.806 / 2.0;
    if (bicycle_dyn_sim_P.Bicycledynamicmodel_Linear == 0.0) {
      if (bicycle_dyn_sim_B.In1.Linear.X == 0.0) {
        bicycle_dyn_sim_B.first_der[2] = 0.0;
      } else {
        bicycle_dyn_sim_B.first_der[2] =
          ((-bicycle_dyn_sim_P.Bicycledynamicmodel_C_f * tan(alpha_f) * cos
            (bicycle_dyn_sim_B.In1.Angular.Z) -
            bicycle_dyn_sim_P.Bicycledynamicmodel_C_r * tan(alpha_r)) -
           bicycle_dyn_sim_P.Bicycledynamicmodel_m *
           bicycle_dyn_sim_DW.Delay3_DSTATE * bicycle_dyn_sim_B.In1.Linear.X) *
          (1.0 / (bicycle_dyn_sim_P.Bicycledynamicmodel_m *
                  bicycle_dyn_sim_B.In1.Linear.X));
      }

      bicycle_dyn_sim_B.dpsi_2 = (-bicycle_dyn_sim_P.Bicycledynamicmodel_CFD *
        bicycle_dyn_sim_P.Bicycledynamicmodel_C_f * tan(alpha_f) * cos
        (bicycle_dyn_sim_B.In1.Angular.Z) +
        bicycle_dyn_sim_P.Bicycledynamicmodel_RCD *
        bicycle_dyn_sim_P.Bicycledynamicmodel_C_r * tan(alpha_r)) * (1.0 /
        bicycle_dyn_sim_P.Bicycledynamicmodel_I_z);
    } else {
      Fyr = 3.0 * bicycle_dyn_sim_P.Bicycledynamicmodel_u * Fz;
      if (fabs(alpha_f) < atan(Fyr / bicycle_dyn_sim_P.Bicycledynamicmodel_C_f))
      {
        alpha_f = tan(alpha_f);
        rtb_DigitalClock = bicycle_dyn_sim_P.Bicycledynamicmodel_C_f *
          bicycle_dyn_sim_P.Bicycledynamicmodel_C_f;
        alpha_f = (rtb_DigitalClock / Fyr * fabs(alpha_f) * alpha_f +
                   -bicycle_dyn_sim_P.Bicycledynamicmodel_C_f * alpha_f) -
          rtb_DigitalClock * bicycle_dyn_sim_P.Bicycledynamicmodel_C_f / (27.0 *
          bicycle_dyn_sim_P.Bicycledynamicmodel_u * Fz *
          bicycle_dyn_sim_P.Bicycledynamicmodel_u * Fz) * (alpha_f * alpha_f *
          alpha_f);
      } else {
        if (alpha_f < 0.0) {
          alpha_f = -1.0;
        } else if (alpha_f > 0.0) {
          alpha_f = 1.0;
        } else if (alpha_f == 0.0) {
          alpha_f = 0.0;
        } else {
          alpha_f = (rtNaN);
        }

        alpha_f *= -bicycle_dyn_sim_P.Bicycledynamicmodel_u * Fz;
      }

      if (fabs(alpha_r) < atan(Fyr / bicycle_dyn_sim_P.Bicycledynamicmodel_C_r))
      {
        alpha_r = tan(alpha_r);
        rtb_DigitalClock = bicycle_dyn_sim_P.Bicycledynamicmodel_C_r *
          bicycle_dyn_sim_P.Bicycledynamicmodel_C_r;
        Fyr = (rtb_DigitalClock / Fyr * fabs(alpha_r) * alpha_r +
               -bicycle_dyn_sim_P.Bicycledynamicmodel_C_r * alpha_r) -
          rtb_DigitalClock * bicycle_dyn_sim_P.Bicycledynamicmodel_C_r / (27.0 *
          bicycle_dyn_sim_P.Bicycledynamicmodel_u * Fz *
          bicycle_dyn_sim_P.Bicycledynamicmodel_u * Fz) * (alpha_r * alpha_r *
          alpha_r);
      } else {
        if (alpha_r < 0.0) {
          alpha_r = -1.0;
        } else if (alpha_r > 0.0) {
          alpha_r = 1.0;
        } else if (alpha_r == 0.0) {
          alpha_r = 0.0;
        } else {
          alpha_r = (rtNaN);
        }

        Fyr = -bicycle_dyn_sim_P.Bicycledynamicmodel_u * Fz * alpha_r;
      }

      Fz = cos(bicycle_dyn_sim_B.In1.Angular.Z);
      bicycle_dyn_sim_B.dpsi_2 = (bicycle_dyn_sim_P.Bicycledynamicmodel_CFD *
        alpha_f * Fz - bicycle_dyn_sim_P.Bicycledynamicmodel_RCD * Fyr) * (1.0 /
        bicycle_dyn_sim_P.Bicycledynamicmodel_I_z);
      if (bicycle_dyn_sim_B.In1.Linear.X == 0.0) {
        bicycle_dyn_sim_B.first_der[2] = 0.0;
      } else {
        bicycle_dyn_sim_B.first_der[2] = ((alpha_f * Fz + Fyr) -
          bicycle_dyn_sim_P.Bicycledynamicmodel_m *
          bicycle_dyn_sim_DW.Delay3_DSTATE * bicycle_dyn_sim_B.In1.Linear.X) *
          (1.0 / (bicycle_dyn_sim_P.Bicycledynamicmodel_m *
                  bicycle_dyn_sim_B.In1.Linear.X));
      }
    }

    Fyr = bicycle_dyn_sim_DW.Delay1_DSTATE + bicycle_dyn_sim_DW.Delay2_DSTATE;
    bicycle_dyn_sim_B.first_der[0] = cos(Fyr) * bicycle_dyn_sim_B.In1.Linear.X;
    bicycle_dyn_sim_B.first_der[1] = sin(Fyr) * bicycle_dyn_sim_B.In1.Linear.X;

    // End of MATLAB Function: '<S1>/Bicycle dynamics'

    // DigitalClock: '<S4>/Digital Clock'
    rtb_DigitalClock = ((bicycle_dyn_sim_M->Timing.clockTick1) * 0.01);
  }

  // Integrator: '<S1>/Integrator3'
  bicycle_dyn_sim_B.Integrator3[0] = bicycle_dyn_sim_X.Integrator3_CSTATE[0];
  bicycle_dyn_sim_B.Integrator3[1] = bicycle_dyn_sim_X.Integrator3_CSTATE[1];
  bicycle_dyn_sim_B.Integrator3[2] = bicycle_dyn_sim_X.Integrator3_CSTATE[2];

  // Integrator: '<S1>/Integrator2'
  bicycle_dyn_sim_B.Integrator2 = bicycle_dyn_sim_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(bicycle_dyn_sim_M)) {
    // MATLAB Function: '<S4>/MATLAB Function' incorporates:
    //   Constant: '<S11>/Constant'
    //   Constant: '<S4>/frame_id'
    //   Constant: '<S4>/frame_id2'
    //   MATLAB Function: '<S4>/MATLAB Function1'

    bicycle_dyn_sim_B.odomMsg_b = bicycle_dyn_sim_P.Constant_Value_m;
    if (rtb_DigitalClock < 0.0) {
      // MATLAB Function: '<S4>/MATLAB Function2'
      Fyr = ceil(rtb_DigitalClock);
    } else {
      // MATLAB Function: '<S4>/MATLAB Function2'
      Fyr = floor(rtb_DigitalClock);
    }

    bicycle_dyn_sim_B.odomMsg_b.Header.Stamp.Sec = Fyr;
    rtb_DigitalClock = (rtb_DigitalClock - Fyr) * 1.0E+9;
    if (rtb_DigitalClock < 0.0) {
      // MATLAB Function: '<S4>/MATLAB Function2'
      Fz = ceil(rtb_DigitalClock);
    } else {
      // MATLAB Function: '<S4>/MATLAB Function2'
      Fz = floor(rtb_DigitalClock);
    }

    bicycle_dyn_sim_B.odomMsg_b.Header.Stamp.Nsec = Fz;
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId[0] =
      bicycle_dyn_sim_P.frame_id_Value[0];
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId[1] =
      bicycle_dyn_sim_P.frame_id_Value[1];
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId[2] =
      bicycle_dyn_sim_P.frame_id_Value[2];
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId[3] =
      bicycle_dyn_sim_P.frame_id_Value[3];
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId_SL_Info.CurrentLength = 4U;
    for (i = 0; i < 9; i++) {
      bicycle_dyn_sim_B.odomMsg_b.ChildFrameId[i] =
        bicycle_dyn_sim_P.frame_id2_Value[i];
    }

    bicycle_dyn_sim_B.odomMsg_b.ChildFrameId_SL_Info.CurrentLength = 9U;
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Position.X =
      bicycle_dyn_sim_B.Integrator3[0];
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Position.Y =
      bicycle_dyn_sim_B.Integrator3[1];
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Position.Z = 0.0;
    alpha_f = bicycle_dyn_sim_B.Integrator2 / 2.0;
    rtb_DigitalClock = cos(alpha_f);
    alpha_r = sin(alpha_f);
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Orientation.X = 0.0 * alpha_r +
      rtb_DigitalClock;
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Orientation.Y = alpha_r - 0.0 *
      rtb_DigitalClock;
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Orientation.Z = 0.0 * rtb_DigitalClock
      + 0.0 * alpha_r;
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Orientation.W = 0.0 * rtb_DigitalClock
      - 0.0 * alpha_r;

    // End of MATLAB Function: '<S4>/MATLAB Function'

    // Outputs for Atomic SubSystem: '<S4>/Publish'
    // MATLABSystem: '<S16>/SinkBlock'
    Pub_bicycle_dyn_sim_126.publish(&bicycle_dyn_sim_B.odomMsg_b);

    // End of Outputs for SubSystem: '<S4>/Publish'

    // MATLAB Function: '<S4>/MATLAB Function1' incorporates:
    //   Constant: '<S12>/Constant'
    //   Constant: '<S4>/frame_id'
    //   Constant: '<S4>/frame_id2'

    bicycle_dyn_sim_B.tf2Msg = bicycle_dyn_sim_P.Constant_Value;
    bicycle_dyn_sim_B.tf2Msg.Transforms_SL_Info.CurrentLength = 1U;
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Header.Stamp.Sec = Fyr;
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Header.Stamp.Nsec = Fz;
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Header.FrameId[0] =
      bicycle_dyn_sim_P.frame_id_Value[0];
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Header.FrameId[1] =
      bicycle_dyn_sim_P.frame_id_Value[1];
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Header.FrameId[2] =
      bicycle_dyn_sim_P.frame_id_Value[2];
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Header.FrameId[3] =
      bicycle_dyn_sim_P.frame_id_Value[3];
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Header.FrameId_SL_Info.CurrentLength =
      4U;
    for (i = 0; i < 9; i++) {
      bicycle_dyn_sim_B.tf2Msg.Transforms[0].ChildFrameId[i] =
        bicycle_dyn_sim_P.frame_id2_Value[i];
    }

    bicycle_dyn_sim_B.tf2Msg.Transforms[0].ChildFrameId_SL_Info.CurrentLength =
      9U;
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Transform.Translation.X =
      bicycle_dyn_sim_B.Integrator3[0];
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Transform.Translation.Y =
      bicycle_dyn_sim_B.Integrator3[1];
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Transform.Translation.Z = 0.0;
    rtb_DigitalClock = cos(alpha_f);
    alpha_r = sin(alpha_f);
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Transform.Rotation.X = 0.0 * alpha_r
      + rtb_DigitalClock;
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Transform.Rotation.Y = alpha_r - 0.0 *
      rtb_DigitalClock;
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Transform.Rotation.Z = 0.0 *
      rtb_DigitalClock + 0.0 * alpha_r;
    bicycle_dyn_sim_B.tf2Msg.Transforms[0].Transform.Rotation.W = 0.0 *
      rtb_DigitalClock - 0.0 * alpha_r;

    // Outputs for Atomic SubSystem: '<S4>/Publish1'
    // MATLABSystem: '<S17>/SinkBlock'
    Pub_bicycle_dyn_sim_127.publish(&bicycle_dyn_sim_B.tf2Msg);

    // End of Outputs for SubSystem: '<S4>/Publish1'

    // MATLAB Function: '<S4>/MATLAB Function2' incorporates:
    //   Constant: '<S11>/Constant'
    //   Constant: '<S4>/frame_id'
    //   Constant: '<S4>/frame_id2'
    //   Sum: '<S1>/Sum'

    bicycle_dyn_sim_B.odomMsg_b = bicycle_dyn_sim_P.Constant_Value_m;
    bicycle_dyn_sim_B.odomMsg_b.Header.Stamp.Sec = Fyr;
    bicycle_dyn_sim_B.odomMsg_b.Header.Stamp.Nsec = Fz;
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId[0] =
      bicycle_dyn_sim_P.frame_id_Value[0];
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId[1] =
      bicycle_dyn_sim_P.frame_id_Value[1];
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId[2] =
      bicycle_dyn_sim_P.frame_id_Value[2];
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId[3] =
      bicycle_dyn_sim_P.frame_id_Value[3];
    bicycle_dyn_sim_B.odomMsg_b.Header.FrameId_SL_Info.CurrentLength = 4U;
    for (i = 0; i < 9; i++) {
      bicycle_dyn_sim_B.odomMsg_b.ChildFrameId[i] =
        bicycle_dyn_sim_P.frame_id2_Value[i];
    }

    bicycle_dyn_sim_B.odomMsg_b.ChildFrameId_SL_Info.CurrentLength = 9U;
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Position.X =
      bicycle_dyn_sim_B.Integrator3[0];
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Position.Y =
      bicycle_dyn_sim_B.Integrator3[1];
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Position.Z = 0.0;
    Fyr = (bicycle_dyn_sim_B.Integrator3[2] + bicycle_dyn_sim_B.Integrator2) /
      2.0;
    rtb_DigitalClock = cos(Fyr);
    alpha_r = sin(Fyr);
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Orientation.X = 0.0 * alpha_r +
      rtb_DigitalClock;
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Orientation.Y = alpha_r - 0.0 *
      rtb_DigitalClock;
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Orientation.Z = 0.0 * rtb_DigitalClock
      + 0.0 * alpha_r;
    bicycle_dyn_sim_B.odomMsg_b.Pose.Pose.Orientation.W = 0.0 * rtb_DigitalClock
      - 0.0 * alpha_r;

    // Outputs for Atomic SubSystem: '<S4>/Publish2'
    // MATLABSystem: '<S18>/SinkBlock'
    Pub_bicycle_dyn_sim_128.publish(&bicycle_dyn_sim_B.odomMsg_b);

    // End of Outputs for SubSystem: '<S4>/Publish2'
  }

  // Integrator: '<S1>/Integrator1'
  bicycle_dyn_sim_B.Integrator1 = bicycle_dyn_sim_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(bicycle_dyn_sim_M)) {
    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   UnitDelay: '<S2>/Unit Delay'

    Fyr = bicycle_dyn_sim_DW.UnitDelay_DSTATE * 100000.0;
    rtb_timeMsg.Clock_.Sec = rt_roundd_snf(Fyr * 1.0E-9);
    rtb_timeMsg.Clock_.Nsec = rt_roundd_snf(Fyr - rt_roundd_snf(Fyr));
    bicycle_dyn_sim_DW.UnitDelay_DSTATE++;

    // Outputs for Atomic SubSystem: '<S2>/Publish'
    // MATLABSystem: '<S8>/SinkBlock'
    Pub_bicycle_dyn_sim_134.publish(&rtb_timeMsg);

    // End of Outputs for SubSystem: '<S2>/Publish'
  }

  if (rtmIsMajorTimeStep(bicycle_dyn_sim_M)) {
    if (rtmIsMajorTimeStep(bicycle_dyn_sim_M)) {
      // Update for Delay: '<S1>/Delay1'
      bicycle_dyn_sim_DW.Delay1_DSTATE = bicycle_dyn_sim_B.Integrator3[2];

      // Update for Delay: '<S1>/Delay2'
      bicycle_dyn_sim_DW.Delay2_DSTATE = bicycle_dyn_sim_B.Integrator2;

      // Update for Delay: '<S1>/Delay3'
      bicycle_dyn_sim_DW.Delay3_DSTATE = bicycle_dyn_sim_B.Integrator1;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(bicycle_dyn_sim_M)) {
    rt_ertODEUpdateContinuousStates(&bicycle_dyn_sim_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++bicycle_dyn_sim_M->Timing.clockTick0;
    bicycle_dyn_sim_M->Timing.t[0] = rtsiGetSolverStopTime
      (&bicycle_dyn_sim_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.01s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.01, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      bicycle_dyn_sim_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void bicycle_dyn_sim_derivatives(void)
{
  XDot_bicycle_dyn_sim_T *_rtXdot;
  _rtXdot = ((XDot_bicycle_dyn_sim_T *) bicycle_dyn_sim_M->derivs);

  // Derivatives for Integrator: '<S1>/Integrator3'
  _rtXdot->Integrator3_CSTATE[0] = bicycle_dyn_sim_B.first_der[0];
  _rtXdot->Integrator3_CSTATE[1] = bicycle_dyn_sim_B.first_der[1];
  _rtXdot->Integrator3_CSTATE[2] = bicycle_dyn_sim_B.first_der[2];

  // Derivatives for Integrator: '<S1>/Integrator2'
  _rtXdot->Integrator2_CSTATE = bicycle_dyn_sim_B.Integrator1;

  // Derivatives for Integrator: '<S1>/Integrator1'
  _rtXdot->Integrator1_CSTATE = bicycle_dyn_sim_B.dpsi_2;
}

// Model initialize function
void bicycle_dyn_sim_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&bicycle_dyn_sim_M->solverInfo,
                          &bicycle_dyn_sim_M->Timing.simTimeStep);
    rtsiSetTPtr(&bicycle_dyn_sim_M->solverInfo, &rtmGetTPtr(bicycle_dyn_sim_M));
    rtsiSetStepSizePtr(&bicycle_dyn_sim_M->solverInfo,
                       &bicycle_dyn_sim_M->Timing.stepSize0);
    rtsiSetdXPtr(&bicycle_dyn_sim_M->solverInfo, &bicycle_dyn_sim_M->derivs);
    rtsiSetContStatesPtr(&bicycle_dyn_sim_M->solverInfo, (real_T **)
                         &bicycle_dyn_sim_M->contStates);
    rtsiSetNumContStatesPtr(&bicycle_dyn_sim_M->solverInfo,
      &bicycle_dyn_sim_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&bicycle_dyn_sim_M->solverInfo,
      &bicycle_dyn_sim_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&bicycle_dyn_sim_M->solverInfo,
      &bicycle_dyn_sim_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&bicycle_dyn_sim_M->solverInfo,
      &bicycle_dyn_sim_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&bicycle_dyn_sim_M->solverInfo, (&rtmGetErrorStatus
      (bicycle_dyn_sim_M)));
    rtsiSetRTModelPtr(&bicycle_dyn_sim_M->solverInfo, bicycle_dyn_sim_M);
  }

  rtsiSetSimTimeStep(&bicycle_dyn_sim_M->solverInfo, MAJOR_TIME_STEP);
  bicycle_dyn_sim_M->intgData.y = bicycle_dyn_sim_M->odeY;
  bicycle_dyn_sim_M->intgData.f[0] = bicycle_dyn_sim_M->odeF[0];
  bicycle_dyn_sim_M->intgData.f[1] = bicycle_dyn_sim_M->odeF[1];
  bicycle_dyn_sim_M->intgData.f[2] = bicycle_dyn_sim_M->odeF[2];
  bicycle_dyn_sim_M->contStates = ((X_bicycle_dyn_sim_T *) &bicycle_dyn_sim_X);
  rtsiSetSolverData(&bicycle_dyn_sim_M->solverInfo, static_cast<void *>
                    (&bicycle_dyn_sim_M->intgData));
  rtsiSetSolverName(&bicycle_dyn_sim_M->solverInfo,"ode3");
  rtmSetTPtr(bicycle_dyn_sim_M, &bicycle_dyn_sim_M->Timing.tArray[0]);
  bicycle_dyn_sim_M->Timing.stepSize0 = 0.01;

  {
    static const char_T tmp_1[13] = { '/', 'o', 'd', 'o', 'm', '_', 'c', 'h',
      'a', 's', 's', 'i', 's' };

    static const char_T tmp[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_2[6] = { '/', 'c', 'l', 'o', 'c', 'k' };

    static const char_T tmp_0[5] = { '/', 'o', 'd', 'o', 'm' };

    int32_T i;
    char_T b_zeroDelimTopic_2[14];
    char_T b_zeroDelimTopic[9];
    char_T b_zeroDelimTopic_3[7];
    char_T b_zeroDelimTopic_0[6];
    char_T b_zeroDelimTopic_1[4];

    // InitializeConditions for Delay: '<S1>/Delay1'
    bicycle_dyn_sim_DW.Delay1_DSTATE = bicycle_dyn_sim_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay2'
    bicycle_dyn_sim_DW.Delay2_DSTATE = bicycle_dyn_sim_P.Delay2_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay3'
    bicycle_dyn_sim_DW.Delay3_DSTATE = bicycle_dyn_sim_P.Delay3_InitialCondition;

    // InitializeConditions for Integrator: '<S1>/Integrator3'
    bicycle_dyn_sim_X.Integrator3_CSTATE[0] =
      bicycle_dyn_sim_P.Bicycledynamicmodel_state0[0];
    bicycle_dyn_sim_X.Integrator3_CSTATE[1] =
      bicycle_dyn_sim_P.Bicycledynamicmodel_state0[1];
    bicycle_dyn_sim_X.Integrator3_CSTATE[2] =
      bicycle_dyn_sim_P.Bicycledynamicmodel_state0[2];

    // InitializeConditions for Integrator: '<S1>/Integrator2'
    bicycle_dyn_sim_X.Integrator2_CSTATE =
      bicycle_dyn_sim_P.Bicycledynamicmodel_state1;

    // InitializeConditions for Integrator: '<S1>/Integrator1'
    bicycle_dyn_sim_X.Integrator1_CSTATE = bicycle_dyn_sim_P.Integrator1_IC;

    // InitializeConditions for UnitDelay: '<S2>/Unit Delay'
    bicycle_dyn_sim_DW.UnitDelay_DSTATE =
      bicycle_dyn_sim_P.UnitDelay_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S10>/Out1' incorporates:
    //   Inport: '<S10>/In1'

    bicycle_dyn_sim_B.In1 = bicycle_dyn_sim_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    bicycle_dyn_sim_DW.obj_j.matlabCodegenIsDeleted = false;
    bicycle_dyn_sim_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[8] = '\x00';
    Sub_bicycle_dyn_sim_17.createSubscriber(&b_zeroDelimTopic[0], 1);
    bicycle_dyn_sim_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S4>/Publish'
    // Start for MATLABSystem: '<S16>/SinkBlock'
    bicycle_dyn_sim_DW.obj_i0.matlabCodegenIsDeleted = false;
    bicycle_dyn_sim_DW.obj_i0.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[5] = '\x00';
    Pub_bicycle_dyn_sim_126.createPublisher(&b_zeroDelimTopic_0[0], 1);
    bicycle_dyn_sim_DW.obj_i0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S16>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S4>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S4>/Publish1'
    // Start for MATLABSystem: '<S17>/SinkBlock'
    bicycle_dyn_sim_DW.obj_i.matlabCodegenIsDeleted = false;
    bicycle_dyn_sim_DW.obj_i.isInitialized = 1;
    b_zeroDelimTopic_1[0] = '/';
    b_zeroDelimTopic_1[1] = 't';
    b_zeroDelimTopic_1[2] = 'f';
    b_zeroDelimTopic_1[3] = '\x00';
    Pub_bicycle_dyn_sim_127.createPublisher(&b_zeroDelimTopic_1[0], 1);
    bicycle_dyn_sim_DW.obj_i.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S4>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<S4>/Publish2'
    // Start for MATLABSystem: '<S18>/SinkBlock'
    bicycle_dyn_sim_DW.obj.matlabCodegenIsDeleted = false;
    bicycle_dyn_sim_DW.obj.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      b_zeroDelimTopic_2[i] = tmp_1[i];
    }

    b_zeroDelimTopic_2[13] = '\x00';
    Pub_bicycle_dyn_sim_128.createPublisher(&b_zeroDelimTopic_2[0], 1);
    bicycle_dyn_sim_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S18>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S4>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<S2>/Publish'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    bicycle_dyn_sim_DW.obj_o.matlabCodegenIsDeleted = false;
    bicycle_dyn_sim_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic_3[i] = tmp_2[i];
    }

    b_zeroDelimTopic_3[6] = '\x00';
    Pub_bicycle_dyn_sim_134.createPublisher(&b_zeroDelimTopic_3[0], 1);
    bicycle_dyn_sim_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Publish'
  }
}

// Model terminate function
void bicycle_dyn_sim_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S3>/Subscribe'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!bicycle_dyn_sim_DW.obj_j.matlabCodegenIsDeleted) {
    bicycle_dyn_sim_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe'

  // Terminate for Atomic SubSystem: '<S4>/Publish'
  // Terminate for MATLABSystem: '<S16>/SinkBlock'
  if (!bicycle_dyn_sim_DW.obj_i0.matlabCodegenIsDeleted) {
    bicycle_dyn_sim_DW.obj_i0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/SinkBlock'
  // End of Terminate for SubSystem: '<S4>/Publish'

  // Terminate for Atomic SubSystem: '<S4>/Publish1'
  // Terminate for MATLABSystem: '<S17>/SinkBlock'
  if (!bicycle_dyn_sim_DW.obj_i.matlabCodegenIsDeleted) {
    bicycle_dyn_sim_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/SinkBlock'
  // End of Terminate for SubSystem: '<S4>/Publish1'

  // Terminate for Atomic SubSystem: '<S4>/Publish2'
  // Terminate for MATLABSystem: '<S18>/SinkBlock'
  if (!bicycle_dyn_sim_DW.obj.matlabCodegenIsDeleted) {
    bicycle_dyn_sim_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/SinkBlock'
  // End of Terminate for SubSystem: '<S4>/Publish2'

  // Terminate for Atomic SubSystem: '<S2>/Publish'
  // Terminate for MATLABSystem: '<S8>/SinkBlock'
  if (!bicycle_dyn_sim_DW.obj_o.matlabCodegenIsDeleted) {
    bicycle_dyn_sim_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
