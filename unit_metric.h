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
    using meters      = metric_unit<long long>;

    ostream& operator<<(ostream& os, const meters& m)
    {
        return os << m.count() << " meters";
    }

    ostream& operator<<(ostream& os, const millimeters& m)
    {
        return os << m.count() << " millimeters";
    }    
}


#if _LIBCPP_STD_VER > 11
// Suffixes for ...
inline namespace literals
{
  inline namespace unit_literals
  {

    constexpr unit::meters operator""_m(unsigned long long m)
    {
        return unit::meters(static_cast<unit::meters::rep>(m));
    }
}}

// uncomment when bringing back into std namespace "_LIBCPP_END_NAMESPACE_STD"
// namespace unit { // hoist the literals into namespace std::chrono
//    using namespace literals::unit_literals;
// }

#endif

// _LIBCPP_END_NAMESPACE_STD

#endif  // _LIBCPP_UNIT_METRIC
