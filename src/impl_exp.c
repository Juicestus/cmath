/// @: Justus Languell <jlanguell@extendable.co>

#include "cmath.h"

static const float SMOL = 1e-6;

static float _exp_aprox(float n)
{
  int a = 0, b = n > 0;
  float c = 1, d = 1, e = 1;
  for (b || (n = -n); e + SMOL < (e += (d *= n) / (c *= ++a));)
    ;
  return b ? e : 1 / e;
}

static float _ln_aprox(const float n)
{
  unsigned int a = 0, d;
  float b, c, e, f;
  if (n > 0) {
    for (c = n < 1 ? 1 / n : n; (c /= M_E) > 1; ++a)
      ;
    c = 1 / (c * M_E - 1), c = c + c + 1, f = c * c, b = 0;
    for (d = 1, c /= 2; e = b, b += 1 / (d * c), b - e /* > SMOL */;)
      d += 2, c *= f;
  }
  else
    b = (n == 0) / 0.;
  return n < 1 ? -(a + b) : a + b;
}

static const int ITERATIONS = 3;

// Super fast where 0 < x < 1
// Based on Quake 3 fast inverse square root
// and then takes the resiprocol
static float _sqrt_newton_aprox(float x)
{
  const float xhalf = 0.5f * x;
  int i = *(int*)&x;
  i = 0x5f3759df - (i >> 1);
  x = *(float*)&i;
  for (int i = 0; i < ITERATIONS; i++) x = x * (1.5f - xhalf * x * x);
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
  u.x = u.x + x / u.x;
  u.x = .25 * u.x + x / u.x;
  return u.x;
}

int m_exp(const float n, float* result)
{
  *result = _exp_aprox(n);
  return 0;
}

int m_ln(const float x, float* y)
{
  if (x <= 0) return 1;
  *y = _ln_aprox(x);
  return 0;
}

int m_log(const float x, const float base, float* y)
{
  if (x <= 0) return 1;
  *y = _ln_aprox(x) / _ln_aprox(base);
  return 0;
}

int m_sqrt(const float x, float* y)
{
  if (x < 0) return 1;
  if (x == 1)
    *y = 1;
  else if (x < 1)
    *y = _sqrt_newton_aprox(x);
  else
    *y = _sqrt_babylonian_aprox(x);
  // else {
  // *y = _sqrt_newton_aprox(x) ;
  // }
  return 0;
}

int m_pow(float a, const float b, float* result)
{
  float r_sign;
  m_signf(a, &r_sign);
  // I dont really know what/why the bottom rule does
  if (r_sign < 0 && (int)(b * 100) % 4 != 0) return 1;
  *result = _exp_aprox(b * _ln_aprox(a * r_sign));
  if (b > 0 && (int)b % 2 == 1) *result *= r_sign;
  return 0;
}