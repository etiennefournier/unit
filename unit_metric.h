// -*- C++ -*-
//===---------------------------- unit ------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_UNIT_METRIC
#define _LIBCPP_UNIT_METRIC

#include <__config>
#include <iostream>

#include "unit.h"

// _LIBCPP_BEGIN_NAMESPACE_STD

namespace unit
{
   struct metric_trait{};

    // ratios
    // using ratios defines in ratio header
    template<class _Rep, class _Dimension = ratio<1>>
    using metric_unit = __unit<metric_trait, _Rep, _Dimension>;

    // aliases
    using nanometers  = metric_unit<long long, std::nano>;
    using micrometers = metric_unit<long long, std::micro>;
    using millimeters = metric_unit<long long, std::milli>;
    using centimeters = metric_unit<long long, std::centi>;
    using decimeters  = metric_unit<long long, std::deci>;
    using meters      = metric_unit<long long>;
    using kilometers  = metric_unit<long long, std::kilo>;

    inline ostream& operator<<(ostream& os, const nanometers& u)  { return os << u.count() << " nanometers";}
    inline ostream& operator<<(ostream& os, const micrometers& u) { return os << u.count() << " micrometers";}
    inline ostream& operator<<(ostream& os, const millimeters& u) { return os << u.count() << " millimeters";}
    inline ostream& operator<<(ostream& os, const centimeters& u) { return os << u.count() << " centimeters";}
    inline ostream& operator<<(ostream& os, const decimeters& u)  { return os << u.count() << " decimeters";}
    inline ostream& operator<<(ostream& os, const meters& u)      { return os << u.count() << " meters";}
    inline ostream& operator<<(ostream& os, const kilometers& u)  { return os << u.count() << " kilometers";}
}


#if _LIBCPP_STD_VER > 11
// Suffixes for ...
inline namespace literals
{
  inline namespace unit_literals
  {
    constexpr unit::nanometers  operator""_nm(unsigned long long m){ return unit::nanometers(static_cast<unit::nanometers::rep>(m)); }
    constexpr unit::micrometers operator""_um(unsigned long long m){ return unit::micrometers(static_cast<unit::micrometers::rep>(m)); }
    constexpr unit::millimeters operator""_mm(unsigned long long m){ return unit::millimeters(static_cast<unit::millimeters::rep>(m)); }
    constexpr unit::centimeters operator""_cm(unsigned long long m){ return unit::centimeters(static_cast<unit::centimeters::rep>(m)); }
    constexpr unit::decimeters  operator""_dm(unsigned long long m){ return unit::decimeters(static_cast<unit::decimeters::rep>(m)); }
    constexpr unit::meters      operator""_m (unsigned long long m){ return unit::meters(static_cast<unit::meters::rep>(m)); }
    constexpr unit::kilometers  operator""_km(unsigned long long m){ return unit::kilometers(static_cast<unit::kilometers::rep>(m)); }
}}

// uncomment when bringing back into std namespace "_LIBCPP_END_NAMESPACE_STD"
// namespace unit { // hoist the literals into namespace std::chrono
//    using namespace literals::unit_literals;
// }

#endif

// _LIBCPP_END_NAMESPACE_STD

#endif  // _LIBCPP_UNIT_METRIC
