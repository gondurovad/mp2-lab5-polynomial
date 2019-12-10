#include <gtest.h>
#include "polynomial.h"

TEST(Monom, can_create_monom)
{
    ASSERT_NO_THROW(Monom m(9.0, 123));
}

TEST(Monom, cant_create_monom_with_degree_greater_than_nine)
{
    ASSERT_ANY_THROW(Monom m(1.0, 2312));
}


