#include "cmath.h"

static const int ITERATIONS = 3;

// Super fast where 0 < x < 1
// Based on Quake 3 fast inverse square root
// and then takes the resiprocol
static float _sqrt_newton_aprox(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int*) &x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*) &i;
    for (int i = 0; i < ITERATIONS; i++)
        x = x * (1.5f - xhalf * x * x);
    return 1 / x;
}

// Accurate where x > 1
float _sqrt_babylonian_aprox(const float x)  
{
  union {
      int i;
      float x;
  } u;

  u.x = x;
  u.i = (1 << 29) + (u.i >> 1) - (1 << 22); 
  u.x = u.x + x/u.x;
  u.x = .25 * u.x + x / u.x;
  return u.x;
}  

int m_sqrtf(const float x, float* y)
{
    if (x < 0) return 1;
    if (x == 1) *y = 1;
    else if (x < 1) *y = _sqrt_newton_aprox(x);
    else *y = _sqrt_babylonian_aprox(x);
    // else {
      // *y = _sqrt_newton_aprox(x) ;
    // }
    return 0;
}