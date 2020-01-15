#include <gtest/gtest.h>

#include "../unit_metric.h"

using namespace unit;
// using namespace std::unit;

TEST(metric, Creation)
{
    meters m1{1};
    EXPECT_EQ(m1.count(), 1LL);

    auto m2 = meters(2);
    EXPECT_EQ(m2.count(), 2LL);

    const auto m3 = meters{3};
    EXPECT_EQ(m3.count(), 3LL);

    constexpr auto m4 = meters{4};
    EXPECT_EQ(m4.count(), 4LL);
}

TEST(metric, Literals)
{
    constexpr auto nm = 1_nm;
    EXPECT_EQ(nm.count(), 1LL);
    
    constexpr auto um = 2_um;
    EXPECT_EQ(um.count(), 2LL);

    const auto mm = 3_mm;
    EXPECT_EQ(mm.count(), 3LL);

    auto cm = 4_cm;
    EXPECT_EQ(cm.count(), 4LL);

    auto dm = 5_dm;
    EXPECT_EQ(dm.count(), 5LL);

    meters m = 6_m;
    EXPECT_EQ(m.count(), 6LL);
}

TEST(metric, Comparisons)
{
    EXPECT_EQ(meters(1),  nanometers(1000000000));
    EXPECT_EQ(meters(1), micrometers(1000000));
    EXPECT_EQ(meters(1), millimeters(1000));
    EXPECT_EQ(meters(1), centimeters(100));
    EXPECT_EQ(meters(1), decimeters(10));
    EXPECT_EQ(meters(1), meters(1));

    EXPECT_EQ(nanometers(0), kilometers(0));
}

TEST(metric, UnitCasts)
{
    constexpr auto um = micrometers(123456);

    nanometers nm = um;
    EXPECT_EQ(nm.count(), 123456000);

    nm = unit_cast<nanometers>(um);
    EXPECT_EQ(nm.count(), 123456000);

    // precision loss
    constexpr auto mm = unit_cast<millimeters>(um);
    EXPECT_EQ(mm.count(), 123);
}
