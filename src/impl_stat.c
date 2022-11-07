/// @: Suhas Guddeti <sguddeti@extendable.co>

#include "cmath.h"

int m_zscore(float* result, const float x, const float mean, const float std)
{
  if (std == 0) return 1;
  *result = (x - mean) / std;
  return 0;
}

static const double ERF_A1 = 0.254829592, ERF_A2 = -0.284496736,
                    ERF_A3 = 1.421413741, ERF_4 = -1.453152027,
                    ERF_5 = 1.061405429, ERF_P = 0.3275911;

int m_erf(float* result, float x)
{
  double t, y;
  int sign = (x < 0) ? -1 : 1; // use signf retard
  m_absf(&x, x);
  float e_pow;
  m_pow(&e_pow, M_E, -x * x);
  t = 1. / (1. + ERF_P * x);
  y = 1. - (((((ERF_5 * t + ERF_4) * t) + ERF_A3) * t + ERF_A2) * t + ERF_A1) *
                t * e_pow;
  *result = sign * y;
  return 0;
}

// overload with 3 args or 4? if 3 args then left
// is implied mean - (std * 10)
// ^ cant overload in C - jus
int m_normal_cdf(float* result, const float x, const float mean, const float std) 
{
  if (std == 0) return 1;
  float err_score;
  m_erf(&err_score, (x - mean) / (std * M_SQRT2));
  *result = .5 * (1 + err_score);
  return 0;
}

int m_normal_cdf_range(float* result, const float left, const float right, const float mean,
                     const float std)
{
  if (std == 0 || left > right) return 1;
  float left_cdf, right_cdf;
  m_normalcdf(&left_cdf, mean, std);
  m_normalcdf(&right_cdf, mean, std);
  *result = right_cdf - left_cdf;
  return 0;
}