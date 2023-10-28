#include "cmath.h"

static float _sin_taylor_aprox(const float theta)
{
  double term = theta, result = theta;
  const double theta_sq = theta * theta;
  for (int iter = 3; iter < 2 * TAYLOR_ITERS; iter += 2)
    result += (term *= -theta_sq / iter / (iter - 1));
  return result;
}

static float _cos_taylor_aprox(const float theta)
{
  double term = theta, result = theta;
  const double theta_sq = theta * theta;
  for (int iter = 2; iter < 2 * TAYLOR_ITERS; iter += 2)
    result += (term *= -theta_sq / iter / (iter - 1));
  return result;
}

float m_sin(const float theta)
{
  return _sin_taylor_aprox(theta);
}

float m_cos(const float theta)
{
  return _cos_taylor_aprox(theta);
}

float m_tan(const float theta)
{
  return m_sin(theta) / m_cos(theta);
}

float m_csc(const float theta)
{
  return 1. / m_sin(theta);
}

float m_sec(const float theta)
{
  return m_resip(m_cos(theta));
}

float m_cot(const float theta)
{
  return m_cos(theta) / m_sin(theta);
}