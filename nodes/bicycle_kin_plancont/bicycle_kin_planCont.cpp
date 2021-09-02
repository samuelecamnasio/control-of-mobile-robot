//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: bicycle_kin_planCont.cpp
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
#include "bicycle_kin_planCont.h"
#include "bicycle_kin_planCont_private.h"

// Block signals (default storage)
B_bicycle_kin_planCont_T bicycle_kin_planCont_B;

// Block states (default storage)
DW_bicycle_kin_planCont_T bicycle_kin_planCont_DW;

// Previous zero-crossings (trigger) states
PrevZCX_bicycle_kin_planCont_T bicycle_kin_planCont_PrevZCX;

// Real-time model
RT_MODEL_bicycle_kin_planCont_T bicycle_kin_planCont_M_ =
  RT_MODEL_bicycle_kin_planCont_T();
RT_MODEL_bicycle_kin_planCont_T *const bicycle_kin_planCont_M =
  &bicycle_kin_planCont_M_;

// Forward declaration for local functions
static void bicycle_kin_pla_SystemCore_step(boolean_T *varargout_1, uint32_T
  *varargout_2_Header_Seq, real_T *varargout_2_Header_Stamp_Sec, real_T
  *varargout_2_Header_Stamp_Nsec, uint8_T varargout_2_Header_FrameId[128],
  uint32_T *varargout_2_Header_FrameId_SL_I, uint32_T
  *varargout_2_Header_FrameId_SL_0,
  SL_Bus_bicycle_kin_planCont_geometry_msgs_PoseStamped varargout_2_Poses[25],
  uint32_T *varargout_2_Poses_SL_Info_Curre, uint32_T
  *varargout_2_Poses_SL_Info_Recei);

//
// Output and update for atomic system:
//    '<S16>/MATLAB Function1'
//    '<S17>/MATLAB Function1'
//    '<S18>/MATLAB Function1'
//
void bicycle_kin_pla_MATLABFunction1(const
  SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped *rtu_blankMsg, real_T
  rtu_time, const uint8_T rtu_frame_id[4], real_T rtu_x, real_T rtu_y,
  SL_Bus_bicycle_kin_planCont_geometry_msgs_PointStamped *rty_outMsg)
{
  real_T u;
  *rty_outMsg = *rtu_blankMsg;
  if (rtu_time < 0.0) {
    u = ceil(rtu_time);
  } else {
    u = floor(rtu_time);
  }

  rty_outMsg->Header.Stamp.Sec = u;
  u = (rtu_time - u) * 1.0E+9;
  if (u < 0.0) {
    rty_outMsg->Header.Stamp.Nsec = ceil(u);
  } else {
    rty_outMsg->Header.Stamp.Nsec = floor(u);
  }

  rty_outMsg->Header.FrameId[0] = rtu_frame_id[0];
  rty_outMsg->Header.FrameId[1] = rtu_frame_id[1];
  rty_outMsg->Header.FrameId[2] = rtu_frame_id[2];
  rty_outMsg->Header.FrameId[3] = rtu_frame_id[3];
  rty_outMsg->Header.FrameId_SL_Info.CurrentLength = 4U;
  rty_outMsg->Point.X = rtu_x;
  rty_outMsg->Point.Y = rtu_y;
  rty_outMsg->Point.Z = 0.0;
}

static void bicycle_kin_pla_SystemCore_step(boolean_T *varargout_1, uint32_T
  *varargout_2_Header_Seq, real_T *varargout_2_Header_Stamp_Sec, real_T
  *varargout_2_Header_Stamp_Nsec, uint8_T varargout_2_Header_FrameId[128],
  uint32_T *varargout_2_Header_FrameId_SL_I, uint32_T
  *varargout_2_Header_FrameId_SL_0,
  SL_Bus_bicycle_kin_planCont_geometry_msgs_PoseStamped varargout_2_Poses[25],
  uint32_T *varargout_2_Poses_SL_Info_Curre, uint32_T
  *varargout_2_Poses_SL_Info_Recei)
{
  *varargout_1 = Sub_bicycle_kin_planCont_64.getLatestMessage
    (&bicycle_kin_planCont_B.b_varargout_2);
  *varargout_2_Header_Seq = bicycle_kin_planCont_B.b_varargout_2.Header.Seq;
  *varargout_2_Header_Stamp_Sec =
    bicycle_kin_planCont_B.b_varargout_2.Header.Stamp.Sec;
  *varargout_2_Header_Stamp_Nsec =
    bicycle_kin_planCont_B.b_varargout_2.Header.Stamp.Nsec;
  memcpy(&varargout_2_Header_FrameId[0],
         &bicycle_kin_planCont_B.b_varargout_2.Header.FrameId[0], sizeof(uint8_T)
         << 7U);
  *varargout_2_Header_FrameId_SL_I =
    bicycle_kin_planCont_B.b_varargout_2.Header.FrameId_SL_Info.CurrentLength;
  *varargout_2_Header_FrameId_SL_0 =
    bicycle_kin_planCont_B.b_varargout_2.Header.FrameId_SL_Info.ReceivedLength;
  memcpy(&varargout_2_Poses[0], &bicycle_kin_planCont_B.b_varargout_2.Poses[0],
         25U * sizeof(SL_Bus_bicycle_kin_planCont_geometry_msgs_PoseStamped));
  *varargout_2_Poses_SL_Info_Curre =
    bicycle_kin_planCont_B.b_varargout_2.Poses_SL_Info.CurrentLength;
  *varargout_2_Poses_SL_Info_Recei =
    bicycle_kin_planCont_B.b_varargout_2.Poses_SL_Info.ReceivedLength;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Model step function
void bicycle_kin_planCont_step(void)
{
  real_T rtb_v_x;
  int32_T jump;
  int32_T rtb_change;
  uint32_T b_varargout_2_Header_FrameId_SL;
  uint32_T b_varargout_2_Header_FrameId__0;
  uint32_T b_varargout_2_Header_Seq;
  uint32_T b_varargout_2_Poses_SL_Info_Cur;
  uint32_T b_varargout_2_Poses_SL_Info_Rec;
  boolean_T x[4];
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;
  boolean_T exitg1;

  // Outputs for Atomic SubSystem: '<S4>/Subscribe'
  // MATLABSystem: '<S14>/SourceBlock' incorporates:
  //   Inport: '<S19>/In1'

  bicycle_kin_pla_SystemCore_step(&b_varargout_1, &b_varargout_2_Header_Seq,
    &bicycle_kin_planCont_B.b_varargout_2_Header_Stamp_Sec,
    &bicycle_kin_planCont_B.history_x,
    bicycle_kin_planCont_B.b_varargout_2_Header_FrameId,
    &b_varargout_2_Header_FrameId_SL, &b_varargout_2_Header_FrameId__0,
    bicycle_kin_planCont_B.b_varargout_2_Poses, &b_varargout_2_Poses_SL_Info_Cur,
    &b_varargout_2_Poses_SL_Info_Rec);

  // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  if (b_varargout_1) {
    bicycle_kin_planCont_B.In1.Header.Seq = b_varargout_2_Header_Seq;
    bicycle_kin_planCont_B.In1.Header.Stamp.Sec =
      bicycle_kin_planCont_B.b_varargout_2_Header_Stamp_Sec;
    bicycle_kin_planCont_B.In1.Header.Stamp.Nsec =
      bicycle_kin_planCont_B.history_x;
    memcpy(&bicycle_kin_planCont_B.In1.Header.FrameId[0],
           &bicycle_kin_planCont_B.b_varargout_2_Header_FrameId[0], sizeof
           (uint8_T) << 7U);
    bicycle_kin_planCont_B.In1.Header.FrameId_SL_Info.CurrentLength =
      b_varargout_2_Header_FrameId_SL;
    bicycle_kin_planCont_B.In1.Header.FrameId_SL_Info.ReceivedLength =
      b_varargout_2_Header_FrameId__0;
    memcpy(&bicycle_kin_planCont_B.In1.Poses[0],
           &bicycle_kin_planCont_B.b_varargout_2_Poses[0], 25U * sizeof
           (SL_Bus_bicycle_kin_planCont_geometry_msgs_PoseStamped));
    bicycle_kin_planCont_B.In1.Poses_SL_Info.CurrentLength =
      b_varargout_2_Poses_SL_Info_Cur;
    bicycle_kin_planCont_B.In1.Poses_SL_Info.ReceivedLength =
      b_varargout_2_Poses_SL_Info_Rec;
  }

  // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'

  // Outputs for Triggered SubSystem: '<S4>/Triggered Subsystem' incorporates:
  //   TriggerPort: '<S15>/Trigger'

  if (b_varargout_1 && (bicycle_kin_planCont_PrevZCX.TriggeredSubsystem_Trig_ZCE
                        != POS_ZCSIG)) {
    // MATLAB Function: '<S15>/MATLAB Function'
    for (rtb_change = 0; rtb_change < 25; rtb_change++) {
      bicycle_kin_planCont_B.t[rtb_change] =
        bicycle_kin_planCont_B.In1.Poses[rtb_change].Header.Stamp.Nsec * 1.0E-9
        + bicycle_kin_planCont_B.In1.Poses[rtb_change].Header.Stamp.Sec;
      bicycle_kin_planCont_B.x[rtb_change] =
        bicycle_kin_planCont_B.In1.Poses[rtb_change].Pose.Position.X;
      bicycle_kin_planCont_B.y[rtb_change] =
        bicycle_kin_planCont_B.In1.Poses[rtb_change].Pose.Position.Y;
    }

    bicycle_kin_planCont_B.num_poses =
      bicycle_kin_planCont_B.In1.Poses_SL_Info.ReceivedLength;

    // End of MATLAB Function: '<S15>/MATLAB Function'

    // MATLABSystem: '<S15>/Current Time'
    currentROSTimeDouble(&bicycle_kin_planCont_B.CurrentTime);
  }

  bicycle_kin_planCont_PrevZCX.TriggeredSubsystem_Trig_ZCE = b_varargout_1;

  // End of Outputs for SubSystem: '<S4>/Triggered Subsystem'
  // End of Outputs for SubSystem: '<S4>/Subscribe'

  // MATLABSystem: '<S4>/Current Time'
  currentROSTimeDouble(&bicycle_kin_planCont_B.b_varargout_2_Header_Stamp_Sec);

  // Outputs for Atomic SubSystem: '<S2>/Subscribe'
  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  b_varargout_1_0 = Sub_bicycle_kin_planCont_53.getLatestMessage
    (&bicycle_kin_planCont_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (b_varargout_1_0) {
    bicycle_kin_planCont_B.In1_b = bicycle_kin_planCont_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S2>/Subscribe'

  // MATLAB Function: '<S2>/Conversion'
  x[0] = (bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.X == 0.0);
  x[1] = (bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.Y == 0.0);
  x[2] = (bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.Z == 0.0);
  x[3] = (bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.W == 0.0);
  b_varargout_1_0 = true;
  rtb_change = 0;
  exitg1 = false;
  while ((!exitg1) && (rtb_change < 4)) {
    if (!x[rtb_change]) {
      b_varargout_1_0 = false;
      exitg1 = true;
    } else {
      rtb_change++;
    }
  }

  if (b_varargout_1_0) {
    bicycle_kin_planCont_B.theta = 0.0;
  } else {
    bicycle_kin_planCont_B.v_y = 1.0 / sqrt
      (((bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.X *
         bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.X +
         bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.Y *
         bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.Y) +
        bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.Z *
        bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.Z) +
       bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.W *
       bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.W);
    bicycle_kin_planCont_B.history_x =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.X *
      bicycle_kin_planCont_B.v_y;
    bicycle_kin_planCont_B.history_y =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.Y *
      bicycle_kin_planCont_B.v_y;
    bicycle_kin_planCont_B.theta =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.Z *
      bicycle_kin_planCont_B.v_y;
    bicycle_kin_planCont_B.v_y *=
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Orientation.W;
    bicycle_kin_planCont_B.theta = rt_atan2d_snf((bicycle_kin_planCont_B.theta *
      bicycle_kin_planCont_B.v_y + bicycle_kin_planCont_B.history_x *
      bicycle_kin_planCont_B.history_y) * 2.0,
      ((bicycle_kin_planCont_B.history_x * bicycle_kin_planCont_B.history_x -
        bicycle_kin_planCont_B.history_y * bicycle_kin_planCont_B.history_y) -
       bicycle_kin_planCont_B.theta * bicycle_kin_planCont_B.theta) +
      bicycle_kin_planCont_B.v_y * bicycle_kin_planCont_B.v_y);
  }

  // MATLAB Function: '<S4>/MATLAB Function' incorporates:
  //   Constant: '<S4>/Constant2'
  //   MATLAB Function: '<S2>/Conversion'
  //   MATLABSystem: '<S14>/SourceBlock'
  //   UnitDelay: '<S4>/Unit Delay1'
  //   UnitDelay: '<S4>/Unit Delay2'
  //   UnitDelay: '<S4>/Unit Delay3'
  //   UnitDelay: '<S4>/Unit Delay4'

  rtb_change = 0;
  jump = 0;

  // Outputs for Atomic SubSystem: '<S4>/Subscribe'
  if ((bicycle_kin_planCont_DW.UnitDelay1_DSTATE == 0.0) && (!b_varargout_1)) {
    bicycle_kin_planCont_DW.UnitDelay3_DSTATE =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X;
    bicycle_kin_planCont_DW.UnitDelay2_DSTATE =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y;
    bicycle_kin_planCont_B.x_obj =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X;
    bicycle_kin_planCont_B.y_obj =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y;
    bicycle_kin_planCont_B.history_x =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X;
    bicycle_kin_planCont_B.history_y =
      bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y;
    bicycle_kin_planCont_DW.UnitDelay1_DSTATE = 0.0;
    rtb_v_x = 0.0;
    bicycle_kin_planCont_B.v_y = 0.0;
  } else {
    if (b_varargout_1) {
      bicycle_kin_planCont_DW.UnitDelay1_DSTATE = 2.0;
      jump = 1;
    }

    bicycle_kin_planCont_B.x_obj = bicycle_kin_planCont_B.x[static_cast<int32_T>
      (bicycle_kin_planCont_DW.UnitDelay1_DSTATE + 1.0) - 1];
    bicycle_kin_planCont_B.y_obj = bicycle_kin_planCont_B.y[static_cast<int32_T>
      (bicycle_kin_planCont_DW.UnitDelay1_DSTATE + 1.0) - 1];
    bicycle_kin_planCont_B.history_x = bicycle_kin_planCont_B.x
      [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1];
    bicycle_kin_planCont_B.history_y = bicycle_kin_planCont_B.y
      [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1];
    if (bicycle_kin_planCont_DW.UnitDelay1_DSTATE >=
        bicycle_kin_planCont_B.num_poses) {
      bicycle_kin_planCont_DW.UnitDelay3_DSTATE = bicycle_kin_planCont_B.x[
        static_cast<int32_T>(bicycle_kin_planCont_B.num_poses) - 1];
      bicycle_kin_planCont_DW.UnitDelay2_DSTATE = bicycle_kin_planCont_B.y[
        static_cast<int32_T>(bicycle_kin_planCont_B.num_poses) - 1];
      rtb_v_x = 0.0;
      bicycle_kin_planCont_B.v_y = 0.0;
    } else {
      bicycle_kin_planCont_B.v_y = bicycle_kin_planCont_B.t[static_cast<int32_T>
        (bicycle_kin_planCont_DW.UnitDelay1_DSTATE + 1.0) - 1] -
        bicycle_kin_planCont_B.t[static_cast<int32_T>
        (bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1];
      bicycle_kin_planCont_B.m = bicycle_kin_planCont_B.x_obj -
        bicycle_kin_planCont_B.history_x;
      rtb_v_x = bicycle_kin_planCont_B.m / bicycle_kin_planCont_B.v_y;
      bicycle_kin_planCont_B.xi = bicycle_kin_planCont_B.y_obj -
        bicycle_kin_planCont_B.history_y;
      bicycle_kin_planCont_B.v_y = bicycle_kin_planCont_B.xi /
        bicycle_kin_planCont_B.v_y;
      if (bicycle_kin_planCont_B.m != 0.0) {
        bicycle_kin_planCont_B.m = bicycle_kin_planCont_B.xi /
          bicycle_kin_planCont_B.m;
        bicycle_kin_planCont_B.xi =
          bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X -
          bicycle_kin_planCont_DW.UnitDelay3_DSTATE;
        bicycle_kin_planCont_B.d_a =
          bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y -
          bicycle_kin_planCont_DW.UnitDelay2_DSTATE;
        if ((sqrt(bicycle_kin_planCont_B.xi * bicycle_kin_planCont_B.xi +
                  bicycle_kin_planCont_B.d_a * bicycle_kin_planCont_B.d_a) <=
             bicycle_kin_planCont_P.Trajectoryinterpolator_R / 1.5) && (jump !=
             1)) {
          if (bicycle_kin_planCont_DW.UnitDelay4_DSTATE == 1.0) {
            if (bicycle_kin_planCont_B.x_obj > bicycle_kin_planCont_B.history_x)
            {
              bicycle_kin_planCont_DW.UnitDelay3_DSTATE =
                bicycle_kin_planCont_B.history_x + 1.0;
            } else {
              bicycle_kin_planCont_DW.UnitDelay3_DSTATE =
                bicycle_kin_planCont_B.history_x - 1.0;
            }

            bicycle_kin_planCont_DW.UnitDelay2_DSTATE =
              (bicycle_kin_planCont_DW.UnitDelay3_DSTATE -
               bicycle_kin_planCont_B.history_x) * bicycle_kin_planCont_B.m +
              bicycle_kin_planCont_B.history_y;
          } else {
            if (bicycle_kin_planCont_B.x_obj > bicycle_kin_planCont_B.history_x)
            {
              bicycle_kin_planCont_DW.UnitDelay3_DSTATE++;
            } else {
              bicycle_kin_planCont_DW.UnitDelay3_DSTATE--;
            }

            bicycle_kin_planCont_DW.UnitDelay2_DSTATE =
              (bicycle_kin_planCont_DW.UnitDelay3_DSTATE -
               bicycle_kin_planCont_B.history_x) * bicycle_kin_planCont_B.m +
              bicycle_kin_planCont_B.history_y;
          }
        }
      } else {
        bicycle_kin_planCont_B.m =
          bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X -
          bicycle_kin_planCont_DW.UnitDelay3_DSTATE;
        bicycle_kin_planCont_B.xi =
          bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y -
          bicycle_kin_planCont_DW.UnitDelay2_DSTATE;
        if ((sqrt(bicycle_kin_planCont_B.m * bicycle_kin_planCont_B.m +
                  bicycle_kin_planCont_B.xi * bicycle_kin_planCont_B.xi) <=
             bicycle_kin_planCont_P.Trajectoryinterpolator_R / 1.5) && (jump !=
             1)) {
          if (bicycle_kin_planCont_DW.UnitDelay4_DSTATE == 1.0) {
            if (bicycle_kin_planCont_B.y_obj > bicycle_kin_planCont_B.history_y)
            {
              bicycle_kin_planCont_DW.UnitDelay2_DSTATE =
                bicycle_kin_planCont_B.history_y + 1.0;
            } else {
              bicycle_kin_planCont_DW.UnitDelay2_DSTATE =
                bicycle_kin_planCont_B.history_y - 1.0;
            }
          } else if (bicycle_kin_planCont_B.y_obj >
                     bicycle_kin_planCont_B.history_y) {
            bicycle_kin_planCont_DW.UnitDelay2_DSTATE++;
          } else {
            bicycle_kin_planCont_DW.UnitDelay2_DSTATE--;
          }
        }
      }
    }

    if (bicycle_kin_planCont_DW.UnitDelay1_DSTATE <
        bicycle_kin_planCont_B.num_poses) {
      bicycle_kin_planCont_B.m =
        bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X -
        bicycle_kin_planCont_B.x_obj;
      bicycle_kin_planCont_B.xi =
        bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y -
        bicycle_kin_planCont_B.y_obj;
      if (sqrt(bicycle_kin_planCont_B.m * bicycle_kin_planCont_B.m +
               bicycle_kin_planCont_B.xi * bicycle_kin_planCont_B.xi) <=
          bicycle_kin_planCont_P.Trajectoryinterpolator_R) {
        bicycle_kin_planCont_DW.UnitDelay1_DSTATE++;
        if (bicycle_kin_planCont_B.x[static_cast<int32_T>
            (bicycle_kin_planCont_DW.UnitDelay1_DSTATE + 1.0) - 1] -
            bicycle_kin_planCont_B.x[static_cast<int32_T>
            (bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1] != 0.0) {
          if (bicycle_kin_planCont_B.x[static_cast<int32_T>
              (bicycle_kin_planCont_DW.UnitDelay1_DSTATE + 1.0) - 1] >
              bicycle_kin_planCont_B.x[static_cast<int32_T>
              (bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1]) {
            bicycle_kin_planCont_B.xi = bicycle_kin_planCont_B.x
              [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE) -
              1] + 0.5;
          } else {
            bicycle_kin_planCont_B.xi = bicycle_kin_planCont_B.x
              [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE) -
              1] - 0.5;
          }

          bicycle_kin_planCont_B.m = (bicycle_kin_planCont_B.y
            [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE +
            1.0) - 1] - bicycle_kin_planCont_B.y[static_cast<int32_T>
            (bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1]) /
            (bicycle_kin_planCont_B.x[static_cast<int32_T>
             (bicycle_kin_planCont_DW.UnitDelay1_DSTATE + 1.0) - 1] -
             bicycle_kin_planCont_B.x[static_cast<int32_T>
             (bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1]) *
            (bicycle_kin_planCont_B.xi - bicycle_kin_planCont_B.x
             [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE) -
             1]) + bicycle_kin_planCont_B.y[static_cast<int32_T>
            (bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1];
        } else {
          if (bicycle_kin_planCont_B.y[static_cast<int32_T>
              (bicycle_kin_planCont_DW.UnitDelay1_DSTATE + 1.0) - 1] >
              bicycle_kin_planCont_B.y[static_cast<int32_T>
              (bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1]) {
            bicycle_kin_planCont_B.m = bicycle_kin_planCont_B.y
              [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE) -
              1] + 0.5;
          } else {
            bicycle_kin_planCont_B.m = bicycle_kin_planCont_B.y
              [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE) -
              1] - 0.5;
          }

          bicycle_kin_planCont_B.xi = bicycle_kin_planCont_B.x
            [static_cast<int32_T>(bicycle_kin_planCont_DW.UnitDelay1_DSTATE) - 1];
        }

        bicycle_kin_planCont_DW.UnitDelay3_DSTATE = (bicycle_kin_planCont_B.xi -
          bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X) / 2.0 +
          bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X;
        bicycle_kin_planCont_DW.UnitDelay2_DSTATE = (bicycle_kin_planCont_B.m -
          bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y) / 2.0 +
          bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y;
        rtb_change = 1;
      }
    }
  }

  // End of MATLAB Function: '<S4>/MATLAB Function'
  // End of Outputs for SubSystem: '<S4>/Subscribe'

  // MATLAB Function: '<S18>/MATLAB Function1' incorporates:
  //   Constant: '<S18>/frame_id'
  //   Constant: '<S27>/Constant'
  //   MATLABSystem: '<S4>/Current Time'

  bicycle_kin_pla_MATLABFunction1(&bicycle_kin_planCont_P.Constant_Value_h,
    bicycle_kin_planCont_B.b_varargout_2_Header_Stamp_Sec,
    bicycle_kin_planCont_P.frame_id_Value_d, bicycle_kin_planCont_B.x_obj,
    bicycle_kin_planCont_B.y_obj, &bicycle_kin_planCont_B.outMsg);

  // Outputs for Atomic SubSystem: '<S18>/Publish'
  // MATLABSystem: '<S29>/SinkBlock'
  Pub_bicycle_kin_planCont_169.publish(&bicycle_kin_planCont_B.outMsg);

  // End of Outputs for SubSystem: '<S18>/Publish'

  // MATLAB Function: '<S3>/Proportional + velocity feed forward' incorporates:
  //   Constant: '<S3>/Constant'
  //   Constant: '<S3>/point distance'
  //   MATLAB Function: '<S10>/Bicycle kinematic feedback linearization'
  //   MATLAB Function: '<S2>/Conversion'
  //   UnitDelay: '<S4>/Unit Delay2'
  //   UnitDelay: '<S4>/Unit Delay3'

  bicycle_kin_planCont_B.x_obj = cos(bicycle_kin_planCont_B.theta);
  rtb_v_x += ((bicycle_kin_planCont_P.Proportionalbasedonfeedbackline *
               bicycle_kin_planCont_B.x_obj +
               bicycle_kin_planCont_DW.UnitDelay3_DSTATE) -
              (bicycle_kin_planCont_P.Proportionalbasedonfeedbackline * cos
               (bicycle_kin_planCont_B.theta) +
               bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.X)) *
    bicycle_kin_planCont_P.Proportionalbasedonfeedbackli_b;
  bicycle_kin_planCont_B.y_obj = sin(bicycle_kin_planCont_B.theta);
  bicycle_kin_planCont_B.m =
    ((bicycle_kin_planCont_P.Proportionalbasedonfeedbackline *
      bicycle_kin_planCont_B.y_obj + bicycle_kin_planCont_DW.UnitDelay2_DSTATE)
     - (bicycle_kin_planCont_P.Proportionalbasedonfeedbackline * sin
        (bicycle_kin_planCont_B.theta) +
        bicycle_kin_planCont_B.In1_b.Pose.Pose.Position.Y)) *
    bicycle_kin_planCont_P.Proportionalbasedonfeedbackli_b +
    bicycle_kin_planCont_B.v_y;

  // MATLAB Function: '<S10>/Bicycle kinematic feedback linearization' incorporates:
  //   Constant: '<S10>/Centre-Front Distance'
  //   Constant: '<S10>/Constant'
  //   Constant: '<S10>/Rear-Centre Distance'
  //   Constant: '<S3>/point distance'

  bicycle_kin_planCont_B.v_y = rtb_v_x * bicycle_kin_planCont_B.x_obj +
    bicycle_kin_planCont_B.m * bicycle_kin_planCont_B.y_obj;
  bicycle_kin_planCont_B.x_obj = bicycle_kin_planCont_B.m *
    bicycle_kin_planCont_B.x_obj - rtb_v_x * bicycle_kin_planCont_B.y_obj;
  bicycle_kin_planCont_B.theta = rtb_v_x * cos(bicycle_kin_planCont_B.theta) +
    bicycle_kin_planCont_B.m * sin(bicycle_kin_planCont_B.theta);
  if ((bicycle_kin_planCont_B.x_obj == 0.0) && (bicycle_kin_planCont_B.theta ==
       0.0)) {
    bicycle_kin_planCont_B.theta = 0.0;
  } else {
    bicycle_kin_planCont_B.theta = atan
      ((bicycle_kin_planCont_P.Bicyclekinematicfeedbacklineari +
        bicycle_kin_planCont_P.Bicyclekinematicfeedbacklinea_l) /
       bicycle_kin_planCont_P.Proportionalbasedonfeedbackline *
       bicycle_kin_planCont_B.x_obj / bicycle_kin_planCont_B.theta);
  }

  if (bicycle_kin_planCont_B.theta > 0.7) {
    bicycle_kin_planCont_B.theta = 0.7;
  } else {
    if (bicycle_kin_planCont_B.theta < -0.7) {
      bicycle_kin_planCont_B.theta = -0.7;
    }
  }

  if (bicycle_kin_planCont_P.Constant_Value_b == 1.0) {
    bicycle_kin_planCont_B.theta = 0.0;
    bicycle_kin_planCont_B.v_y = 0.0;
  }

  // BusAssignment: '<S1>/Bus Assignment' incorporates:
  //   Constant: '<S5>/Constant'
  //   MATLAB Function: '<S10>/Bicycle kinematic feedback linearization'

  bicycle_kin_planCont_B.BusAssignment = bicycle_kin_planCont_P.Constant_Value_a;
  bicycle_kin_planCont_B.BusAssignment.Linear.X = bicycle_kin_planCont_B.v_y;
  bicycle_kin_planCont_B.BusAssignment.Angular.Z = bicycle_kin_planCont_B.theta;

  // Outputs for Atomic SubSystem: '<S1>/Publish'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_bicycle_kin_planCont_9.publish(&bicycle_kin_planCont_B.BusAssignment);

  // End of Outputs for SubSystem: '<S1>/Publish'

  // MATLAB Function: '<S16>/MATLAB Function1' incorporates:
  //   Constant: '<S16>/frame_id'
  //   Constant: '<S21>/Constant'
  //   MATLABSystem: '<S4>/Current Time'

  bicycle_kin_pla_MATLABFunction1(&bicycle_kin_planCont_P.Constant_Value_k,
    bicycle_kin_planCont_B.b_varargout_2_Header_Stamp_Sec,
    bicycle_kin_planCont_P.frame_id_Value, bicycle_kin_planCont_B.history_x,
    bicycle_kin_planCont_B.history_y, &bicycle_kin_planCont_B.outMsg);

  // Outputs for Atomic SubSystem: '<S16>/Publish'
  // MATLABSystem: '<S23>/SinkBlock'
  Pub_bicycle_kin_planCont_213.publish(&bicycle_kin_planCont_B.outMsg);

  // End of Outputs for SubSystem: '<S16>/Publish'

  // MATLAB Function: '<S17>/MATLAB Function1' incorporates:
  //   Constant: '<S17>/frame_id'
  //   Constant: '<S24>/Constant'
  //   MATLABSystem: '<S4>/Current Time'
  //   UnitDelay: '<S4>/Unit Delay2'
  //   UnitDelay: '<S4>/Unit Delay3'

  bicycle_kin_pla_MATLABFunction1(&bicycle_kin_planCont_P.Constant_Value_i,
    bicycle_kin_planCont_B.b_varargout_2_Header_Stamp_Sec,
    bicycle_kin_planCont_P.frame_id_Value_m,
    bicycle_kin_planCont_DW.UnitDelay3_DSTATE,
    bicycle_kin_planCont_DW.UnitDelay2_DSTATE, &bicycle_kin_planCont_B.outMsg);

  // Outputs for Atomic SubSystem: '<S17>/Publish'
  // MATLABSystem: '<S26>/SinkBlock'
  Pub_bicycle_kin_planCont_195.publish(&bicycle_kin_planCont_B.outMsg);

  // End of Outputs for SubSystem: '<S17>/Publish'

  // Update for UnitDelay: '<S4>/Unit Delay4'
  bicycle_kin_planCont_DW.UnitDelay4_DSTATE = rtb_change;
}

// Model initialize function
void bicycle_kin_planCont_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T tmp_4[16] = { '/', 'i', 'n', 't', 'e', 'r', '_', 'o',
      'b', 'j', 'e', 'c', 't', 'i', 'v', 'e' };

    static const char_T tmp_3[15] = { '/', 'l', 'a', 's', 't', '_', 'o', 'b',
      'j', 'e', 'c', 't', 'i', 'v', 'e' };

    static const char_T tmp_1[10] = { '/', 'o', 'b', 'j', 'e', 'c', 't', 'i',
      'v', 'e' };

    static const char_T tmp_2[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp[5] = { '/', 'p', 'l', 'a', 'n' };

    static const char_T tmp_0[5] = { '/', 'o', 'd', 'o', 'm' };

    int32_T i;
    char_T b_zeroDelimTopic_3[17];
    char_T b_zeroDelimTopic_2[16];
    char_T b_zeroDelimTopic_0[11];
    char_T b_zeroDelimTopic_1[9];
    char_T b_zeroDelimTopic[6];
    bicycle_kin_planCont_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S4>/Unit Delay1'
    bicycle_kin_planCont_DW.UnitDelay1_DSTATE =
      bicycle_kin_planCont_P.UnitDelay1_InitialCondition;

    // InitializeConditions for UnitDelay: '<S4>/Unit Delay3'
    bicycle_kin_planCont_DW.UnitDelay3_DSTATE =
      bicycle_kin_planCont_P.UnitDelay3_InitialCondition;

    // InitializeConditions for UnitDelay: '<S4>/Unit Delay2'
    bicycle_kin_planCont_DW.UnitDelay2_DSTATE =
      bicycle_kin_planCont_P.UnitDelay2_InitialCondition;

    // InitializeConditions for UnitDelay: '<S4>/Unit Delay4'
    bicycle_kin_planCont_DW.UnitDelay4_DSTATE =
      bicycle_kin_planCont_P.UnitDelay4_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<S4>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S19>/Out1' incorporates:
    //   Inport: '<S19>/In1'

    bicycle_kin_planCont_B.In1 = bicycle_kin_planCont_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem'

    // Start for MATLABSystem: '<S14>/SourceBlock'
    bicycle_kin_planCont_DW.obj_g.matlabCodegenIsDeleted = false;
    bicycle_kin_planCont_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[5] = '\x00';
    Sub_bicycle_kin_planCont_64.createSubscriber(&b_zeroDelimTopic[0], 1);
    bicycle_kin_planCont_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S14>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S4>/Subscribe'

    // SystemInitialize for Triggered SubSystem: '<S4>/Triggered Subsystem'
    // Start for MATLABSystem: '<S15>/Current Time'
    bicycle_kin_planCont_DW.obj.matlabCodegenIsDeleted = false;
    bicycle_kin_planCont_DW.obj.isInitialized = 1;
    bicycle_kin_planCont_DW.obj.isSetupComplete = true;

    // SystemInitialize for MATLABSystem: '<S15>/Current Time' incorporates:
    //   Outport: '<S15>/startTime'

    bicycle_kin_planCont_B.CurrentTime = bicycle_kin_planCont_P.startTime_Y0;
    for (i = 0; i < 25; i++) {
      // SystemInitialize for Outport: '<S15>/t'
      bicycle_kin_planCont_B.t[i] = bicycle_kin_planCont_P.t_Y0;

      // SystemInitialize for Outport: '<S15>/x'
      bicycle_kin_planCont_B.x[i] = bicycle_kin_planCont_P.x_Y0;

      // SystemInitialize for Outport: '<S15>/y'
      bicycle_kin_planCont_B.y[i] = bicycle_kin_planCont_P.y_Y0;
    }

    // SystemInitialize for Outport: '<S15>/numPoses'
    bicycle_kin_planCont_B.num_poses = bicycle_kin_planCont_P.numPoses_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Triggered Subsystem'

    // SystemInitialize for Atomic SubSystem: '<S2>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S9>/Out1' incorporates:
    //   Inport: '<S9>/In1'

    bicycle_kin_planCont_B.In1_b = bicycle_kin_planCont_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    bicycle_kin_planCont_DW.obj_pt.matlabCodegenIsDeleted = false;
    bicycle_kin_planCont_DW.obj_pt.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic[i] = tmp_0[i];
    }

    b_zeroDelimTopic[5] = '\x00';
    Sub_bicycle_kin_planCont_53.createSubscriber(&b_zeroDelimTopic[0], 1);
    bicycle_kin_planCont_DW.obj_pt.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S18>/Publish'
    // Start for MATLABSystem: '<S29>/SinkBlock'
    bicycle_kin_planCont_DW.obj_p.matlabCodegenIsDeleted = false;
    bicycle_kin_planCont_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic_0[i] = tmp_1[i];
    }

    b_zeroDelimTopic_0[10] = '\x00';
    Pub_bicycle_kin_planCont_169.createPublisher(&b_zeroDelimTopic_0[0], 1);
    bicycle_kin_planCont_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S29>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S18>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    bicycle_kin_planCont_DW.obj_n.matlabCodegenIsDeleted = false;
    bicycle_kin_planCont_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_1[i] = tmp_2[i];
    }

    b_zeroDelimTopic_1[8] = '\x00';
    Pub_bicycle_kin_planCont_9.createPublisher(&b_zeroDelimTopic_1[0], 1);
    bicycle_kin_planCont_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S16>/Publish'
    // Start for MATLABSystem: '<S23>/SinkBlock'
    bicycle_kin_planCont_DW.obj_m.matlabCodegenIsDeleted = false;
    bicycle_kin_planCont_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_2[i] = tmp_3[i];
    }

    b_zeroDelimTopic_2[15] = '\x00';
    Pub_bicycle_kin_planCont_213.createPublisher(&b_zeroDelimTopic_2[0], 1);
    bicycle_kin_planCont_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S23>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S16>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S17>/Publish'
    // Start for MATLABSystem: '<S26>/SinkBlock'
    bicycle_kin_planCont_DW.obj_p3.matlabCodegenIsDeleted = false;
    bicycle_kin_planCont_DW.obj_p3.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic_3[i] = tmp_4[i];
    }

    b_zeroDelimTopic_3[16] = '\x00';
    Pub_bicycle_kin_planCont_195.createPublisher(&b_zeroDelimTopic_3[0], 1);
    bicycle_kin_planCont_DW.obj_p3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S26>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S17>/Publish'

    // Start for MATLABSystem: '<S4>/Current Time'
    bicycle_kin_planCont_DW.obj_o.matlabCodegenIsDeleted = false;
    bicycle_kin_planCont_DW.obj_o.isInitialized = 1;
    bicycle_kin_planCont_DW.obj_o.isSetupComplete = true;
  }
}

// Model terminate function
void bicycle_kin_planCont_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S4>/Subscribe'
  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!bicycle_kin_planCont_DW.obj_g.matlabCodegenIsDeleted) {
    bicycle_kin_planCont_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'
  // End of Terminate for SubSystem: '<S4>/Subscribe'

  // Terminate for Triggered SubSystem: '<S4>/Triggered Subsystem'
  // Terminate for MATLABSystem: '<S15>/Current Time'
  if (!bicycle_kin_planCont_DW.obj.matlabCodegenIsDeleted) {
    bicycle_kin_planCont_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/Current Time'
  // End of Terminate for SubSystem: '<S4>/Triggered Subsystem'

  // Terminate for MATLABSystem: '<S4>/Current Time'
  if (!bicycle_kin_planCont_DW.obj_o.matlabCodegenIsDeleted) {
    bicycle_kin_planCont_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Current Time'

  // Terminate for Atomic SubSystem: '<S2>/Subscribe'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!bicycle_kin_planCont_DW.obj_pt.matlabCodegenIsDeleted) {
    bicycle_kin_planCont_DW.obj_pt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe'

  // Terminate for Atomic SubSystem: '<S18>/Publish'
  // Terminate for MATLABSystem: '<S29>/SinkBlock'
  if (!bicycle_kin_planCont_DW.obj_p.matlabCodegenIsDeleted) {
    bicycle_kin_planCont_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/SinkBlock'
  // End of Terminate for SubSystem: '<S18>/Publish'

  // Terminate for Atomic SubSystem: '<S1>/Publish'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!bicycle_kin_planCont_DW.obj_n.matlabCodegenIsDeleted) {
    bicycle_kin_planCont_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish'

  // Terminate for Atomic SubSystem: '<S16>/Publish'
  // Terminate for MATLABSystem: '<S23>/SinkBlock'
  if (!bicycle_kin_planCont_DW.obj_m.matlabCodegenIsDeleted) {
    bicycle_kin_planCont_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S23>/SinkBlock'
  // End of Terminate for SubSystem: '<S16>/Publish'

  // Terminate for Atomic SubSystem: '<S17>/Publish'
  // Terminate for MATLABSystem: '<S26>/SinkBlock'
  if (!bicycle_kin_planCont_DW.obj_p3.matlabCodegenIsDeleted) {
    bicycle_kin_planCont_DW.obj_p3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/SinkBlock'
  // End of Terminate for SubSystem: '<S17>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
