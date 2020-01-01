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

// Duration equality operator works by casting left and right arguments to their common type
// and comparing their count.
// Comparison between two differents systems won't have a common type, hence the need to implement
// the logic in the equality operator.

template <
    class _Rep1, class _Dimension1,
    class _Rep2, class _Dimension2>
inline constexpr bool operator==(
    const imperial_unit<_Rep1, _Dimension1> &_Left, const metric_unit<_Rep2, _Dimension2> &_Right)
{
        return (unit_cast<thous>(_Left) / thous_in_micrometers::num).count() ==
               (unit_cast<micrometers>(_Right) / thous_in_micrometers::den).count();
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
