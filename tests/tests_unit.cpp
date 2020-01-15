#include <gtest/gtest.h>

#include "../unit.h"

using namespace unit;
// using namespace std::unit;

struct test_trait{};

TEST(unit, UnitSizeOf)
{
    EXPECT_EQ(sizeof(__unit<test_trait, long long>), sizeof(long long));
    EXPECT_EQ(sizeof(__unit<test_trait, float>), sizeof(float));
}
