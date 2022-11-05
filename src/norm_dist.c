#include "cmath.h"

int m_zscore(const float x, const float mean, const float std, float *result)
{
    if (std == 0)
        return 1;
    *result = (x - mean) / std;
    return 0;
}

int m_erf(const float x, float *result)
{
    if (x == 0)
        return 1;
    float tTerm, fTerm, sTerm, nTerm;
    m_pow(x, 3.0, &tTerm);
    m_pow(x, 5.0, &fTerm);
    m_pow(x, 7.0, &sTerm);
    m_pow(x, 9.0, &nTerm);
    *result = (2 / M_PI) * (x - tTerm / 3) + (fTerm / 10) - (sTerm / 42) + (nTerm / 216);
    return 0;
}

int m_normalcdf(const float left, const float right, const float mean, const float std, float *result)
{
    if (std == 0)
        return 1;
    float zLeft, zRight;
    m_zscore(left, mean, std, &zLeft);
    m_zscore(right, mean, std, &zRight);
    float erfLeft, erfRight;
    m_erf(zLeft / M_SQRT2, &erfLeft);
    m_erf(zRight / M_SQRT2, &erfRight);
    *result = (erfRight - erfLeft) / 2;
    return 0;
}