#include "cmath.h"

int m_zscore(const float x, const float mean, const float std, float *result)
{
    *result = (std == 0) ? 1 : (x - mean) / std;
    return 0;
}

static float _erf(float x)
{
    float t, y;
    const float a1 = 0.254829592;
    const float a2 = -0.284496736;
    const float a3 = 1.421413741;
    const float a4 = -1.453152027;
    const float a5 = 1.061405429;
    const float p = 0.3275911;

    int sign = (x < 0) ? -1 : 1;
    m_absf(x, &x);
    float epow;
    m_pow(M_E, -x * x, &epow);
    t = 1.0 / (1.0 + p * x);
    y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * epow;
    return sign * y;
}

static float _erfc(const float x) // we don't need this yet
{
    float t, z, ans, epow;
    m_absf(x, &z);
    t = 1.0 / (1.0 + 0.5 * z);
    m_pow(M_E, -z * z - 1.26551223 + t * (1.00002368 + t * (0.37409196 + t * (0.09678418 + t * (-0.18628806 + t * (0.27886807 + t * (-1.13520398 + t * (1.48851587 + t * (-0.82215223 + t * 0.17087277)))))))), &epow);
    ans = t * epow;
    return (x >= 0.0) ? ans : 2.0 - ans;
}

// overload with 3 args or 4? if 3 args then left is implied as -1E99
int m_normalcdf(const float x, const float mean, const float std, float *result) // normalcdf(-1E99, x, mean, std)
{
    *result = (std == 0) ? 1 : 0.5 * (1 + _erf((x - mean) / (std * M_SQRT2)));
    return 0;
}

int m_normalcdfrange(const float left, const float right, const float mean, const float std, float *result) // normalcdf(left, right, mean, std)
{
    if (std == 0 || left > right)
        *result = 1;
    float left_cdf, right_cdf;
    m_normalcdf(left, mean, std, &left_cdf);
    m_normalcdf(right, mean, std, &right_cdf);
    *result = right_cdf - left_cdf;
    return 0;
}

static float _inverse_dist_approx(const float t)
{
    const float c0 = 2.515517;
    const float c1 = 0.802853;
    const float c2 = 0.010328;
    const float d0 = 1.432788;
    const float d1 = 0.189269;
    const float d2 = 0.001308;
    return t - ((c2 * t + c1) * t + c0) / (((d2 * t + d1) * t + d0) * t + 1.0);
}

// invnorm with percentile argument, later add generic invnorm and delete this
int m_invnormalcdf_p(const float p, float *result) // invnorm(x, 0, 1, LEFT)
{
    if (p < 0.0 || p > 1.0)
        *result = 0;
    float neg_p, log_p, pos_p, log_1p;
    m_log(p, M_E, &neg_p);
    m_sqrt(-2. * neg_p, &log_p);
    m_log(1.0 - p, M_E, &pos_p);
    m_sqrt(-2. * pos_p, &log_1p);
    *result = (p < 0.5) ? -_inverse_dist_approx(log_p) : _inverse_dist_approx(log_1p);
    return 0;
}