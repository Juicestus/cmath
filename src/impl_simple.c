/// @: Justus Languell <jlanguell@extendable.co>

#include "cmath.h"

int m_absf(float* y, const float x)
{
  union {
    long i;
    float d;
  } u;

  u.d = x;
  u.i &= 0x7FFFFFFF;
  *y = u.d;
  return 0;
}

int m_signf(float* y, const float x)
{
  *y = (x > 0) - (x < 0);
  return 0;
}