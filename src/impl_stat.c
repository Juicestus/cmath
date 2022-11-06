/// @: Suhas Guddeti <sguddeti@extendable.co>

#include "cmath.h"

int m_zscore(const float x, const float mean, const float std, float* result)
{
  if (std == 0) return 1;
  *result = (x - mean) / std;
  return 0;
}

static const double ERF_A1 = 0.254829592, ERF_A2 = -0.284496736,
                    ERF_A3 = 1.421413741, ERF_4 = -1.453152027,
                    ERF_5 = 1.061405429, ERF_P = 0.3275911;

int m_erf(float x, float* result)
{
  double t, y;
  int sign = (x < 0) ? -1 : 1;
  m_absf(x, &x);
  float epow;
  m_pow(M_E, -x * x, &epow);
  t = 1.0 / (1.0 + ERF_P * x);
  y = 1.0 - (((((ERF_5 * t + ERF_4) * t) + ERF_A3) * t + ERF_A2) * t + ERF_A1) *
                t * epow;
  *result = sign * y;
  return 0;
}

int m_normalcdf(const float x, const float mean, const float std,
                float* result) // overload with 3 args or 4? if 3 args then left
                               // is implied mean - (std * 10)
{
  if (std == 0) return 1;
  float err_score;
  m_erf((x - mean) / (std * M_SQRT2), &err_score);
  *result = 0.5 * (1 + err_score);
  return 0;
}

int m_normalcdfrange(const float left, const float right, const float mean,
                     const float std, float* result)
{
  if (std == 0 || left > right) return 1;
  float left_cdf, right_cdf;
  m_normalcdf(left, mean, std, &left_cdf);
  m_normalcdf(right, mean, std, &right_cdf);
  *result = right_cdf - left_cdf;
  return 0;
}