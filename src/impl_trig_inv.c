#include "cmath.h"

// This is actually a pretty shitty approximate
static double _arcsin_abramowitz_aprox(const double x)
{
    if (x < 0) return -_arcsin_abramowitz_aprox(-x);
    float r_sqrt;
    if (m_sqrtf(1 - x, &r_sqrt)) return 1;
    return M_PI_2 - r_sqrt * (1.5707288 - 0.2121144 * x + 0.0742610 * x * x - 0.0187293 * x * x * x);
}

int m_asin(const float ratio, float* result)
{
    if (-1 > ratio || ratio > 1) return 1; 
    *result = _arcsin_abramowitz_aprox(ratio);
    return 0;
}

int m_acos(const float ratio, float* result)
{
    float r_asin;
    m_asin(ratio, &r_asin);
    *result = M_PI_2 - r_asin;
    return 0;
}