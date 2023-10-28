#include "cmath.h"

static float _arcsin_taylor_approx(const float x) {
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

float m_asin(const float x)
{
  if (-1 > x || x > 1) return M_NAN;
  return _arcsin_taylor_approx(x);
}

float m_acos(const float x)
{
  return M_PI_2 - m_asin(x);
}

float m_atan(const float x)
{
  return m_sign(x) * m_acos(m_sqrt(1. / (1. + (x * x))));
}

// float m_atan2(const float x, const float y)
// {

// }