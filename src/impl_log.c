#include "cmath.h"

static const float SMOL = 1e-6;

static float _exp_aprox(float n)
{
  int a = 0, b = n > 0;
  float c = 1, d = 1, e = 1;
  for (b || (n = -n); e + SMOL < (e += (d *= n) / (c *= ++a)););
  return b ? e : 1 / e;
}

static float _ln_aprox(const float n)
{
  unsigned int a = 0, d;
  float b, c, e, f;
  if (n > 0) {
    for (c = n < 1 ? 1 / n : n; (c /= M_E) > 1; ++a);
    c = 1 / (c * M_E - 1), c = c + c + 1, f = c * c, b = 0;
    for (d = 1, c /= 2; e = b, b += 1 / (d * c), b - e /* > SMOL */;)
      d += 2, c *= f;
  } else b = (n == 0) / 0.;
  return n < 1 ? -(a + b) : a + b;
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