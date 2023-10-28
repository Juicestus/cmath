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

// Super fast where 0 < x < 1
// Based on Quake 3 fast inverse square root
// and then takes the resiprocol
static float _sqrt_newton_aprox(float x)
{
#define SQRT_NEWTON_ITERS 3
  const float xhalf = 0.5f * x;
  int i = *(int*)&x;
  i = 0x5f3759df - (i >> 1);
  x = *(float*)&i;
  for (int i = 0; i < SQRT_NEWTON_ITERS; i++) x = x * (1.5f - xhalf * x * x);
  return 1 / x;
}

// Accurate where x > 1
static float _sqrt_babylonian_aprox(const float x)
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

float m_exp(const float n)
{
  return _exp_aprox(n);
}

float m_ln(const float x)
{
  if (x < 0) return M_NAN;
  if (x == 0) return M_ASM;
  return _ln_aprox(x);
}

float m_log(const float x, const float base)
{
  if (x <= 0 || base <= 0) return M_NAN;
  if (x == 1) return M_ASM;
  return _ln_aprox(x) / _ln_aprox(base);
}

float m_sqrt(const float x)
{
  if (x < 0) 
    return M_NAN;
  if (x == 1)
    return 1;
  else if (x < 1)
    return _sqrt_newton_aprox(x);
  else
    return _sqrt_babylonian_aprox(x);
}

float m_pow(float a, const float b)
{
  if (a == 0) return 0;
  // const float sign = m_signf(a);

  // I dont really know what/why the bottom rule does
  // if (sign < 0 && (int)(b * 100) % 4 != 0) return 1;
  return _exp_aprox(b * _ln_aprox(a));
  // if (b > 0 && (int)b % 2 == 1) *result *= r_sign;

  if (a < 0)

  return 0;
}