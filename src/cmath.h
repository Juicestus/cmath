/// @: Justus Languell <jlanguell@extendable.co>
/// @: Suhas Guddeti <sguddeti@extendable.co>

#ifndef __CMATH_H__
#define __CMATH_H__

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
    M_SQRT1_2 = 0.707106781186547524401;         // 1/sqrt(2)

// Simple functions (impl_simple.c)
int m_absf(float*, const float);
int m_signf(float*, const float);

// Exponent functions (impl_exp.c)
int m_sqrt(float*, const float);
int m_exp(float*, const float);
int m_ln(float*, const float);
int m_log(float*, const float, const float);
int m_pow(float*, const float, const float);

// Trig functions (impl_trig.c)
int m_sin(float*, const float);
int m_cos(float*, const float);
int m_tan(float*, const float);
int m_csc(float*, const float);
int m_sec(float*, const float);
int m_cot(float*, const float);

// Inverse trig functions (impl_arc.c)
int m_asin(float*, const float);
int m_acos(float*, const float);
int m_atan(float*, const float);

// Stat functions (impl_stat.c)
int m_zscore(float*, const float, const float, const float);
int m_erf(float*, const float);
int m_normal_cdf(float*, const float, const float, const float);
int m_normal_cdf_range(float*, const float, const float, const float, const float);

#endif