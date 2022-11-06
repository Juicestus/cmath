#ifndef CMATH_H_
#define CMATH_H_

static const float
	M_E = 2.71828182845904523536,		 // e
	M_LOG2E = 1.44269504088896340736,	 // log2(e)
	M_LOG10E = 0.434294481903251827651,	 // log10(e)
	M_LN2 = 0.693147180559945309417,	 // ln(2)
	M_LN10 = 2.30258509299404568402,	 // ln(10)
	M_PI = 3.14159265358979323846,		 // pi
	M_PI_2 = 1.57079632679489661923,	 // pi/2
	M_PI_4 = 0.785398163397448309616,	 // pi/4
	M_1_PI = 0.318309886183790671538,	 // 2/pi
	M_2_PI = 0.636619772367581343076,	 // 2/pi
	M_2_SQRTPI = 1.12837916709551257390, // 2/sqrt(pi)
	M_SQRT2 = 1.41421356237309504880,	 // sqrt(2)
	M_SQRT1_2 = 0.707106781186547524401; // 1/sqrt(2)

// Simple functions (impl_simple.c)
int m_absf(const float, float *);
int m_signf(const float, float *);

// Exponent functions (impl_exp.c)
int m_sqrt(const float, float *);
int m_exp(const float, float *);
int m_ln(const float, float *);
int m_log(const float, const float, float *);
int m_pow(const float, const float, float *);

// Trig functions (impl_trig.c)
int m_sin(const float, float *);
int m_cos(const float, float *);
int m_tan(const float, float *);
int m_csc(const float, float *);
int m_sec(const float, float *);
int m_cot(const float, float *);

// Inverse trig functions (impl_arc.c)
int m_asin(const float, float *);
int m_acos(const float, float *);
int m_atan(const float, float *);

// Normal Distribution functions (norm_dist.c)
int m_zscore(const float, const float, const float, float *);
int m_erf(const float, float *);
int m_normalcdf(const float, const float, const float, float *);
int m_normalcdfrange(const float, const float, const float, const float, float *);

#endif