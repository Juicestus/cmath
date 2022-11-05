#include "cmath.h"

int m_zscore(const float x, const float mean, const float std, float *result)
{
    if (std == 0)
        return 1;
    *result = (x - mean) / std;
    return 0;
}

int m_erf(float x, float *result)
{
    double t, y;
    double a1 = 0.254829592;
    double a2 = -0.284496736;
    double a3 = 1.421413741;
    double a4 = -1.453152027;
    double a5 = 1.061405429;
    double p = 0.3275911;

    int sign = (x < 0) ? -1 : 1;
    m_absf(x, &x);
    float epow;
    m_pow(M_E, -x * x, &epow);
    t = 1.0 / (1.0 + p * x);
    y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * epow;
    *result = sign * y;
    return 0;
}

int m_normalcdf(const float x, const float mean, const float std, float *result) // overload with 3 args or 4? if 3 args then left is implied mean - (std * 10)
{
    if (std == 0)
        return 1;
    float err_score;
    m_erf((x - mean) / (std * M_SQRT2), &err_score);
    *result = 0.5 * (1 + err_score);
    return 0;
}

int m_normalcdfrange(const float left, const float right, const float mean, const float std, float *result)
{
    if (std == 0 || left > right)
        return 1;
    float left_cdf, right_cdf;
    m_normalcdf(left, mean, std, &left_cdf);
    m_normalcdf(right, mean, std, &right_cdf);
    *result = right_cdf - left_cdf;
    return 0;
}