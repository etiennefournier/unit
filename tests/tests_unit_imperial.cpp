#include <gtest/gtest.h>

#include "../unit_imperial.h"

using namespace unit;
// using namespace std::unit;

TEST(imperial, Construction)
{
    yards y1{1};
    EXPECT_EQ(y1.count(), 1LL);

    auto y2 = yards(2);
    EXPECT_EQ(y2.count(), 2LL);

    const auto y3 = yards{3};
    EXPECT_EQ(y3.count(), 3LL);

    constexpr auto y4 = yards{4};
    EXPECT_EQ(y4.count(), 4LL);
}

TEST(imperial, Literals)
{
    constexpr auto t = 1_thou;
    EXPECT_EQ(t.count(), 1LL);

    constexpr auto i = 2_inch;
    EXPECT_EQ(i.count(), 2LL);

    constexpr auto f = 3_foot;
    EXPECT_EQ(f.count(), 3LL);

    constexpr auto y = 4_yard;
    EXPECT_EQ(y.count(), 4LL);

    constexpr auto c = 5_chain;
    EXPECT_EQ(c.count(), 5LL);

    constexpr auto fur = 6_furlong;
    EXPECT_EQ(fur.count(), 6LL);
    
    constexpr auto m = 7_mile;
    EXPECT_EQ(m.count(), 7LL);

    constexpr auto l = 8_league;
    EXPECT_EQ(l.count(), 8LL);
}

TEST(imperial, Comparisons)
{
    EXPECT_EQ(thous(1000), inches(1));
    EXPECT_EQ(inches(12), feet(1));
    EXPECT_EQ(feet(3), yards(1));
    EXPECT_EQ(yards(22), chains(1));
    EXPECT_EQ(chains(10), furlongs(1));
    EXPECT_EQ(furlongs(8), miles(1));
    EXPECT_EQ(miles(3), leagues(1));
}

TEST(imperial, UnitCasts)
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
