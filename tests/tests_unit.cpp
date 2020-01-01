#include <gtest/gtest.h>

#include "../unit_metric.h"
#include "../unit_imperial.h"
#include "../unit_metric_conversion.h"

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
