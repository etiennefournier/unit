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

template<class _Rep>
using metric_ref_type = __unit<_Rep, micrometers::system, micrometers::dimension>;

template<class _Rep>
using imperial_ref_type = __unit<_Rep, thous::system, thous::dimension>;

// TODO see what needs to be done to support other flavors of num and den equality (last 2 templated arguments).

template <class _RepFrom, class _DimensionFrom, class _RepTo, class _DimensionTo, class _Dimension>
struct __unit_cast<__unit<_RepFrom, metric_trait, _DimensionFrom>, __unit<_RepTo, imperial_trait, _DimensionTo>, _Dimension, false, false>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    __unit<_RepTo, imperial_trait, _DimensionTo> operator()(const __unit<_RepFrom, metric_trait, _DimensionFrom>& __fu) const
    {
        typedef typename common_type<_RepFrom, _RepTo>::type _Cr;

        const auto refUnitFrom = unit_cast<metric_ref_type<_Cr>>(__fu);
        const auto refUnitTo   = imperial_ref_type<_Cr>{refUnitFrom.count() * thous_in_micrometers::num / thous_in_micrometers::den};

        return unit_cast<__unit<_RepTo, imperial_trait, _DimensionTo> >(refUnitTo);
    }
};

template <class _RepFrom, class _DimensionFrom, class _RepTo, class _DimensionTo, class _Dimension>
struct __unit_cast<__unit<_RepFrom, imperial_trait, _DimensionFrom>, __unit<_RepTo, metric_trait, _DimensionTo>, _Dimension, false, false>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    __unit<_RepTo, metric_trait, _DimensionTo> operator()(const __unit<_RepFrom, imperial_trait, _DimensionFrom>& __fu) const
    {
        typedef typename common_type<_RepFrom, _RepTo>::type _Cr;

        const auto refUnitFrom = unit_cast<imperial_ref_type<_Cr>>(__fu);
        const auto refUnitTo   = metric_ref_type<_Cr>{refUnitFrom.count() * thous_in_micrometers::den / thous_in_micrometers::num};

        return unit_cast<__unit<_RepTo, metric_trait, _DimensionTo> >(refUnitTo);
    }
};

} // namespace unit

// _LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP_UNIT_METRIC_CONVERSION
