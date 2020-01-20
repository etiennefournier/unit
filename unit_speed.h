// -*- C++ -*-
//===---------------------------- unit ------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_UNIT_SPEED
#define _LIBCPP_UNIT_SPEED

#include <__config>
#include <iostream>

#include "unit.h"
#include "unit_metric.h"
#include "unit_chrono.h"

// _LIBCPP_BEGIN_NAMESPACE_STD

namespace unit
{
    struct speed_trait{};
    
    template<class _Rep, class _DimensionNum = ratio<1>, class _DimensionDen = ratio<1>>
    using speed_unit = __unit<speed_trait, _Rep, _DimensionNum, _DimensionDen>;

    // ratios

    // aliases
    using meters_per_seconds = speed_unit<typename common_type<meters::rep, chrono::seconds::rep>::type, meters::dimension, chrono::seconds::dimension>;

    template <class _Sys1, class _Rep1, class _Dimension1, class _Sys2, class _Rep2, class _Dimension2>
    inline _LIBCPP_INLINE_VISIBILITY
    _LIBCPP_CONSTEXPR
    speed_unit<typename common_type<_Rep1, _Rep2>::type, _Dimension1, _Dimension2>
    operator/(const __unit<_Sys1, _Rep1, _Dimension1>& __lhs, const __unit<_Sys2, _Rep2, _Dimension2>& __rhs)
    {
        typedef typename common_type<_Rep1, _Rep2>::type _CommonRepType;
        return speed_unit<_CommonRepType, _Dimension1, _Dimension2>{_CommonRepType(__lhs.count()) / _CommonRepType(__rhs.count())};
    }
}


#if _LIBCPP_STD_VER > 11
// Suffixes for ...
inline namespace literals
{
  inline namespace unit_literals
  {
}}

// uncomment when bringing back into std namespace "_LIBCPP_END_NAMESPACE_STD"
// namespace unit { // hoist the literals into namespace std::chrono
//    using namespace literals::unit_literals;
// }

#endif

// _LIBCPP_END_NAMESPACE_STD

#endif  // _LIBCPP_UNIT_SPEED
