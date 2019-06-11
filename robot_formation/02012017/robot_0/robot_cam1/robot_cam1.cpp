//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: robot_cam1.cpp
//
// Code generated for Simulink model 'robot_cam1'.
//
// Model version                  : 1.18
// Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
// C/C++ source code generated on : Wed Feb  1 20:20:38 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "robot_cam1.h"
#include "robot_cam1_private.h"
#define robot_cam1_MessageQueueLen     (105)
#define robot_cam1_MessageQueueLen_l   (1)

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

    y = atan2((real_T)u0_0, (real_T)u1_0);
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

//
// Output and update for atomic system:
//    '<S3>/Conversion1'
//    '<S3>/Conversion2'
//
void robot_cam1_Conversion1(real_T rtu_x, real_T rtu_y, real_T rtu_z, real_T
  rtu_w, B_Conversion1_robot_cam1_T *localB)
{
  real_T b_y;
  real_T q_idx_0;
  real_T q_idx_1;
  real_T q_idx_2;

  //  Convert the quaternion to a yaw angle (zyx euler angle)
  // MATLAB Function 'camera/Conversion1': '<S11>:1'
  // '<S11>:1:5' eul = quat2eul([w,x,y,z]);
  b_y = 1.0 / sqrt(((rtu_w * rtu_w + rtu_x * rtu_x) + rtu_y * rtu_y) + rtu_z *
                   rtu_z);
  q_idx_0 = rtu_w * b_y;
  q_idx_1 = rtu_x * b_y;
  q_idx_2 = rtu_y * b_y;
  b_y *= rtu_z;

  // '<S11>:1:6' yaw = eul(1);
  localB->yaw = rt_atan2d_snf((q_idx_1 * q_idx_2 + q_idx_0 * b_y) * 2.0,
    ((q_idx_0 * q_idx_0 + q_idx_1 * q_idx_1) - q_idx_2 * q_idx_2) - b_y * b_y);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

// Model step function
void robot_0ModelClass::step()
{
  boolean_T varargout_1;
  boolean_T varargout_1_0;

  // Outputs for Atomic SubSystem: '<S3>/Subscribe2'
  // Start for MATLABSystem: '<S14>/SourceBlock' incorporates:
  //   Inport: '<S16>/In1'
  //   MATLABSystem: '<S14>/SourceBlock'

  varargout_1 = Sub_robot_cam1_11.getLatestMessage(&robot_cam1_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S16>/Enable'

  if (varargout_1) {
    robot_cam1_B.In1 = robot_cam1_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S3>/Subscribe2'

  // Outputs for Atomic SubSystem: '<S3>/Subscribe1'
  // Start for MATLABSystem: '<S13>/SourceBlock' incorporates:
  //   Inport: '<S15>/In1'
  //   MATLABSystem: '<S13>/SourceBlock'

  varargout_1_0 = Sub_robot_cam1_10.getLatestMessage(&robot_cam1_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S13>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  if (varargout_1_0) {
    robot_cam1_B.In1_d = robot_cam1_B.varargout_2;
  }

  // End of Start for MATLABSystem: '<S13>/SourceBlock'
  // End of Outputs for SubSystem: '<S13>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S3>/Subscribe1'

  // MATLAB Function: '<S3>/Conversion2'
  // MATLAB Function 'cyc_pursuit2': '<S4>:1'
  // '<S4>:1:4' y1 = ((1-0.2)*u1+(u3*0.2)-(0.75*0.2));
  // '<S4>:1:5' y2 = ((1-0.2)*u2+(0.2*u4)+(1.2990*0.2));
  // '<S4>:1:6' y3=u1;
  // '<S4>:1:7' y4=u2;
  //        y1 = ((1-0.2)*u1+(u3*0.2)+(1.5451*0.2));
  //          y2 = ((1-0.2)*u2+(0.2*u4)+(4.7553*0.2));
  //          y3 = ((1-0.2)*u3+(u5*0.2)-(4.0451*0.2));
  //          y4 = ((1-0.2)*u4+(u6*0.2)+(2.9389*0.2));
  //          y5 = ((1-0.2)*u5+(u7*0.2)-(4.0451*0.2));
  //          y6 = ((1-0.2)*u6+(u8*0.2)-(2.9389*0.2));
  //          y7 = ((1-0.2)*u7+(u9*0.2)+(1.5451*0.2));
  //          y8 = ((1-0.2)*u8+(u10*0.2)-(4.7553*0.2));
  //          y9 = ((1-0.2)*u9+(u1*0.2)+(5*0.2));
  //          y10 = ((1-0.2)*u10+(u2*0.2)+(0*0.2));
  robot_cam1_Conversion1(robot_cam1_B.In1.Pose.Orientation.X,
    robot_cam1_B.In1.Pose.Orientation.Y, robot_cam1_B.In1.Pose.Orientation.Z,
    robot_cam1_B.In1.Pose.Orientation.W, &robot_cam1_B.sf_Conversion2);

  // Outputs for Enabled SubSystem: '<S1>/Command Velocity Publisher' incorporates:
  //   EnablePort: '<S5>/Enable'

  // Outputs for Enabled SubSystem: '<S2>/Proportional Controller' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Outputs for Atomic SubSystem: '<S3>/Subscribe2'
  // Start for MATLABSystem: '<S14>/SourceBlock' incorporates:
  //   MATLABSystem: '<S14>/SourceBlock'

  if (varargout_1) {
    // Sum: '<S9>/Sum1' incorporates:
    //   MATLAB Function: '<Root>/cyc_pursuit2'
    //   SignalConversion: '<S3>/SigConversion_InsertedFor_Bus Selector1_at_outport_1'
    //   SignalConversion: '<S3>/SigConversion_InsertedFor_Bus Selector2_at_outport_1'

    robot_cam1_B.Sum1 = ((0.8 * robot_cam1_B.In1.Pose.Position.Y + 0.2 *
                          robot_cam1_B.In1_d.Pose.Position.Y) + 0.2598) -
      robot_cam1_B.In1.Pose.Position.Y;

    // Sum: '<S9>/Sum' incorporates:
    //   MATLAB Function: '<Root>/cyc_pursuit2'
    //   SignalConversion: '<S3>/SigConversion_InsertedFor_Bus Selector1_at_outport_0'
    //   SignalConversion: '<S3>/SigConversion_InsertedFor_Bus Selector2_at_outport_0'

    robot_cam1_B.Sum = ((0.8 * robot_cam1_B.In1.Pose.Position.X +
                         robot_cam1_B.In1_d.Pose.Position.X * 0.2) -
                        0.15000000000000002) - robot_cam1_B.In1.Pose.Position.X;

    // Fcn: '<S9>/Distance1'
    robot_cam1_B.Sum3 = rt_powd_snf(robot_cam1_B.Sum, 2.0) + rt_powd_snf
      (robot_cam1_B.Sum1, 2.0);
    if (robot_cam1_B.Sum3 < 0.0) {
      robot_cam1_B.Sum3 = -sqrt(-robot_cam1_B.Sum3);
    } else {
      robot_cam1_B.Sum3 = sqrt(robot_cam1_B.Sum3);
    }

    // End of Fcn: '<S9>/Distance1'

    // Switch: '<S9>/Switch1' incorporates:
    //   Constant: '<S10>/Constant'
    //   Constant: '<S9>/Stop1'
    //   Fcn: '<S9>/Bound [-pi,pi]'
    //   RelationalOperator: '<S10>/Compare'
    //   Switch: '<S9>/Switch2'

    if (robot_cam1_B.Sum3 <= robot_cam1_P.speedThreshold2_const) {
      robot_cam1_B.Switch1 = robot_cam1_P.Stop1_Value;
      robot_cam1_B.Sum1 = robot_cam1_P.Stop1_Value;
    } else {
      // Sum: '<S9>/Sum3' incorporates:
      //   Trigonometry: '<S9>/Desired Yaw'

      robot_cam1_B.Sum3 = rt_atan2d_snf(robot_cam1_B.Sum1, robot_cam1_B.Sum) -
        robot_cam1_B.sf_Conversion2.yaw;
      robot_cam1_B.Switch1 = rt_atan2d_snf(sin(robot_cam1_B.Sum3), cos
        (robot_cam1_B.Sum3));

      // Fcn: '<S9>/Distance3' incorporates:
      //   Fcn: '<S9>/Bound [-pi,pi]'

      robot_cam1_B.Sum1 *= 5.0;

      // Fcn: '<S9>/Distance2'
      robot_cam1_B.Sum *= 5.0;

      // Fcn: '<S9>/Distance'
      robot_cam1_B.Sum3 = rt_powd_snf(robot_cam1_B.Sum, 2.0) + rt_powd_snf
        (robot_cam1_B.Sum1, 2.0);
      if (robot_cam1_B.Sum3 < 0.0) {
        robot_cam1_B.Sum1 = -sqrt(-robot_cam1_B.Sum3);
      } else {
        robot_cam1_B.Sum1 = sqrt(robot_cam1_B.Sum3);
      }

      // End of Fcn: '<S9>/Distance'
    }

    // End of Switch: '<S9>/Switch1'

    // BusAssignment: '<S5>/Bus Assignment1' incorporates:
    //   Constant: '<S7>/Constant'
    //   Gain: '<S6>/Slider Gain'

    robot_cam1_B.BusAssignment1 = robot_cam1_P.Constant_Value_p;
    robot_cam1_B.BusAssignment1.Linear.X =
      robot_cam1_P.LinearVelocitySlider_gain * robot_cam1_B.Sum1;
    robot_cam1_B.BusAssignment1.Angular.Z = robot_cam1_B.Switch1;

    // Outputs for Atomic SubSystem: '<S5>/Publish2'
    // Start for MATLABSystem: '<S8>/SinkBlock' incorporates:
    //   MATLABSystem: '<S8>/SinkBlock'

    Pub_robot_cam1_75.publish(&robot_cam1_B.BusAssignment1);

    // End of Outputs for SubSystem: '<S5>/Publish2'
  }

  // End of Outputs for SubSystem: '<S3>/Subscribe2'
  // End of Outputs for SubSystem: '<S2>/Proportional Controller'
  // End of Outputs for SubSystem: '<S1>/Command Velocity Publisher'

  // MATLAB Function: '<S3>/Conversion1'
  robot_cam1_Conversion1(robot_cam1_B.In1_d.Pose.Orientation.X,
    robot_cam1_B.In1_d.Pose.Orientation.Y, robot_cam1_B.In1_d.Pose.Orientation.Z,
    robot_cam1_B.In1_d.Pose.Orientation.W, &robot_cam1_B.sf_Conversion1);
}

// Model initialize function
void robot_0ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus((&robot_cam1_M), (NULL));

  // block I/O
  (void) memset(((void *) &robot_cam1_B), 0,
                sizeof(B_robot_cam1_T));

  // states (dwork)
  (void) memset((void *)&robot_cam1_DW, 0,
                sizeof(DW_robot_cam1_T));

  {
    static const char_T tmp[16] = { '/', 'r', 'o', 'b', 'o', 't', '_', '0', '/',
      'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[11] = { '/', 'b', 'o', 't', '_', '1', '/', 'p',
      'o', 's', 'e' };

    static const char_T tmp_1[11] = { '/', 'b', 'o', 't', '_', '0', '/', 'p',
      'o', 's', 'e' };

    char_T tmp_2[17];
    char_T tmp_3[12];
    int32_T i;

    // Start for Atomic SubSystem: '<S3>/Subscribe2'
    // Start for MATLABSystem: '<S14>/SourceBlock'
    robot_cam1_DW.obj_o.isInitialized = 0;
    robot_cam1_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_3[i] = tmp_1[i];
    }

    tmp_3[11] = '\x00';
    Sub_robot_cam1_11.createSubscriber(tmp_3, robot_cam1_MessageQueueLen_l);

    // End of Start for MATLABSystem: '<S14>/SourceBlock'
    // End of Start for SubSystem: '<S3>/Subscribe2'

    // Start for Atomic SubSystem: '<S3>/Subscribe1'
    // Start for MATLABSystem: '<S13>/SourceBlock'
    robot_cam1_DW.obj_n.isInitialized = 0;
    robot_cam1_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[11] = '\x00';
    Sub_robot_cam1_10.createSubscriber(tmp_3, robot_cam1_MessageQueueLen_l);

    // End of Start for MATLABSystem: '<S13>/SourceBlock'
    // End of Start for SubSystem: '<S3>/Subscribe1'

    // Start for Enabled SubSystem: '<S1>/Command Velocity Publisher'
    // Start for Atomic SubSystem: '<S5>/Publish2'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    robot_cam1_DW.obj.isInitialized = 0;
    robot_cam1_DW.obj.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[16] = '\x00';
    Pub_robot_cam1_75.createPublisher(tmp_2, robot_cam1_MessageQueueLen);

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of Start for SubSystem: '<S5>/Publish2'
    // End of Start for SubSystem: '<S1>/Command Velocity Publisher'

    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S16>/Out1'
    robot_cam1_B.In1 = robot_cam1_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S13>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S15>/Out1'
    robot_cam1_B.In1_d = robot_cam1_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S13>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe1'
  }
}

// Model terminate function
void robot_0ModelClass::terminate()
{
  // Terminate for Atomic SubSystem: '<S3>/Subscribe2'
  // Start for MATLABSystem: '<S14>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S14>/SourceBlock'

  if (robot_cam1_DW.obj_o.isInitialized == 1) {
    robot_cam1_DW.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S14>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S3>/Subscribe1'
  // Start for MATLABSystem: '<S13>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S13>/SourceBlock'

  if (robot_cam1_DW.obj_n.isInitialized == 1) {
    robot_cam1_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S13>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe1'

  // Terminate for Enabled SubSystem: '<S1>/Command Velocity Publisher'
  // Terminate for Atomic SubSystem: '<S5>/Publish2'
  // Start for MATLABSystem: '<S8>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SinkBlock'

  if (robot_cam1_DW.obj.isInitialized == 1) {
    robot_cam1_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<S5>/Publish2'
  // End of Terminate for SubSystem: '<S1>/Command Velocity Publisher'
}

// Constructor
robot_0ModelClass::robot_0ModelClass()
{
  static const P_robot_cam1_T robot_cam1_P_temp = {
    0.009,                             // Mask Parameter: speedThreshold2_const
                                       //  Referenced by: '<S10>/Constant'

    0.1,                               // Mask Parameter: LinearVelocitySlider_gain
                                       //  Referenced by: '<S6>/Slider Gain'


    {
      {
        0U,                            // Seq

        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // FrameId

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // FrameId_SL_Info

        {
          0.0,                         // Sec
          0.0                          // Nsec
        }                              // Stamp
      },                               // Header

      {
        {
          0.0,                         // X
          0.0,                         // Y
          0.0                          // Z
        },                             // Position

        {
          0.0,                         // X
          0.0,                         // Y
          0.0,                         // Z
          0.0                          // W
        }                              // Orientation
      }                                // Pose
    },                                 // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S15>/Out1'


    {
      {
        0U,                            // Seq

        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // FrameId

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // FrameId_SL_Info

        {
          0.0,                         // Sec
          0.0                          // Nsec
        }                              // Stamp
      },                               // Header

      {
        {
          0.0,                         // X
          0.0,                         // Y
          0.0                          // Z
        },                             // Position

        {
          0.0,                         // X
          0.0,                         // Y
          0.0,                         // Z
          0.0                          // W
        }                              // Orientation
      }                                // Pose
    },                                 // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S13>/Constant'


    {
      {
        0U,                            // Seq

        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // FrameId

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // FrameId_SL_Info

        {
          0.0,                         // Sec
          0.0                          // Nsec
        }                              // Stamp
      },                               // Header

      {
        {
          0.0,                         // X
          0.0,                         // Y
          0.0                          // Z
        },                             // Position

        {
          0.0,                         // X
          0.0,                         // Y
          0.0,                         // Z
          0.0                          // W
        }                              // Orientation
      }                                // Pose
    },                                 // Computed Parameter: Out1_Y0_p
                                       //  Referenced by: '<S16>/Out1'


    {
      {
        0U,                            // Seq

        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // FrameId

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // FrameId_SL_Info

        {
          0.0,                         // Sec
          0.0                          // Nsec
        }                              // Stamp
      },                               // Header

      {
        {
          0.0,                         // X
          0.0,                         // Y
          0.0                          // Z
        },                             // Position

        {
          0.0,                         // X
          0.0,                         // Y
          0.0,                         // Z
          0.0                          // W
        }                              // Orientation
      }                                // Pose
    },                                 // Computed Parameter: Constant_Value_m
                                       //  Referenced by: '<S14>/Constant'


    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    },                                 // Computed Parameter: Constant_Value_p
                                       //  Referenced by: '<S7>/Constant'

    0.0,                               // Computed Parameter: LinearVelocityv_Y0
                                       //  Referenced by: '<S9>/Linear Velocity (v)'

    0.0,                               // Computed Parameter: AngularVelocityw_Y0
                                       //  Referenced by: '<S9>/Angular Velocity (w)'

    0.0                                // Expression: 0
                                       //  Referenced by: '<S9>/Stop1'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  robot_cam1_P = robot_cam1_P_temp;
}

// Destructor
robot_0ModelClass::~robot_0ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_robot_cam1_T * robot_0ModelClass::getRTM()
{
  return (&robot_cam1_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
