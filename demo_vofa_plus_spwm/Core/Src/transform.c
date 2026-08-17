#include "transform.h"
#include <math.h>

/* 逆 Park 变换: d,q → α,β
 * |α|   |cosθ  -sinθ| |d|
 * |β| = |sinθ   cosθ| |q|
 */
void ipark(float d, float q, float theta, float *alpha, float *beta)
{
    float sin_val = sinf(theta);
    float cos_val = cosf(theta);

    *alpha = d * cos_val - q * sin_val;
    *beta  = d * sin_val + q * cos_val;
}

/* 逆 Clarke 变换: α,β → a,b,c
 * a = α
 * b = -α/2 + √3/2 * β
 * c = -α/2 - √3/2 * β
 */
void iclarke(float alpha, float beta, float *a, float *b, float *c)
{
    *a = alpha;
    *b = -0.5f * alpha + SQRT3_OVER_2 * beta;
    *c = -0.5f * alpha - SQRT3_OVER_2 * beta;
}

/* 逆 Park + 逆 Clarke 组合变换: d,q,θ → a,b,c */
void ipark_clarke(float d, float q, float theta, float *a, float *b, float *c)
{
    float alpha, beta;
    ipark(d, q, theta, &alpha, &beta);
    iclarke(alpha, beta, a, b, c);
}