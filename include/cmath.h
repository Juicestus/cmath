/// @: Justus Languell <jlanguell@extendable.co>
/// @: Suhas Guddeti <sguddeti@extendable.co>

#ifndef __CMATH_H__
#define __CMATH_H__

#define TAYLOR_ITERS 200
#define M_NAN (0. / 0.)
#define M_INF (1. / 0.)
#define M_POS_INF M_INF
#define M_NEG_INF -M_INF
#define M_ASM M_INF

static const float M_E = 2.71828182845904523536, // e
    M_LOG2E = 1.44269504088896340736,            // log2(e)
    M_LOG10E = 0.434294481903251827651,          // log10(e)
    M_LN2 = 0.693147180559945309417,             // ln(2)
    M_LN10 = 2.30258509299404568402,             // ln(10)
    M_PI = 3.14159265358979323846,               // pi
    M_PI_2 = 1.57079632679489661923,             // pi/2
    M_PI_4 = 0.785398163397448309616,            // pi/4
    M_1_PI = 0.318309886183790671538,            // 2/pi
    M_2_PI = 0.636619772367581343076,            // 2/pi
    M_2_SQRTPI = 1.12837916709551257390,         // 2/sqrt(pi)
    M_SQRT2 = 1.41421356237309504880,            // sqrt(2)
    M_1_SQRT_2 = 0.707106781186547524401,        // 1/sqrt(2)
    M_1_SQRT_2PI = 0.3989422804014327;           // 1/sqrt(2 pi)

static const float M_FLOAT_MIN = 1.175494e-38;
static const float M_FLOAT_MAX = 3.402823e+38;
static const float M_ABS_INT_MIN = 2147483648.0;
static const int M_INT_MIN = -2147483648;
static const int M_INT_MAX = 2147483647;

typedef unsigned short bool;

// Simple functions (simple.c)
bool m_isnan(const float);
bool m_isinf(const float);
bool m_isposinf(const float);
bool m_isneginf(const float);
float m_resip(const float);
float m_abs(const float);
float m_sign(const float);
float m_floor(const float);
float m_ciel(const float);
float m_trunc(const float);
float m_fmod(const float, const float);

// Exponent functions (exp.c)
float m_sqrt(const float);
float m_exp(const float);
float m_ln(const float);
float m_log(const float, const float);
float m_pow(const float, const float);

// Trig functions (trig.c)
float m_sin(const float);
float m_cos(const float);
float m_tan(const float);
float m_csc(const float);
float m_sec(const float);
float m_cot(const float);

// Inverse trig functions (arctrig.c)
float m_asin(const float);
float m_acos(const float);
float m_atan(const float);

// Statistics functions (stats.c)
// int m_zscore(const float, const float, const float, float*);
// int m_normal_cdf(const float, const float, const float, float*);
// int m_normal_cdf_range(const float, const float, const float, const float,
//                        float*);
// int m_inv_normal_cdf_p(const float, float*);
// int m_inv_normal_cdf(const float, const float, const float, float*);
// int m_normal_pdf(const float z, const float mean, const float std,
//                  float* result);
// int m_geometric_pdf(const float, const int, float*);
// int m_erfc(float, float*);

#endif