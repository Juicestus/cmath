/// @: Justus Languell <jlanguell@extendable.co>
/// @: Suhas Guddeti <sguddeti@extendable.co>

#include "cmath.h"
#include "test_macros.h"

int main(const int argc, const char** argv)
{
  F_PRINT_CALL(m_normal_cdf_range, 2., 5., 2.5, 0.5);

  F_TEST_CASE(6., m_test, 2., 3.);
  F_TEST_CASE(7., m_test, 2., 3.);
  F_TEST_CASE(ERROR, m_test, 2., 3.);
  F_TEST_CASE(ERROR, m_test, 2., 2.);

  return 0;
}
