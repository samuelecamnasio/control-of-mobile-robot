//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: planPublisher_test.cpp
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
#include "planPublisher_test.h"
#include "planPublisher_test_private.h"

// Block signals (default storage)
B_planPublisher_test_T planPublisher_test_B;

// Block states (default storage)
DW_planPublisher_test_T planPublisher_test_DW;

// Real-time model
RT_MODEL_planPublisher_test_T planPublisher_test_M_ =
  RT_MODEL_planPublisher_test_T();
RT_MODEL_planPublisher_test_T *const planPublisher_test_M =
  &planPublisher_test_M_;
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
void planPublisher_test_step(void)
{
  real_T len;
  real_T pathPos;
  real_T u;
  real_T u_tmp;
  int32_T seq;

  // Step: '<Root>/Publishing delay'
  if (((planPublisher_test_M->Timing.clockTick0) * 0.2) <
      planPublisher_test_P.Publishingdelay_Time) {
    u = planPublisher_test_P.Publishingdelay_Y0;
  } else {
    u = planPublisher_test_P.Publishingdelay_YFinal;
  }

  // End of Step: '<Root>/Publishing delay'

  // Outputs for Enabled SubSystem: '<Root>/Single plan message publisher' incorporates:
  //   EnablePort: '<S1>/Enable'

  if (u > 0.0) {
    // Outputs for Enabled SubSystem: '<S1>/Path publisher Single execution' incorporates:
    //   EnablePort: '<S2>/Enable'

    // DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
    //   Delay: '<S1>/Delay'

    if (planPublisher_test_DW.Delay_DSTATE != 0.0) {
      // SignalConversion generated from: '<S2>/Enable signal' incorporates:
      //   Constant: '<S2>/Constant'

      planPublisher_test_B.OutportBufferForEnablesignal =
        planPublisher_test_P.Constant_Value_f;

      // MATLABSystem: '<S2>/Current Time'
      currentROSTimeDouble(&pathPos);

      // MATLAB Function: '<S2>/MATLAB Function' incorporates:
      //   Constant: '<S1>/Desired trajectory'
      //   Constant: '<S1>/frame_id'
      //   Constant: '<S3>/Constant'
      //   Delay: '<S2>/Delay'
      //   MATLABSystem: '<S2>/Current Time'

      planPublisher_test_B.pathMsg = planPublisher_test_P.Constant_Value;
      len = 77.0 - planPublisher_test_DW.Delay_DSTATE_j * 25.0;
      if ((25.0 < len) || rtIsNaN(len)) {
        len = 25.0;
      }

      if (pathPos < 0.0) {
        u = ceil(pathPos);
      } else {
        u = floor(pathPos);
      }

      planPublisher_test_B.pathMsg.Header.Stamp.Sec = u;
      u = (pathPos - u) * 1.0E+9;
      if (u < 0.0) {
        planPublisher_test_B.pathMsg.Header.Stamp.Nsec = ceil(u);
      } else {
        planPublisher_test_B.pathMsg.Header.Stamp.Nsec = floor(u);
      }

      planPublisher_test_B.pathMsg.Header.FrameId[0] =
        planPublisher_test_P.frame_id_Value[0];
      planPublisher_test_B.pathMsg.Header.FrameId[1] =
        planPublisher_test_P.frame_id_Value[1];
      planPublisher_test_B.pathMsg.Header.FrameId[2] =
        planPublisher_test_P.frame_id_Value[2];
      planPublisher_test_B.pathMsg.Header.FrameId[3] =
        planPublisher_test_P.frame_id_Value[3];
      planPublisher_test_B.pathMsg.Header.FrameId_SL_Info.CurrentLength = 4U;
      u = rt_roundd_snf(len);
      if (u >= 0.0) {
        planPublisher_test_B.pathMsg.Poses_SL_Info.CurrentLength =
          static_cast<uint32_T>(static_cast<int32_T>(u));
      } else {
        planPublisher_test_B.pathMsg.Poses_SL_Info.CurrentLength = 0U;
      }

      for (seq = 0; seq < static_cast<int32_T>(len); seq++) {
        pathPos = (static_cast<real_T>(seq) + 1.0) + 25.0 *
          planPublisher_test_DW.Delay_DSTATE_j;
        u_tmp = planPublisher_test_P.desired_traj[static_cast<int32_T>(pathPos)
          + 230];
        if (u_tmp < 0.0) {
          u = ceil(u_tmp);
        } else {
          u = floor(u_tmp);
        }

        planPublisher_test_B.pathMsg.Poses[seq].Header.Stamp.Sec = u;
        u = (u_tmp - u) * 1.0E+9;
        if (u < 0.0) {
          planPublisher_test_B.pathMsg.Poses[seq].Header.Stamp.Nsec = ceil(u);
        } else {
          planPublisher_test_B.pathMsg.Poses[seq].Header.Stamp.Nsec = floor(u);
        }

        planPublisher_test_B.pathMsg.Poses[seq].Header.FrameId[0] =
          planPublisher_test_P.frame_id_Value[0];
        planPublisher_test_B.pathMsg.Poses[seq].Header.FrameId[1] =
          planPublisher_test_P.frame_id_Value[1];
        planPublisher_test_B.pathMsg.Poses[seq].Header.FrameId[2] =
          planPublisher_test_P.frame_id_Value[2];
        planPublisher_test_B.pathMsg.Poses[seq].Header.FrameId[3] =
          planPublisher_test_P.frame_id_Value[3];
        planPublisher_test_B.pathMsg.Poses[seq].
          Header.FrameId_SL_Info.CurrentLength = 4U;
        planPublisher_test_B.pathMsg.Poses[seq].Pose.Position.X =
          planPublisher_test_P.desired_traj[static_cast<int32_T>(pathPos) - 1];
        planPublisher_test_B.pathMsg.Poses[seq].Pose.Position.Y =
          planPublisher_test_P.desired_traj[static_cast<int32_T>(pathPos) + 76];
        planPublisher_test_B.pathMsg.Poses[seq].Pose.Position.Z = 0.0;
        pathPos = planPublisher_test_P.desired_traj[static_cast<int32_T>(pathPos)
          + 153] / 2.0;
        u = cos(pathPos);
        pathPos = sin(pathPos);
        planPublisher_test_B.pathMsg.Poses[seq].Pose.Orientation.X = 0.0 *
          pathPos + u;
        planPublisher_test_B.pathMsg.Poses[seq].Pose.Orientation.Y = pathPos -
          0.0 * u;
        planPublisher_test_B.pathMsg.Poses[seq].Pose.Orientation.Z = 0.0 * u +
          0.0 * pathPos;
        planPublisher_test_B.pathMsg.Poses[seq].Pose.Orientation.W = 0.0 * u -
          0.0 * pathPos;
      }

      planPublisher_test_DW.Delay_DSTATE_j++;

      // End of MATLAB Function: '<S2>/MATLAB Function'

      // Outputs for Atomic SubSystem: '<S2>/Publish'
      // MATLABSystem: '<S5>/SinkBlock'
      Pub_planPublisher_test_5.publish(&planPublisher_test_B.pathMsg);

      // End of Outputs for SubSystem: '<S2>/Publish'
    }

    // End of Outputs for SubSystem: '<S1>/Path publisher Single execution'

    // Stop: '<S1>/Stop Simulation' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion'
    //   Delay: '<S1>/Delay'
    //   Logic: '<S1>/NOT'

    if (!(planPublisher_test_DW.Delay_DSTATE != 0.0)) {
      rtmSetStopRequested(planPublisher_test_M, 1);
    }

    // End of Stop: '<S1>/Stop Simulation'

    // Update for Delay: '<S1>/Delay'
    planPublisher_test_DW.Delay_DSTATE =
      planPublisher_test_B.OutportBufferForEnablesignal;
  }

  // End of Outputs for SubSystem: '<Root>/Single plan message publisher'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.2, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  planPublisher_test_M->Timing.clockTick0++;
}

// Model initialize function
void planPublisher_test_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T tmp[5] = { '/', 'p', 'l', 'a', 'n' };

    int32_T i;
    char_T b_zeroDelimTopic[6];

    // SystemInitialize for Enabled SubSystem: '<Root>/Single plan message publisher' 
    // InitializeConditions for Delay: '<S1>/Delay'
    planPublisher_test_DW.Delay_DSTATE =
      planPublisher_test_P.Delay_InitialCondition_e;

    // SystemInitialize for Enabled SubSystem: '<S1>/Path publisher Single execution' 
    // InitializeConditions for Delay: '<S2>/Delay'
    planPublisher_test_DW.Delay_DSTATE_j =
      planPublisher_test_P.Delay_InitialCondition;

    // SystemInitialize for SignalConversion generated from: '<S2>/Enable signal' incorporates:
    //   Constant: '<S2>/Constant'

    planPublisher_test_B.OutportBufferForEnablesignal =
      planPublisher_test_P.Constant_Value_f;

    // SystemInitialize for Atomic SubSystem: '<S2>/Publish'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    planPublisher_test_DW.obj_d.matlabCodegenIsDeleted = false;
    planPublisher_test_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[5] = '\x00';
    Pub_planPublisher_test_5.createPublisher(&b_zeroDelimTopic[0], 1);
    planPublisher_test_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Publish'

    // Start for MATLABSystem: '<S2>/Current Time'
    planPublisher_test_DW.obj.matlabCodegenIsDeleted = false;
    planPublisher_test_DW.obj.isInitialized = 1;
    planPublisher_test_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S1>/Path publisher Single execution' 
    // End of SystemInitialize for SubSystem: '<Root>/Single plan message publisher' 
  }
}

// Model terminate function
void planPublisher_test_terminate(void)
{
  // Terminate for Enabled SubSystem: '<Root>/Single plan message publisher'
  // Terminate for Enabled SubSystem: '<S1>/Path publisher Single execution'
  // Terminate for MATLABSystem: '<S2>/Current Time'
  if (!planPublisher_test_DW.obj.matlabCodegenIsDeleted) {
    planPublisher_test_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Current Time'

  // Terminate for Atomic SubSystem: '<S2>/Publish'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!planPublisher_test_DW.obj_d.matlabCodegenIsDeleted) {
    planPublisher_test_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish'
  // End of Terminate for SubSystem: '<S1>/Path publisher Single execution'
  // End of Terminate for SubSystem: '<Root>/Single plan message publisher'
}

//
// File trailer for generated code.
//
// [EOF]
//
