/// @: Justus Languell <jlanguell@extendable.co>

#include "cmath.h"

// This is actually a pretty shitty approximate
// Accurate to only ~3 decimals
static double _arcsin_abramowitz_aprox(const double x)
{
  if (x < 0) return -_arcsin_abramowitz_aprox(-x);
  float r_sqrt;
  if (m_sqrt(1 - x, &r_sqrt)) return 1;
  return M_PI_2 - r_sqrt * (1.5707288 - 0.2121144 * x + 0.0742610 * x * x -
                            0.0187293 * x * x * x);
}

static double _arcsin_taylor_approx(const float x) {
  const float x_sq = x * x;
  float term = x, result = x, coef = 1;
  for (float d = 3; d < 2 * TAYLOR_ITERS; d += 2) 
  {
    coef *= (d - 2) / (d - 1);
    term *= x_sq;
    result += coef * (term / d);
  }
  return result;
}

int m_asin(const float ratio, float* result)
{
  if (-1 > ratio || ratio > 1) return 1;
  *result = _arcsin_taylor_approx(ratio);
  return 0;
}

int m_acos(const float ratio, float* result)
{
  float r_asin;
  m_asin(ratio, &r_asin);
  *result = M_PI_2 - r_asin;
  return 0;
}

int m_atan(const float ratio, float* result)
{
  if (ratio == 0) return 1;
  const float radicand = 1. / ((ratio * ratio) + 1);
  float r_sqrt, r_acos, r_signf;
  if (m_sqrt(radicand, &r_sqrt)) return 1;
  if (m_acos(r_sqrt, &r_acos)) return 1;
  if (m_signf(ratio, &r_signf)) return 1;
  *result = r_acos * r_signf;
  return 0;
}