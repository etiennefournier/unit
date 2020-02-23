#include <gtest/gtest.h>

#include "../unit_metric.h"
#include "../unit_imperial.h"
#include "../unit_chrono.h"
 #include "../unit_speed.h"

using namespace unit;
using namespace unit::chrono;
// using namespace std::unit;

// template <class _Rep, class _SysNum, class _DimensionNum = std::ratio<1>, class _SysDen = void, class _DimensionDen = std::ratio<1>>
// struct unit_type
// {
//     unit_type(long long rep) : _rep(rep) {};
//     long long _rep;
//     long long count() const {return _rep;}
// };

// template <class _Rep, class _SysNum, class _DimensionNum = std::ratio<1>, class _SysDen, class _DimensionDen = std::ratio<1>>
// using speed_type = __unit<_Rep, _SysNum, _DimensionNum, _SysDen, _DimensionDen>; // where _SysNum is a base unit and _SysDen a duration

// template <class _Rep, class _SysNum, class _DimensionNum = std::ratio<1>, class _SysDen, class _DimensionDen = std::ratio<1>>
// using acceleration_type = __unit<_Rep, _SysNum, _DimensionNum, _SysDen, _DimensionDen>; // where _SysNum is a speed unit and _SysDen a duration

// // template<class _Rep, class _Dimension = ratio<1>>
 using meters_per_second = __unit_speed<long long, metric_trait, std::ratio<1>, duration_trait, std::ratio<1>>;
 using meters_per_minute = __unit_speed<long long, metric_trait, std::ratio<1>, duration_trait, std::ratio<60>>;
 using nanometers_per_second = __unit_speed<long long, metric_trait, std::nano, duration_trait, std::ratio<1>>;
 using centimeters_per_hour = __unit_speed<long long, metric_trait, std::centi, duration_trait, hours::dimension>;

// using meters_per_second_squared = __unit<long long, metric_trait, duration_trait, std::ratio<1>, std::ratio<1>>;

TEST(speed, Creation)
{
    meters_per_second m1{1};
    EXPECT_EQ(m1.count(), 1LL);

    auto m2 = meters_per_second(2);
    EXPECT_EQ(m2.count(), 2LL);

    const auto m3 = meters_per_second{3};
    EXPECT_EQ(m3.count(), 3LL);

    constexpr auto m4 = meters_per_second{4};
    EXPECT_EQ(m4.count(), 4LL);
}

TEST(speed, Comparisons)
{
    EXPECT_EQ(meters_per_second(1),  meters_per_minute(60));
    EXPECT_EQ(meters_per_second(1),  meters_per_second(1));
    EXPECT_EQ(meters_per_second(1),  nanometers_per_second(1'000'000'000));

    EXPECT_EQ(meters_per_minute(720), meters_per_second(12));
    EXPECT_EQ(nanometers_per_second(1'000'000), centimeters_per_hour(360));
}
