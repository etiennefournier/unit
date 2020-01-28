// -*- C++ -*-
//===---------------------------- unit ------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_UNIT_CHRONO
#define _LIBCPP_UNIT_CHRONO

#include <__config>

#include "unit.h"

// _LIBCPP_BEGIN_NAMESPACE_STD

namespace unit
{
    namespace chrono
    {
        struct duration_trait{};

        //aliases
        template<class _Rep, class _Dimension = ratio<1>>
        using duration = __unit<_Rep, duration_trait, _Dimension>;

        // Duration cast   
        template <class _ToUnit, class _Rep, class _Dimension>
        inline _LIBCPP_INLINE_VISIBILITY
        _LIBCPP_CONSTEXPR
        typename enable_if
        <
            __is_unit<_ToUnit>::value,
            _ToUnit
        >::type
        duration_cast(const duration<_Rep, _Dimension>& __fu)
        {
            return __unit_cast<duration<_Rep, _Dimension>, _ToUnit>()(__fu);
        }

        typedef duration<long long,         nano> nanoseconds;
        typedef duration<long long,        micro> microseconds;
        typedef duration<long long,        milli> milliseconds;
        typedef duration<long long              > seconds;
        typedef duration<     long, ratio<  60> > minutes;
        typedef duration<     long, ratio<3600> > hours;
        #if _LIBCPP_STD_VER > 17
        typedef duration<     int, ratio_multiply<ratio<24>, hours::period>>         days;
        typedef duration<     int, ratio_multiply<ratio<7>,   days::period>>         weeks;
        typedef duration<     int, ratio_multiply<ratio<146097, 400>, days::period>> years;
        typedef duration<     int, ratio_divide<years::period, ratio<12>>>           months;
        #endif

        inline ostream& operator<<(ostream& os, const nanoseconds& u)  { return os << u.count() << " nanoseconds";}
        inline ostream& operator<<(ostream& os, const microseconds& u) { return os << u.count() << " microseconds";}
        inline ostream& operator<<(ostream& os, const milliseconds& u) { return os << u.count() << " milliseconds";}
        inline ostream& operator<<(ostream& os, const seconds& u)      { return os << u.count() << " seconds";}
        inline ostream& operator<<(ostream& os, const minutes& u)      { return os << u.count() << " minutes";}
        inline ostream& operator<<(ostream& os, const hours& u)        { return os << u.count() << " hours";}
        #if _LIBCPP_STD_VER > 17
        inline ostream& operator<<(ostream& os, const days& u)   { return os << u.count() << " days";}
        inline ostream& operator<<(ostream& os, const weeks& u)  { return os << u.count() << " weeks";}
        inline ostream& operator<<(ostream& os, const years& u)  { return os << u.count() << " years";}
        inline ostream& operator<<(ostream& os, const months& u) { return os << u.count() << " months";}
        #endif
    }
}


#if _LIBCPP_STD_VER > 11
// Suffixes for ...
inline namespace literals
{
  inline namespace unit_literals
  {
    constexpr chrono::hours operator""_h(unsigned long long __h)
    {
        return chrono::hours(static_cast<chrono::hours::rep>(__h));
    }

    constexpr chrono::duration<long double, ratio<3600,1>> operator""_h(long double __h)
    {
        return chrono::duration<long double, ratio<3600,1>>(__h);
    }


    constexpr chrono::minutes operator""_min(unsigned long long __m)
    {
        return chrono::minutes(static_cast<chrono::minutes::rep>(__m));
    }

    constexpr chrono::duration<long double, ratio<60,1>> operator""_min(long double __m)
    {
        return chrono::duration<long double, ratio<60,1>> (__m);
    }


    constexpr chrono::seconds operator""_s(unsigned long long __s)
    {
        return chrono::seconds(static_cast<chrono::seconds::rep>(__s));
    }

    constexpr chrono::duration<long double> operator""_s(long double __s)
    {
        return chrono::duration<long double> (__s);
    }


    constexpr chrono::milliseconds operator""_ms(unsigned long long __ms)
    {
        return chrono::milliseconds(static_cast<chrono::milliseconds::rep>(__ms));
    }

    constexpr chrono::duration<long double, milli> operator""_ms(long double __ms)
    {
        return chrono::duration<long double, milli>(__ms);
    }


    constexpr chrono::microseconds operator""_us(unsigned long long __us)
    {
        return chrono::microseconds(static_cast<chrono::microseconds::rep>(__us));
    }

    constexpr chrono::duration<long double, micro> operator""_us(long double __us)
    {
        return chrono::duration<long double, micro> (__us);
    }


    constexpr chrono::nanoseconds operator""_ns(unsigned long long __ns)
    {
        return chrono::nanoseconds(static_cast<chrono::nanoseconds::rep>(__ns));
    }

    constexpr chrono::duration<long double, nano> operator""_ns(long double __ns)
    {
        return chrono::duration<long double, nano> (__ns);
    }

#if _LIBCPP_STD_VER > 17 && !defined(_LIBCPP_HAS_NO_CXX20_CHRONO_LITERALS)
    constexpr chrono::day operator ""_d(unsigned long long __d) noexcept
    {
        return chrono::day(static_cast<unsigned>(__d));
    }
 
    constexpr chrono::year operator ""_y(unsigned long long __y) noexcept
    {
        return chrono::year(static_cast<int>(__y));
    }
#endif
}}

// uncomment when bringing back into std namespace "_LIBCPP_END_NAMESPACE_STD"
// namespace unit { // hoist the literals into namespace std::chrono
//    using namespace literals::unit_literals;
// }

#endif

// _LIBCPP_END_NAMESPACE_STD

#endif  // _LIBCPP_UNIT_CHRONO
