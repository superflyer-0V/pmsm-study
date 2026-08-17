#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "main.h"

/* sqrt(3) / 2 */
#define SQRT3_OVER_2 0.8660254037844386f

/* 逆 Park 变换: d,q → α,β */
void ipark(float d, float q, float theta, float *alpha, float *beta);

/* 逆 Clarke 变换: α,β → a,b,c */
void iclarke(float alpha, float beta, float *a, float *b, float *c);

/* 逆 Park + 逆 Clarke 组合变换: d,q,θ → a,b,c */
void ipark_clarke(float d, float q, float theta, float *a, float *b, float *c);

#endif