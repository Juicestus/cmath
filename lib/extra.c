/// @: Justus Languell <jlanguell@extendable.co>

#include "cmath.h"

bool m_isnan(const float x) 
{
  return x != x;
}

bool m_isposinf(const float x) 
{
  return x == M_INF;
}
bool m_isneginf(const float x) 
{
  return x == -M_INF;
}

bool m_isinf(const float x) 
{
  return m_isposinf(x) || m_isneginf(x);
}

float m_resip(const float x) 
{
  return 1. / x;
}

float m_abs(const float x)
{
  union {
    long i;
    float d;
  } u;

  u.d = x;
  u.i &= 0x7FFFFFFF;
  return u.d;
}

float m_sign(const float x)
{
  return (x > 0) - (x < 0);
}

float m_floor(const float x)
{
  return (int)(x + M_ABS_INT_MIN) + M_ABS_INT_MIN;
}

float m_ciel(const float x)
{
  return M_ABS_INT_MIN - (int)(M_ABS_INT_MIN - x);
}

float m_trunc(const float x) 
{
  return x > 0 ? m_floor(x) : m_ciel(x);
}

float m_fmod(const float x, const float y) 
{
  return x - m_trunc(x / y) * y;
}
