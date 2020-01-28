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
    template<intmax_t _Num, class _FromType, intmax_t _Den, class _ToType>
    struct conversion_helper
    {
        private:
        typedef std::ratio<_Num, _Den> dimension;

        public:
        static _LIBCPP_CONSTEXPR const intmax_t num = dimension::num;
        static _LIBCPP_CONSTEXPR const intmax_t den = dimension::den;

        typedef typename common_type<typename _FromType::rep, typename _ToType::rep>::type _Cr;

        template<class _Rep>
        using from_ref_type = __unit<_Rep, typename _FromType::system, typename _FromType::dimension>;

        template<class _Rep>
        using to_ref_type = __unit<_Rep, typename _ToType::system, typename _ToType::dimension>;
    };

using imperial_to_metric = conversion_helper<5, thous, 127, micrometers>;

// TODO see what needs to be done to support other flavors of num and den equality (last 2 templated arguments).
// Revisit typedefs in conversion helper
template <class _RepFrom, class _DimensionFrom, class _RepTo, class _DimensionTo, class _Dimension>
struct __unit_cast<__unit<_RepFrom, metric_trait, _DimensionFrom>, __unit<_RepTo, imperial_trait, _DimensionTo>, _Dimension, false, false>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    __unit<_RepTo, imperial_trait, _DimensionTo> operator()(const __unit<_RepFrom, metric_trait, _DimensionFrom>& __fu) const
    {
        typedef typename common_type<_RepFrom, _RepTo>::type _Cr;

        const auto refUnitFrom = unit_cast<imperial_to_metric::to_ref_type<_Cr>>(__fu);
        const auto refUnitTo   = imperial_to_metric::from_ref_type<_Cr>{refUnitFrom.count() * imperial_to_metric::num / imperial_to_metric::den};

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

        const auto refUnitFrom = unit_cast<imperial_to_metric::from_ref_type<_Cr>>(__fu);
        const auto refUnitTo   = imperial_to_metric::to_ref_type<_Cr>{refUnitFrom.count() * imperial_to_metric::den / imperial_to_metric::num};

        return unit_cast<__unit<_RepTo, metric_trait, _DimensionTo> >(refUnitTo);
    }
};

} // namespace unit

// _LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP_UNIT_METRIC_CONVERSION
