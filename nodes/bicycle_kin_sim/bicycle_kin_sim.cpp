//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: bicycle_kin_sim.cpp
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
#include "bicycle_kin_sim.h"
#include "bicycle_kin_sim_private.h"

// Block signals (default storage)
B_bicycle_kin_sim_T bicycle_kin_sim_B;

// Continuous states
X_bicycle_kin_sim_T bicycle_kin_sim_X;

// Block states (default storage)
DW_bicycle_kin_sim_T bicycle_kin_sim_DW;

// Real-time model
RT_MODEL_bicycle_kin_sim_T bicycle_kin_sim_M_ = RT_MODEL_bicycle_kin_sim_T();
RT_MODEL_bicycle_kin_sim_T *const bicycle_kin_sim_M = &bicycle_kin_sim_M_;

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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  bicycle_kin_sim_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  bicycle_kin_sim_step();
  bicycle_kin_sim_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  bicycle_kin_sim_step();
  bicycle_kin_sim_derivatives();

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

//
// Output and update for atomic system:
//    '<S4>/MATLAB Function'
//    '<S4>/MATLAB Function2'
//
void bicycle_kin_sim_MATLABFunction(real_T rtu_time, const
  SL_Bus_bicycle_kin_sim_nav_msgs_Odometry *rtu_blankMsg, const uint8_T
  rtu_frame_id[4], const uint8_T rtu_child_frame_id[9], real_T rtu_x, real_T
  rtu_y, real_T rtu_theta, SL_Bus_bicycle_kin_sim_nav_msgs_Odometry *rty_odomMsg)
{
  real_T s_idx_2;
  real_T u;
  int32_T i;
  *rty_odomMsg = *rtu_blankMsg;
  if (rtu_time < 0.0) {
    u = ceil(rtu_time);
  } else {
    u = floor(rtu_time);
  }

  rty_odomMsg->Header.Stamp.Sec = u;
  u = (rtu_time - u) * 1.0E+9;
  if (u < 0.0) {
    rty_odomMsg->Header.Stamp.Nsec = ceil(u);
  } else {
    rty_odomMsg->Header.Stamp.Nsec = floor(u);
  }

  rty_odomMsg->Header.FrameId[0] = rtu_frame_id[0];
  rty_odomMsg->Header.FrameId[1] = rtu_frame_id[1];
  rty_odomMsg->Header.FrameId[2] = rtu_frame_id[2];
  rty_odomMsg->Header.FrameId[3] = rtu_frame_id[3];
  rty_odomMsg->Header.FrameId_SL_Info.CurrentLength = 4U;
  for (i = 0; i < 9; i++) {
    rty_odomMsg->ChildFrameId[i] = rtu_child_frame_id[i];
  }

  rty_odomMsg->ChildFrameId_SL_Info.CurrentLength = 9U;
  rty_odomMsg->Pose.Pose.Position.X = rtu_x;
  rty_odomMsg->Pose.Pose.Position.Y = rtu_y;
  rty_odomMsg->Pose.Pose.Position.Z = 0.0;
  s_idx_2 = rtu_theta / 2.0;
  u = cos(s_idx_2);
  s_idx_2 = sin(s_idx_2);
  rty_odomMsg->Pose.Pose.Orientation.X = 0.0 * s_idx_2 + u;
  rty_odomMsg->Pose.Pose.Orientation.Y = s_idx_2 - 0.0 * u;
  rty_odomMsg->Pose.Pose.Orientation.Z = 0.0 * u + 0.0 * s_idx_2;
  rty_odomMsg->Pose.Pose.Orientation.W = 0.0 * u - 0.0 * s_idx_2;
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
void bicycle_kin_sim_step(void)
{
  real_T dstate_tmp;
  real_T l;
  real_T s_idx_2;
  int32_T i;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(bicycle_kin_sim_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&bicycle_kin_sim_M->solverInfo,
                          ((bicycle_kin_sim_M->Timing.clockTick0+1)*
      bicycle_kin_sim_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(bicycle_kin_sim_M)) {
    bicycle_kin_sim_M->Timing.t[0] = rtsiGetT(&bicycle_kin_sim_M->solverInfo);
  }

  // Integrator: '<S1>/State'
  bicycle_kin_sim_B.State[0] = bicycle_kin_sim_X.State_CSTATE[0];
  bicycle_kin_sim_B.State[1] = bicycle_kin_sim_X.State_CSTATE[1];
  bicycle_kin_sim_B.State[2] = bicycle_kin_sim_X.State_CSTATE[2];
  if (rtmIsMajorTimeStep(bicycle_kin_sim_M)) {
    // Outputs for Atomic SubSystem: '<S3>/Subscribe'
    // MATLABSystem: '<S9>/SourceBlock' incorporates:
    //   Inport: '<S10>/In1'

    b_varargout_1 = Sub_bicycle_kin_sim_17.getLatestMessage
      (&bicycle_kin_sim_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    if (b_varargout_1) {
      bicycle_kin_sim_B.In1 = bicycle_kin_sim_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S9>/SourceBlock'
    // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/Subscribe'

    // MATLAB Function: '<S1>/Bicycle kinematics' incorporates:
    //   Constant: '<S1>/Centre-Front Distance'
    //   Constant: '<S1>/Rear-Centre Distance'
    //   Delay: '<S1>/Delay'
    //   Delay: '<S1>/Delay1'

    l = bicycle_kin_sim_P.Bicyclekinematicmodel_CFD +
      bicycle_kin_sim_P.Bicyclekinematicmodel_RCD;
    s_idx_2 = tan(bicycle_kin_sim_B.In1.Angular.Z);
    dstate_tmp = bicycle_kin_sim_DW.Delay_DSTATE +
      bicycle_kin_sim_DW.Delay1_DSTATE;
    bicycle_kin_sim_B.dstate[0] = cos(dstate_tmp) *
      bicycle_kin_sim_B.In1.Linear.X;
    bicycle_kin_sim_B.dstate[1] = sin(dstate_tmp) *
      bicycle_kin_sim_B.In1.Linear.X;
    bicycle_kin_sim_B.dstate[2] = bicycle_kin_sim_B.In1.Linear.X * cos
      (bicycle_kin_sim_DW.Delay_DSTATE) * s_idx_2 / l;
    bicycle_kin_sim_DW.Delay_DSTATE = atan
      (bicycle_kin_sim_P.Bicyclekinematicmodel_RCD * s_idx_2 / l);

    // DigitalClock: '<S4>/Digital Clock'
    l = ((bicycle_kin_sim_M->Timing.clockTick1) * 0.01);

    // MATLAB Function: '<S4>/MATLAB Function2' incorporates:
    //   Constant: '<S11>/Constant'
    //   Constant: '<S4>/frame_id'
    //   Constant: '<S4>/frame_id2'
    //   Delay: '<S1>/Delay'
    //   Sum: '<S1>/Sum'

    bicycle_kin_sim_MATLABFunction(l, &bicycle_kin_sim_P.Constant_Value_k,
      bicycle_kin_sim_P.frame_id_Value, bicycle_kin_sim_P.frame_id2_Value,
      bicycle_kin_sim_B.State[0], bicycle_kin_sim_B.State[1],
      bicycle_kin_sim_B.State[2] + bicycle_kin_sim_DW.Delay_DSTATE,
      &bicycle_kin_sim_B.rtb_odomMsg_m);

    // Outputs for Atomic SubSystem: '<S4>/Publish2'
    // MATLABSystem: '<S18>/SinkBlock'
    Pub_bicycle_kin_sim_118.publish(&bicycle_kin_sim_B.rtb_odomMsg_m);

    // End of Outputs for SubSystem: '<S4>/Publish2'

    // MATLAB Function: '<S4>/MATLAB Function' incorporates:
    //   Constant: '<S11>/Constant'
    //   Constant: '<S4>/frame_id'
    //   Constant: '<S4>/frame_id2'

    bicycle_kin_sim_MATLABFunction(l, &bicycle_kin_sim_P.Constant_Value_k,
      bicycle_kin_sim_P.frame_id_Value, bicycle_kin_sim_P.frame_id2_Value,
      bicycle_kin_sim_B.State[0], bicycle_kin_sim_B.State[1],
      bicycle_kin_sim_B.State[2], &bicycle_kin_sim_B.rtb_odomMsg_m);

    // Outputs for Atomic SubSystem: '<S4>/Publish'
    // MATLABSystem: '<S16>/SinkBlock'
    Pub_bicycle_kin_sim_72.publish(&bicycle_kin_sim_B.rtb_odomMsg_m);

    // End of Outputs for SubSystem: '<S4>/Publish'

    // MATLAB Function: '<S4>/MATLAB Function1' incorporates:
    //   Constant: '<S12>/Constant'
    //   Constant: '<S4>/frame_id'
    //   Constant: '<S4>/frame_id2'

    bicycle_kin_sim_B.tf2Msg = bicycle_kin_sim_P.Constant_Value;
    bicycle_kin_sim_B.tf2Msg.Transforms_SL_Info.CurrentLength = 1U;
    if (l < 0.0) {
      s_idx_2 = ceil(l);
    } else {
      s_idx_2 = floor(l);
    }

    bicycle_kin_sim_B.tf2Msg.Transforms[0].Header.Stamp.Sec = s_idx_2;
    l = (l - s_idx_2) * 1.0E+9;
    if (l < 0.0) {
      bicycle_kin_sim_B.tf2Msg.Transforms[0].Header.Stamp.Nsec = ceil(l);
    } else {
      bicycle_kin_sim_B.tf2Msg.Transforms[0].Header.Stamp.Nsec = floor(l);
    }

    bicycle_kin_sim_B.tf2Msg.Transforms[0].Header.FrameId[0] =
      bicycle_kin_sim_P.frame_id_Value[0];
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Header.FrameId[1] =
      bicycle_kin_sim_P.frame_id_Value[1];
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Header.FrameId[2] =
      bicycle_kin_sim_P.frame_id_Value[2];
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Header.FrameId[3] =
      bicycle_kin_sim_P.frame_id_Value[3];
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Header.FrameId_SL_Info.CurrentLength =
      4U;
    for (i = 0; i < 9; i++) {
      bicycle_kin_sim_B.tf2Msg.Transforms[0].ChildFrameId[i] =
        bicycle_kin_sim_P.frame_id2_Value[i];
    }

    bicycle_kin_sim_B.tf2Msg.Transforms[0].ChildFrameId_SL_Info.CurrentLength =
      9U;
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Transform.Translation.X =
      bicycle_kin_sim_B.State[0];
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Transform.Translation.Y =
      bicycle_kin_sim_B.State[1];
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Transform.Translation.Z = 0.0;
    s_idx_2 = bicycle_kin_sim_B.State[2] / 2.0;
    l = cos(s_idx_2);
    s_idx_2 = sin(s_idx_2);
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Transform.Rotation.X = 0.0 * s_idx_2
      + l;
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Transform.Rotation.Y = s_idx_2 - 0.0 *
      l;
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Transform.Rotation.Z = 0.0 * l + 0.0 *
      s_idx_2;
    bicycle_kin_sim_B.tf2Msg.Transforms[0].Transform.Rotation.W = 0.0 * l - 0.0 *
      s_idx_2;

    // End of MATLAB Function: '<S4>/MATLAB Function1'

    // Outputs for Atomic SubSystem: '<S4>/Publish1'
    // MATLABSystem: '<S17>/SinkBlock'
    Pub_bicycle_kin_sim_85.publish(&bicycle_kin_sim_B.tf2Msg);

    // End of Outputs for SubSystem: '<S4>/Publish1'

    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   UnitDelay: '<S2>/Unit Delay'

    l = bicycle_kin_sim_DW.UnitDelay_DSTATE * 100000.0;
    bicycle_kin_sim_B.timeMsg.Clock_.Sec = rt_roundd_snf(l * 1.0E-9);
    bicycle_kin_sim_B.timeMsg.Clock_.Nsec = rt_roundd_snf(l - rt_roundd_snf(l));
    bicycle_kin_sim_DW.UnitDelay_DSTATE++;

    // Outputs for Atomic SubSystem: '<S2>/Publish'
    // MATLABSystem: '<S8>/SinkBlock'
    Pub_bicycle_kin_sim_34.publish(&bicycle_kin_sim_B.timeMsg);

    // End of Outputs for SubSystem: '<S2>/Publish'
  }

  if (rtmIsMajorTimeStep(bicycle_kin_sim_M)) {
    if (rtmIsMajorTimeStep(bicycle_kin_sim_M)) {
      // Update for Delay: '<S1>/Delay1'
      bicycle_kin_sim_DW.Delay1_DSTATE = bicycle_kin_sim_B.State[2];
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(bicycle_kin_sim_M)) {
    rt_ertODEUpdateContinuousStates(&bicycle_kin_sim_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++bicycle_kin_sim_M->Timing.clockTick0;
    bicycle_kin_sim_M->Timing.t[0] = rtsiGetSolverStopTime
      (&bicycle_kin_sim_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.01s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.01, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      bicycle_kin_sim_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void bicycle_kin_sim_derivatives(void)
{
  XDot_bicycle_kin_sim_T *_rtXdot;
  _rtXdot = ((XDot_bicycle_kin_sim_T *) bicycle_kin_sim_M->derivs);

  // Derivatives for Integrator: '<S1>/State'
  _rtXdot->State_CSTATE[0] = bicycle_kin_sim_B.dstate[0];
  _rtXdot->State_CSTATE[1] = bicycle_kin_sim_B.dstate[1];
  _rtXdot->State_CSTATE[2] = bicycle_kin_sim_B.dstate[2];
}

// Model initialize function
void bicycle_kin_sim_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&bicycle_kin_sim_M->solverInfo,
                          &bicycle_kin_sim_M->Timing.simTimeStep);
    rtsiSetTPtr(&bicycle_kin_sim_M->solverInfo, &rtmGetTPtr(bicycle_kin_sim_M));
    rtsiSetStepSizePtr(&bicycle_kin_sim_M->solverInfo,
                       &bicycle_kin_sim_M->Timing.stepSize0);
    rtsiSetdXPtr(&bicycle_kin_sim_M->solverInfo, &bicycle_kin_sim_M->derivs);
    rtsiSetContStatesPtr(&bicycle_kin_sim_M->solverInfo, (real_T **)
                         &bicycle_kin_sim_M->contStates);
    rtsiSetNumContStatesPtr(&bicycle_kin_sim_M->solverInfo,
      &bicycle_kin_sim_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&bicycle_kin_sim_M->solverInfo,
      &bicycle_kin_sim_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&bicycle_kin_sim_M->solverInfo,
      &bicycle_kin_sim_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&bicycle_kin_sim_M->solverInfo,
      &bicycle_kin_sim_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&bicycle_kin_sim_M->solverInfo, (&rtmGetErrorStatus
      (bicycle_kin_sim_M)));
    rtsiSetRTModelPtr(&bicycle_kin_sim_M->solverInfo, bicycle_kin_sim_M);
  }

  rtsiSetSimTimeStep(&bicycle_kin_sim_M->solverInfo, MAJOR_TIME_STEP);
  bicycle_kin_sim_M->intgData.y = bicycle_kin_sim_M->odeY;
  bicycle_kin_sim_M->intgData.f[0] = bicycle_kin_sim_M->odeF[0];
  bicycle_kin_sim_M->intgData.f[1] = bicycle_kin_sim_M->odeF[1];
  bicycle_kin_sim_M->intgData.f[2] = bicycle_kin_sim_M->odeF[2];
  bicycle_kin_sim_M->contStates = ((X_bicycle_kin_sim_T *) &bicycle_kin_sim_X);
  rtsiSetSolverData(&bicycle_kin_sim_M->solverInfo, static_cast<void *>
                    (&bicycle_kin_sim_M->intgData));
  rtsiSetSolverName(&bicycle_kin_sim_M->solverInfo,"ode3");
  rtmSetTPtr(bicycle_kin_sim_M, &bicycle_kin_sim_M->Timing.tArray[0]);
  bicycle_kin_sim_M->Timing.stepSize0 = 0.01;

  {
    static const char_T tmp_0[13] = { '/', 'o', 'd', 'o', 'm', '_', 'c', 'h',
      'a', 's', 's', 'i', 's' };

    static const char_T tmp[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_2[6] = { '/', 'c', 'l', 'o', 'c', 'k' };

    static const char_T tmp_1[5] = { '/', 'o', 'd', 'o', 'm' };

    int32_T i;
    char_T b_zeroDelimTopic_0[14];
    char_T b_zeroDelimTopic[9];
    char_T b_zeroDelimTopic_3[7];
    char_T b_zeroDelimTopic_1[6];
    char_T b_zeroDelimTopic_2[4];

    // InitializeConditions for Integrator: '<S1>/State'
    bicycle_kin_sim_X.State_CSTATE[0] =
      bicycle_kin_sim_P.Bicyclekinematicmodel_state0[0];
    bicycle_kin_sim_X.State_CSTATE[1] =
      bicycle_kin_sim_P.Bicyclekinematicmodel_state0[1];
    bicycle_kin_sim_X.State_CSTATE[2] =
      bicycle_kin_sim_P.Bicyclekinematicmodel_state0[2];

    // InitializeConditions for Delay: '<S1>/Delay1'
    bicycle_kin_sim_DW.Delay1_DSTATE = bicycle_kin_sim_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay'
    bicycle_kin_sim_DW.Delay_DSTATE = bicycle_kin_sim_P.Delay_InitialCondition;

    // InitializeConditions for UnitDelay: '<S2>/Unit Delay'
    bicycle_kin_sim_DW.UnitDelay_DSTATE =
      bicycle_kin_sim_P.UnitDelay_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S10>/Out1' incorporates:
    //   Inport: '<S10>/In1'

    bicycle_kin_sim_B.In1 = bicycle_kin_sim_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    bicycle_kin_sim_DW.obj_j.matlabCodegenIsDeleted = false;
    bicycle_kin_sim_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[8] = '\x00';
    Sub_bicycle_kin_sim_17.createSubscriber(&b_zeroDelimTopic[0], 1);
    bicycle_kin_sim_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S4>/Publish2'
    // Start for MATLABSystem: '<S18>/SinkBlock'
    bicycle_kin_sim_DW.obj.matlabCodegenIsDeleted = false;
    bicycle_kin_sim_DW.obj.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[13] = '\x00';
    Pub_bicycle_kin_sim_118.createPublisher(&b_zeroDelimTopic_0[0], 1);
    bicycle_kin_sim_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S18>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S4>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<S4>/Publish'
    // Start for MATLABSystem: '<S16>/SinkBlock'
    bicycle_kin_sim_DW.obj_l.matlabCodegenIsDeleted = false;
    bicycle_kin_sim_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[5] = '\x00';
    Pub_bicycle_kin_sim_72.createPublisher(&b_zeroDelimTopic_1[0], 1);
    bicycle_kin_sim_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S16>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S4>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S4>/Publish1'
    // Start for MATLABSystem: '<S17>/SinkBlock'
    bicycle_kin_sim_DW.obj_k.matlabCodegenIsDeleted = false;
    bicycle_kin_sim_DW.obj_k.isInitialized = 1;
    b_zeroDelimTopic_2[0] = '/';
    b_zeroDelimTopic_2[1] = 't';
    b_zeroDelimTopic_2[2] = 'f';
    b_zeroDelimTopic_2[3] = '\x00';
    Pub_bicycle_kin_sim_85.createPublisher(&b_zeroDelimTopic_2[0], 1);
    bicycle_kin_sim_DW.obj_k.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S4>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<S2>/Publish'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    bicycle_kin_sim_DW.obj_e.matlabCodegenIsDeleted = false;
    bicycle_kin_sim_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic_3[i] = tmp_2[i];
    }

    b_zeroDelimTopic_3[6] = '\x00';
    Pub_bicycle_kin_sim_34.createPublisher(&b_zeroDelimTopic_3[0], 1);
    bicycle_kin_sim_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Publish'
  }
}

// Model terminate function
void bicycle_kin_sim_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S3>/Subscribe'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!bicycle_kin_sim_DW.obj_j.matlabCodegenIsDeleted) {
    bicycle_kin_sim_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe'

  // Terminate for Atomic SubSystem: '<S4>/Publish2'
  // Terminate for MATLABSystem: '<S18>/SinkBlock'
  if (!bicycle_kin_sim_DW.obj.matlabCodegenIsDeleted) {
    bicycle_kin_sim_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/SinkBlock'
  // End of Terminate for SubSystem: '<S4>/Publish2'

  // Terminate for Atomic SubSystem: '<S4>/Publish'
  // Terminate for MATLABSystem: '<S16>/SinkBlock'
  if (!bicycle_kin_sim_DW.obj_l.matlabCodegenIsDeleted) {
    bicycle_kin_sim_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/SinkBlock'
  // End of Terminate for SubSystem: '<S4>/Publish'

  // Terminate for Atomic SubSystem: '<S4>/Publish1'
  // Terminate for MATLABSystem: '<S17>/SinkBlock'
  if (!bicycle_kin_sim_DW.obj_k.matlabCodegenIsDeleted) {
    bicycle_kin_sim_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/SinkBlock'
  // End of Terminate for SubSystem: '<S4>/Publish1'

  // Terminate for Atomic SubSystem: '<S2>/Publish'
  // Terminate for MATLABSystem: '<S8>/SinkBlock'
  if (!bicycle_kin_sim_DW.obj_e.matlabCodegenIsDeleted) {
    bicycle_kin_sim_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
