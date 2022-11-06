/// @: Justus Languell <jlanguell@extendable.co>

#include "cmath.h"

static const int TERMS = 30;

static float _sin_taylor_aprox(const float theta)
{
  double term = theta, result = theta;
  const double theta_sq = theta * theta;
  for (int iter = 3; iter < TERMS; iter += 2)
    result += (term *= -theta_sq / iter / (iter - 1));
  return result;
}

int m_sin(const float theta, float* result)
{
  *result = _sin_taylor_aprox(theta);
  if (-1 >= *result || *result >= 1) return 1;
  return 0;
}

int m_cos(const float theta, float* result)
{
  if (m_sin(M_PI_2 - theta, result)) return 1;
  if (-1 >= *result || *result >= 1) return 1;
  return 0;
}

int m_tan(const float theta, float* result)
{
  float r_sin, r_cos;
  if (m_sin(theta, &r_sin)) return 1;
  if (m_cos(theta, &r_cos)) return 1;
  if (r_cos == 0) return 1;
  *result = r_sin / r_cos;
  return 0;
}

int m_csc(const float theta, float* result)
{
  float r_sin;
  if (m_sin(theta, &r_sin)) return 1;
  if (r_sin == 0) return 1;
  *result = 1 / r_sin;
  return 0;
}

int m_sec(const float theta, float* result)
{
  float r_cos;
  if (m_cos(theta, &r_cos)) return 1;
  if (r_cos == 0) return 1;
  *result = 1 / r_cos;
  return 0;
}

int m_cot(const float theta, float* result)
{
  float r_sin, r_cos;
  if (m_sin(theta, &r_sin)) return 1;
  if (m_cos(theta, &r_cos)) return 1;
  if (r_sin == 0) return 1;
  *result = r_cos / r_sin;
  return 0;
}