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

#include <chrono>

TEST(chrono, TestChrono)
{
    constexpr auto m = std::chrono::minutes(60);
    constexpr auto h = std::chrono::hours(1);
    EXPECT_EQ(m, h);
}