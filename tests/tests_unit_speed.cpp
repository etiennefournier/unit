#include <gtest/gtest.h>

#include "../unit_metric.h"
#include "../unit_chrono.h"
#include "../unit_speed.h"

using namespace unit;
using namespace unit::chrono;
// using namespace std::unit;

TEST(speed, Construction)
{
    meters_per_seconds m1{1};
    EXPECT_EQ(m1.count(), 1LL);

    auto m2 = meters_per_seconds(2);
    EXPECT_EQ(m2.count(), 2LL);

    const auto m3 = meters_per_seconds{3};
    EXPECT_EQ(m3.count(), 3LL);

    constexpr auto m4 = meters_per_seconds{4};
    EXPECT_EQ(m4.count(), 4LL);
}

TEST(speed, TypeDeduction)
{
    meters_per_seconds m1 = meters{2} / seconds{2};
    EXPECT_EQ(m1.count(), 1LL);

    auto m2 = millimeters{2000} / milliseconds{2000};
    EXPECT_EQ(m2.count(), 1LL);

    const auto m3 = nanometers{200'000'000} / minutes{2};
    EXPECT_EQ(m3.count(), 100'000'000LL);

    constexpr auto m4 = kilometers{120} / hours{1};
    EXPECT_EQ(m4.count(), 120LL);
}

TEST(speed, Literals)
{
    constexpr auto km_h = 1_km_h;
    EXPECT_EQ(km_h.count(), 1LL);
}

TEST(speed, Comparisons)
{
    EXPECT_EQ(meters_per_minutes{60},  meters_per_seconds{1});
    EXPECT_EQ(meters{60} / minutes{1}, meters{1} / seconds{1});
    
    EXPECT_EQ(nanometers_per_milliseconds{100'000'000}, decimeters_per_seconds{1000});
    EXPECT_EQ(kilometers_per_hours{120}, meters_per_minutes{2000});
}

TEST(speed, UnitCasts)
{
    constexpr auto m_m = meters_per_minutes{1980};

    meters_per_seconds m_s = m_m;
    EXPECT_EQ(m_s.count(), 33LL);

    m_s = unit_cast<meters_per_seconds>(m_m);
    EXPECT_EQ(m_s.count(), 33LL);

    // precision loss
    constexpr auto km_h = unit_cast<kilometers_per_hours>(m_m);
    EXPECT_EQ(km_h.count(), 118LL); // 118.8
}
