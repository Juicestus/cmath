#include "cmath.h"

float m_zscore(const float x, const float mean, const float std)
{
  if (std == 0) return M_NAN;
  return (x - mean) / std;
}

static const float ERF_A1 = 0.254829592, ERF_A2 = -0.284496736,
                   ERF_A3 = 1.421413741, ERF_A4 = -1.453152027,
                   ERF_A5 = 1.061405429, ERF_P = 0.3275911;

// @suhas what is the accuracy of the polynomial approx?
static float _erf_poly_approx(float x)
{
  int sign = (x < 0) ? -1 : 1;
  x = m_abs(x);
  const float r_pow = m_pow(M_E, -x * x);
  const float t = 1.0 / (1.0 + ERF_P * x);
  const float y =
      1.0 -
      (((((ERF_A5 * t + ERF_A4) * t) + ERF_A3) * t + ERF_A2) * t + ERF_A1) * t *
          r_pow;
  return sign * y;
}

float m_erf(float x)
{
  return _erf_poly_approx(x);
}

static const float ERFC_CONSTS[] = {
    1.26551223, 1.00002368,  0.37409196, 0.09678418,  -0.18628806,
    0.27886807, -1.13520398, 1.48851587, -0.82215223, 0.17087277};

static float _erfc_poly_approx(const float x)
{
  const float r_z = m_abs(x);
  const float t_coef = 1. / (1. + .5 * r_z);

  float exponent = 0;
  for (int i = (sizeof(ERFC_CONSTS) / sizeof(float)) - 1; i >= 1; i--)
    exponent = (exponent + ERFC_CONSTS[i]) * t_coef;
  exponent = -r_z * r_z - ERFC_CONSTS[0] + exponent;

  const float r_pow = m_pow(M_E, exponent);
  const float result = t_coef * r_pow;
  return x >= 0. ? result : 2. - result;
}

float m_erfc(float x)
{
  return _erfc_poly_approx(x);
}

// overload with 3 args or 4? if 3 args then left is implied as -1E99
float m_normal_cdf(const float x, const float mean, const float std) // normalcdf(-1E99, x, mean, std)
{
  return (std == 0) ? 1 : 0.5 * (1 + m_erf((x - mean) / (std * M_SQRT2)));
}

float m_normal_cdf_range(const float left, const float right, const float mean,
                       const float std)
{
  if (std == 0 || left > right) return 1;
  const float r_left_cdf = m_normal_cdf(left, mean, std);
  const float r_right_cdf = m_normal_cdf(right, mean, std);
  return r_right_cdf - r_left_cdf;
}

static const float IDP_C0 = 2.515517, IDP_C1 = 0.802853, IDP_C2 = 0.010328,
                   IDP_D0 = 1.432788, IDP_D1 = 0.189269, IDP_D2 = 0.001308;

static float _inverse_dist_approx(const float t)
{
  return t - ((IDP_C2 * t + IDP_C1) * t + IDP_C0) /
                 (((IDP_D2 * t + IDP_D1) * t + IDP_D0) * t + 1.0);
}

float m_inv_normal_cdf_p(const float p)
{
  if (p < 0.0 || p > 1.0) return 1;
  const float r_log = m_log(p < .5 ? p : 1. - p, M_E);
  const float r_sqrt = m_sqrt(-2. * r_log);
  return -_inverse_dist_approx(r_sqrt);
}

float m_inv_normal_cdf(const float p, const float mean, const float std)
{
  if (std == 0 || p >= 1) return 1;
  const float r_inv_p = m_inv_normal_cdf_p(p);
  return mean + std * r_inv_p;
}

float m_normal_pdf(const float z, const float mean, const float std)
{
  const float a = (z - mean) / std;
  const float r_pow = m_pow(M_E, -0.5f * a * a);
  return M_1_SQRT_2PI / std * r_pow;
}

float m_geometric_pdf(const float p, const int k)
{
  if (p <= 0 || p >= 1 || k < 0) return 1;
  const float r_pow = m_pow(1 - p, k - 1);
  return p * r_pow;
}
