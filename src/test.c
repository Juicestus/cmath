/// @: Justus Languell <jlanguell@extendable.co>
/// @: Suhas Guddeti <sguddeti@extendable.co>

#include "cmath.h"
#include "macros.h"

int main(const int argc, const char** argv)
{
  TEST(0.523598775598, m_asin, 0.5);
  TEST(1.047197551197, m_acos, 0.5);
  TEST(0.463647609001, m_atan, 0.5);

  return 0;
}
