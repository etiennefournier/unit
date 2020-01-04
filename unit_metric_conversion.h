// -*- C++ -*-
//===---------------------------- unit ------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_UNIT_METRIC_CONVERSION
#define _LIBCPP_UNIT_METRIC_CONVERSION

#include <__config>

#include "unit_metric.h"
#include "unit_imperial.h"

// _LIBCPP_BEGIN_NAMESPACE_STD

namespace unit
{
using thous_in_micrometers = ratio<5, 127>;

// TODO see what needs to be done to support other flavors of num and den equality (last 2 templated arguments).

    // auto um = micrometers(127);
    // auto ts = unit_cast<thous>(um);

    // EXPECT_EQ(ts.count(), 5);

template <class _RepFrom, class _DimensionFrom, class _RepTo, class _DimensionTo, class _Dimension>
struct __unit_cast<metric_unit<_RepFrom, _DimensionFrom>, imperial_unit<_RepTo, _DimensionTo>, _Dimension, false, false>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    imperial_unit<_RepTo, _DimensionTo> operator()(const metric_unit<_RepFrom, _DimensionFrom>& __fu) const
    {
        const auto refUnitFrom = unit_cast<micrometers>(__fu);
        const auto refUnitTo   = thous{refUnitFrom.count() * thous_in_micrometers::num / thous_in_micrometers::den};

        return unit_cast<imperial_unit<_RepTo, _DimensionTo> >(refUnitTo);
    }
};

template <class _RepFrom, class _DimensionFrom, class _RepTo, class _DimensionTo, class _Dimension>
struct __unit_cast<imperial_unit<_RepFrom, _DimensionFrom>, metric_unit<_RepTo, _DimensionTo>, _Dimension, false, false>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    metric_unit<_RepTo, _DimensionTo> operator()(const imperial_unit<_RepFrom, _DimensionFrom>& __fu) const
    {
        const auto refUnitFrom = unit_cast<thous>(__fu);
        const auto refUnitTo   = micrometers{refUnitFrom.count() * thous_in_micrometers::den / thous_in_micrometers::num};

        return unit_cast<metric_unit<_RepTo, _DimensionTo> >(refUnitTo);
    }
};

// Duration equality operator works by casting left and right arguments to their common type
// and comparing their count.
// Comparison between two differents systems won't have a common type, hence the need to implement
// the logic in the equality operator.

// TODO 1: Bing able to find a common type that would use the right ratio for the calculation would be ideal.
// TODO 2: Find a way to move this piece of code into unit.h by specializing for different systems
template <
    class _Rep1, class _Dimension1,
    class _Rep2, class _Dimension2>
inline constexpr bool operator==(
    const imperial_unit<_Rep1, _Dimension1> &_Left, const metric_unit<_Rep2, _Dimension2> &_Right)
{
        return _Left == unit_cast<imperial_unit<_Rep1, _Dimension1> >(_Right);
}

template <
    class _Rep1, class _Dimension1,
    class _Rep2, class _Dimension2>
inline constexpr bool operator==(
    const metric_unit<_Rep1, _Dimension1> &_Left, const imperial_unit<_Rep2, _Dimension2> &_Right)
{
        return _Right == _Left;
}

} // namespace unit

// _LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP_UNIT_METRIC_CONVERSION
