/// @: Suhas Guddeti <sguddeti@extendable.co>

#include "cmath.h"

int m_zscore(const float x, const float mean, const float std, float* result)
{
  if (std == 0) return 1;
  *result = (x - mean) / std;
  return 0;
}

static const double ERF_A1 = 0.254829592, ERF_A2 = -0.284496736,
                    ERF_A3 = 1.421413741, ERF_A4 = -1.453152027,
                    ERF_A5 = 1.061405429, ERF_P = 0.3275911;

static float _erf(float x)
{
  int sign = (x < 0) ? -1 : 1;
  m_absf(x, &x);
  float epow;
  m_pow(M_E, -x * x, &epow);
  const float t = 1.0 / (1.0 + ERF_P * x);
  const float y =
      1.0 -
      (((((ERF_A5 * t + ERF_A4) * t) + ERF_A3) * t + ERF_A2) * t + ERF_A1) * t *
          epow;
  return sign * y;
}

int m_erf(float x, float* result)
{
  *result = _erf(x);
  return 0;
}

static const double ERFC_A1 = 1.26551223, ERFC_A2 = 1.00002368,
                    ERFC_A3 = 0.37409196, ERFC_A4 = 0.09678418,
                    ERFC_A5 = -0.18628806, ERFC_A6 = 0.27886807,
                    ERFC_A7 = -1.13520398, ERFC_A8 = 1.48851587,
                    ERFC_A9 = -0.82215223, ERFC_A10 = 0.17087277;

static float _erfc(const float x) // we don't need this yet
{
  float t, z, ans, epow;
  m_absf(x, &z);
  t = 1.0 / (1.0 + 0.5 * z);
  m_pow(M_E,
        -z * z - ERFC_A1 +
            t * (ERFC_A2 +
                 t * (ERFC_A3 +
                      t * (ERFC_A4 +
                           t * (ERFC_A5 +
                                t * (ERFC_A6 +
                                     t * (ERFC_A7 +
                                          t * (ERFC_A8 +
                                               t * (ERFC_A9 +
                                                    t * ERFC_A10)))))))),
        &epow);

  ans = t * epow;
  return (x >= 0.0) ? ans : 2.0 - ans;
}

// overload with 3 args or 4? if 3 args then left is implied as -1E99
int m_normal_cdf(const float x, const float mean, const float std,
                 float* result) // normalcdf(-1E99, x, mean, std)
{
  *result = (std == 0) ? 1 : 0.5 * (1 + _erf((x - mean) / (std * M_SQRT2)));
  return 0;
}

int m_normal_cdf_range(const float left, const float right, const float mean,
                       const float std, float* result)
{
  if (std == 0 || left > right) return 1;
  float left_cdf, right_cdf;
  m_normal_cdf(left, mean, std, &left_cdf);
  m_normal_cdf(right, mean, std, &right_cdf);
  *result = right_cdf - left_cdf;
  return 0;
}

static const float IDP_C0 = 2.515517, IDP_C1 = 0.802853, IDP_C2 = 0.010328,
                   IDP_D0 = 1.432788, IDP_D1 = 0.189269, IDP_D2 = 0.001308;

static float _inverse_dist_approx(const float t)
{
  return t - ((IDP_C2 * t + IDP_C1) * t + IDP_C0) /
                 (((IDP_D2 * t + IDP_D1) * t + IDP_D0) * t + 1.0);
}

// invnorm with percentile argument, later add generic invnorm and delete this
int m_inv_normal_cdf_p(const float p, float* result) // invnorm(x, 0, 1, LEFT)
{
  if (p < 0.0 || p > 1.0) *result = 0;
  float neg_p, log_p, pos_p, log_1p;
  m_log(p, M_E, &neg_p);
  m_sqrt(-2. * neg_p, &log_p);
  m_log(1.0 - p, M_E, &pos_p);
  m_sqrt(-2. * pos_p, &log_1p);
  *result =
      (p < 0.5) ? -_inverse_dist_approx(log_p) : _inverse_dist_approx(log_1p);
  return 0;
}

int m_normal_pdf(const float z, float* result)
{
  float epow;
  m_pow(M_E, -0.5 * z * z, &epow);
  *result = 1.0 / (M_SQRT2PI * epow);
  return 0;
}