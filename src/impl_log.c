#include "cmath.h"

static float _natural_ln_aprox(const float x, const float n)
{
	const float alpha = (x - 1) / (x + 1), alpha_sq = alpha * alpha;
  float ans = alpha, save = ans * alpha_sq;
	for (int i = 2 ; i <= n; i++) {
    ans += (1. / (2 * i - 1)) * save;
		save *= alpha_sq;
	}
	return ans * 2.;
}

int m_ln(const float x, const float n, float* y)
{
  if (x <= 0) return 1;
  *y = _natural_ln_aprox(x, n);
  return 0;
}