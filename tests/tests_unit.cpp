#include <gtest/gtest.h>

#include "../unit_metric.h"
#include "../unit_imperial.h"
#include "../unit_conversion_metric_imperial.h"

using namespace unit;
// using namespace std::unit;

// construction
// comparison
// cast to different units

TEST(unit, SimpleMetricUnitsCreation)
{
    constexpr auto m = meters(1);
    //EXPECT_EQ(m, 1ULL);

    constexpr auto m_literal = 1_m;
    EXPECT_EQ(1_m, m);
    
    constexpr auto mm = unit_cast<millimeters>(m);
    EXPECT_EQ(mm, millimeters(1000));
    EXPECT_EQ(m, millimeters(1000));
}

TEST(unit, MetricComparisons)
{

    constexpr auto um = micrometers(91400);
    constexpr auto mm = millimeters(1000);
    constexpr auto m  = meters(1);
    
    EXPECT_EQ(m, mm);
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

TEST(unit, MetricToImperialComparisons)
{
     EXPECT_EQ(thous(5),  micrometers(127));
     EXPECT_EQ(thous(10), micrometers(254));
}

TEST(unit, UnitCastsMetric)
{
    auto um = micrometers(123456);
    auto nm = unit_cast<nanometers>(um);
    EXPECT_EQ(um, nm);

    auto mm = unit_cast<millimeters>(um);
    EXPECT_EQ(mm.count(), 123);
}

TEST(unit, UnitCastsImperial)
{
    auto y = yards(50);
    auto th = unit_cast<thous>(y); // 1,800,000
    EXPECT_EQ(y, th);

    auto c = unit_cast<chains>(y); // 2
    EXPECT_EQ(c.count(), 2); 
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
