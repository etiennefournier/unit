// -*- C++ -*-
//===---------------------------- unit ------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_UNIT_IMPERIAL
#define _LIBCPP_UNIT_IMPERIAL

#include <__config>

#include "unit.h"

// _LIBCPP_BEGIN_NAMESPACE_STD

namespace unit
{
    struct imperial_trait{};

    // ratios
    using thous_in_inch     = std::ratio<1000>;
    using inches_in_foot    = std::ratio<12>;
    using feet_in_yard      = std::ratio<3>;
    using yards_in_chain    = std::ratio<22>;
    using chains_in_furlong = std::ratio<10>;
    using furlongs_in_mile  = std::ratio<8>;
    using miles_in_league   = std::ratio<3>;

    //aliases
    template<class _Rep, class _Dimension = ratio<1>>
    using imperial_unit = __unit<imperial_trait, _Rep, _Dimension>;

    using yards    = imperial_unit<long long>;

    using feet     = imperial_unit<long long, std::ratio_divide<yards::dimension , feet_in_yard>>;
    using inches   = imperial_unit<long long, std::ratio_divide<feet::dimension  , inches_in_foot>>;
    using thous    = imperial_unit<long long, std::ratio_divide<inches::dimension, thous_in_inch>>;
  
    using chains   = imperial_unit<long long, std::ratio_multiply<yards::dimension   , yards_in_chain>>;
    using furlongs = imperial_unit<long long, std::ratio_multiply<chains::dimension  , chains_in_furlong>>;
    using miles    = imperial_unit<long long, std::ratio_multiply<furlongs::dimension, furlongs_in_mile>>;
    using leagues  = imperial_unit<long long, std::ratio_multiply<miles::dimension   , miles_in_league>>;
}

// _LIBCPP_END_NAMESPACE_STD

#endif  // _LIBCPP_UNIT_IMPERIAL
