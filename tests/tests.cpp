#include <gtest/gtest.h>
#include "../measures.h"
#include "../measures_metric.h"
#include "../measures_imperial.h"
#include "../measures_metric_conversion.h"

using namespace measures;
using namespace measures::metric;
using namespace measures::imperial;

// construction
// comparison
// cast to different units

TEST(measures, SimpleMetricUnitsCreation)
{
    constexpr auto m = meters(1);
    //EXPECT_EQ(m, 1ULL);

    constexpr auto m_literal = 1_m;
    EXPECT_EQ(1_m, m);
    
    constexpr auto mm = distance_cast<millimeters>(m);
    EXPECT_EQ(mm, millimeters(1000));
}

TEST(measures, MetricComparisons)
{

    constexpr auto um = micrometers(91400);
    constexpr auto mm = millimeters(1000);
    constexpr auto m  = meters(1);
    
    EXPECT_EQ(m, mm);
}

TEST(measures, MetricArithmetic)
{
    auto m = meters(1);
    auto m2 = ++m;
    EXPECT_EQ(meters(1) + meters(1), meters(2));
    EXPECT_EQ(meters(10) - meters(5), meters(5));
    // EXPECT_EQ(meters(10) * meters(5), meters(50));
    // EXPECT_EQ(meters(10) / meters(5), meters(2));
    EXPECT_EQ(m2, meters(2));
    // EXPECT_EQ(++m, 2);
    // EXPECT_EQ(--m, 1);
    // EXPECT_EQ(m+=10, 11);
    // EXPECT_EQ(m-=m2, 9);
}

TEST(measures, ImperialComparisons)
{
    EXPECT_EQ(thous(1000), inches(1));
    EXPECT_EQ(inches(12), feet(1));
    EXPECT_EQ(feet(3), yards(1));
    EXPECT_EQ(yards(22), chains(1));
    EXPECT_EQ(chains(10), furlongs(1));
    EXPECT_EQ(furlongs(8), miles(1));
    EXPECT_EQ(miles(3), leagues(1));
}

TEST(measures, MetricToImperialComparisons)
{
     EXPECT_EQ(thous(5),  micrometers(127));
     EXPECT_EQ(thous(10), micrometers(254));
}
