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
    using imperial_unit = __unit<_Rep, imperial_trait, _Dimension>;

    using yards    = imperial_unit<long long>;

    using feet     = imperial_unit<long long, std::ratio_divide<yards::dimension , feet_in_yard>>;
    using inches   = imperial_unit<long long, std::ratio_divide<feet::dimension  , inches_in_foot>>;
    using thous    = imperial_unit<long long, std::ratio_divide<inches::dimension, thous_in_inch>>;
  
    using chains   = imperial_unit<long long, std::ratio_multiply<yards::dimension   , yards_in_chain>>;
    using furlongs = imperial_unit<long long, std::ratio_multiply<chains::dimension  , chains_in_furlong>>;
    using miles    = imperial_unit<long long, std::ratio_multiply<furlongs::dimension, furlongs_in_mile>>;
    using leagues  = imperial_unit<long long, std::ratio_multiply<miles::dimension   , miles_in_league>>;

    inline ostream& operator<<(ostream& os, const yards& u)  { return os << u.count() << " yards";}
    inline ostream& operator<<(ostream& os, const feet& u) { return os << u.count() << " feet";}
    inline ostream& operator<<(ostream& os, const inches& u) { return os << u.count() << " inches";}
    inline ostream& operator<<(ostream& os, const thous& u) { return os << u.count() << " thous";}
    inline ostream& operator<<(ostream& os, const chains& u)  { return os << u.count() << " chains";}
    inline ostream& operator<<(ostream& os, const furlongs& u)      { return os << u.count() << " furlongs";}
    inline ostream& operator<<(ostream& os, const miles& u)  { return os << u.count() << " miles";}
    inline ostream& operator<<(ostream& os, const leagues& u)  { return os << u.count() << " leagues";}
}


#if _LIBCPP_STD_VER > 11
// Suffixes for ...
inline namespace literals
{
  inline namespace unit_literals
  {
    constexpr unit::yards    operator""_yard(unsigned long long u)   { return unit::yards(static_cast<unit::yards::rep>(u)); }
    constexpr unit::feet     operator""_foot(unsigned long long u)   { return unit::feet(static_cast<unit::feet::rep>(u)); }
    constexpr unit::inches   operator""_inch(unsigned long long u)   { return unit::inches(static_cast<unit::inches::rep>(u)); }
    constexpr unit::thous    operator""_thou(unsigned long long u)   { return unit::thous(static_cast<unit::thous::rep>(u)); }
    constexpr unit::chains   operator""_chain(unsigned long long u)  { return unit::chains(static_cast<unit::chains::rep>(u)); }
    constexpr unit::furlongs operator""_furlong(unsigned long long u){ return unit::furlongs(static_cast<unit::furlongs::rep>(u)); }
    constexpr unit::miles    operator""_mile(unsigned long long u)   { return unit::miles(static_cast<unit::miles::rep>(u)); }
    constexpr unit::leagues  operator""_league(unsigned long long u) { return unit::leagues(static_cast<unit::leagues::rep>(u)); }
}}

// uncomment when bringing back into std namespace "_LIBCPP_END_NAMESPACE_STD"
// namespace unit { // hoist the literals into namespace std::chrono
//    using namespace literals::unit_literals;
// }

#endif

// _LIBCPP_END_NAMESPACE_STD

#endif  // _LIBCPP_UNIT_IMPERIAL
