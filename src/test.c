/// @: Justus Languell <jlanguell@extendable.co>
/// @: Suhas Guddeti <sguddeti@extendable.co>

#include "cmath.h"
#include "macros.h"

int main(const int argc, const char** argv)
{
  // F_PRINT_CALL(m_erfc, 0.5);

  F_TEST_CASE(0.523598775598, m_asin, 0.5);
  F_TEST_CASE(1.047197551197, m_acos, 0.5);

  // F_TEST_CASE(.480, m_erfc, .5);
  // F_TEST_CASE(7., m_test, 2., 3.);
  // F_TEST_CASE(ERROR, m_test, 2., 3.);
  // F_TEST_CASE(ERROR, m_test, 2., 2.);

  return 0;
}
