//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: triangle_private.h
//
// Code generated for Simulink model 'triangle'.
//
// Model version                  : 1.229
// Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
// C/C++ source code generated on : Wed Jan  4 17:55:04 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_triangle_private_h_
#define RTW_HEADER_triangle_private_h_
#include "rtwtypes.h"
#include "triangle.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void triangle_Conversion1(real_T rtu_x, real_T rtu_y, real_T rtu_z,
  real_T rtu_w, B_Conversion1_triangle_T *localB);

#endif                                 // RTW_HEADER_triangle_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
