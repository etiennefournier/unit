#include <gtest/gtest.h>
#include "../playground_metric.h"
#include "../playground_imperial.h"
#include "../playground_metric_conversion.h"

using namespace playground;

TEST(Playground, Tests)
{
    metric m(1);
    EXPECT_EQ(m,m);

    imperial i(3);
    EXPECT_EQ(i,i);

    // EXPECT_EQ(i, m);
    EXPECT_EQ(m, i);
}