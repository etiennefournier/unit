#include <gtest/gtest.h>

#include "../unit.h"

using namespace unit;
// using namespace std::unit;

struct test_trait{};

TEST(unit, UnitSizeOf)
{
    EXPECT_EQ(sizeof(__unit<long long, test_trait>), sizeof(long long));
    EXPECT_EQ(sizeof(__unit<float, test_trait>), sizeof(float));
}
