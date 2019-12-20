#include <gtest/gtest.h>
#include "../measures.h"
#include "../measures_metric.h"
#include "../measures_imperial.h"

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
