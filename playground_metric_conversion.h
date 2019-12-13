#ifndef PLAYGROUND_METRIC_CONVERSION
#define PLAYGROUND_METRIC_CONVERSION

#include <ratio>
#include <tuple>
#include "playground_imperial.h"

using namespace std;

namespace playground
{
    struct conversion_tag{};

    template<class FromType, class ToType>
    using conversion_util = tuple<conversion_tag, FromType, ToType>;

    template<class FromType, class ToType>
    inline constexpr conversion_util<FromType, ToType>
    make_conversion(FromType&& _from, ToType&& _to)
    {
        return conversion_util<FromType, ToType>({},_from, _to);
    }

    using conversion_type = decltype(make_conversion(metric(1), imperial(3)));
    // Would be nice if this could be enough.
    inline constexpr auto const_conversion{make_conversion(metric(1), imperial(3))};
    
    // inline  tuple<int, int> = make_tuple(1,2);
    // metric_tag, imperial_tag, 91400_m, 1_ft
    template<class Dimension1, class Dimension2>
    bool operator ==(const distance<Dimension1, metric_tag>& lhs, const distance<Dimension2, imperial_tag>& rhs)
    {
        auto test0 = get<0>(const_conversion);
        auto test1 = get<1>(const_conversion);
        auto test2 = get<2>(const_conversion);

        constexpr tuple_element<1, decltype(const_conversion)>::type::tag test_type{};

        auto l = lhs.m_i * std::ratio_multiply<metric::dimension, imperial::dimension>::num;
        return l == rhs.m_i;
    }
    // bool operator==(const metric &lhs, const imperial &rhs)
    // {
    //     auto l = lhs.m_i * std::ratio_multiply<metric::dimension, imperial::dimension>::num;
    //     return l == rhs.m_i;
    // }

    // bool operator==(const imperial &lhs, const metric &rhs)
    // {
    //     return rhs == lhs;
    // }
} // namespace playground

#endif //PLAYGROUND_METRIC_CONVERSION