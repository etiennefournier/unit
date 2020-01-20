#include <gtest/gtest.h>

#include "../unit_metric.h"
#include "../unit_chrono.h"
#include "../unit_speed.h"

using namespace unit;
using namespace unit::chrono;
// using namespace std::unit;

TEST(speed, Creation)
{
    constexpr auto distance = meters(1);
    constexpr auto time = seconds(1);

    auto speed = distance / time;
    
    EXPECT_EQ(speed.count(), 0);
    EXPECT_EQ(speed, meters_per_seconds(1));
}
