#include <gtest/gtest.h>

#include "../unit_conversion_metric_imperial.h"

using namespace unit;
// using namespace std::unit;

TEST(metric_to_imperial, Comparisons)
{
     EXPECT_EQ(thous(5),  micrometers(127));
     EXPECT_EQ(thous(10), micrometers(254));
}

TEST(metric_to_imperial, UnitCasts)
{
    auto um = micrometers(127*2);
    auto ts = unit_cast<thous>(um);

    EXPECT_EQ(ts.count(), 5*2);
    EXPECT_EQ(ts, um);

    ts = thous(5*3);
    um = unit_cast<micrometers>(ts);

    EXPECT_EQ(um.count(), 127*3);
    EXPECT_EQ(um, ts);
}
