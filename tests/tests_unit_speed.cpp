#include <gtest/gtest.h>

#include "../unit_metric.h"
#include "../unit_imperial.h"
#include "../unit_chrono.h"
// #include "../unit_speed.h"

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
// using meters_per_second         = __unit<long long, metric_trait, std::ratio<1>, duration_trait, std::ratio<1>>;
// using meters_per_second_squared = __unit<long long, metric_trait, duration_trait, std::ratio<1>, std::ratio<1>>;

using m_per_s = decltype(meters{} / 2);
TEST(speed, Construction)
{
//     meters_per_seconds m1{1};
//     EXPECT_EQ(m1.count(), 1LL);

//     auto m2 = meters_per_seconds(2);
//     EXPECT_EQ(m2.count(), 2LL);

//     const auto m3 = meters_per_seconds{3};
//     EXPECT_EQ(m3.count(), 3LL);

//     constexpr auto m4 = meters_per_seconds{4};
//     EXPECT_EQ(m4.count(), 4LL);
}
