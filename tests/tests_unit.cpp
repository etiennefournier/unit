#include <gtest/gtest.h>

#include "../unit_metric.h"
#include "../unit_imperial.h"
#include "../unit_conversion_metric_imperial.h"

using namespace unit;
// using namespace std::unit;

// construction
// comparison
// cast to different units

struct test_trait{};

TEST(unit, UnitSizeOf)
{
    EXPECT_EQ(sizeof(__unit<test_trait, long long>), sizeof(long long));
    EXPECT_EQ(sizeof(__unit<test_trait, float>), sizeof(float));
}

TEST(unit, SimpleMetricUnitsCreation)
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

TEST(unit, MetricUnitsLitterals)
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

TEST(unit, MetricComparisons)
{
    EXPECT_EQ(meters(1),  nanometers(1000000000));
    EXPECT_EQ(meters(1), micrometers(1000000));
    EXPECT_EQ(meters(1), millimeters(1000));
    EXPECT_EQ(meters(1), centimeters(100));
    EXPECT_EQ(meters(1), decimeters(10));
    EXPECT_EQ(meters(1), meters(1));

    EXPECT_EQ(nanometers(0), kilometers(0));
}

TEST(unit, ImperialComparisons)
{
    EXPECT_EQ(thous(1000), inches(1));
    EXPECT_EQ(inches(12), feet(1));
    EXPECT_EQ(feet(3), yards(1));
    EXPECT_EQ(yards(22), chains(1));
    EXPECT_EQ(chains(10), furlongs(1));
    EXPECT_EQ(furlongs(8), miles(1));
    EXPECT_EQ(miles(3), leagues(1));
}

TEST(unit, UnitCastsMetric)
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

TEST(unit, UnitCastsImperial)
{
    constexpr auto y = yards(50);
    thous th = y; // 1,800,000
    EXPECT_EQ(th.count(), 1'800'000);

    th = unit_cast<thous>(y);
    EXPECT_EQ(th.count(), 1'800'000);

    // precision loss
    auto c = unit_cast<chains>(y); // 2
    EXPECT_EQ(c.count(), 2); 
}

TEST(unit, MetricToImperialComparisons)
{
     EXPECT_EQ(thous(5),  micrometers(127));
     EXPECT_EQ(thous(10), micrometers(254));
}

TEST(unit, UnitCastMetricToImperial)
{
    auto um = micrometers(127*2);
    auto ts = unit_cast<thous>(um);

    EXPECT_EQ(ts.count(), 5*2);
    EXPECT_EQ(ts, um);
}

TEST(unit, UnitCastImperialToMetric)
{
    auto ts = thous(5*3);
    auto um = unit_cast<micrometers>(ts);

    EXPECT_EQ(um.count(), 127*3);
    EXPECT_EQ(um, ts);
}
