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

#include <chrono>
#include <__config>
// #include <ctime>
// #include <type_traits>
// #include <ratio>
// #include <limits>
// #include <__cxx_version>

#include "unit.h"

// #if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
// #pragma GCC system_header
// #endif

// _LIBCPP_PUSH_MACROS
// #include <__undef_macros>

// _LIBCPP_BEGIN_NAMESPACE_STD
using namespace std;

namespace unit
{

template <class _Rep, class _SysNum, class _DimensionNum = ratio<1>, class _SysDen = void, class _DimensionDen = ratio<1> > class _LIBCPP_TEMPLATE_VIS __unit_speed;

template <class _Tp>
struct __is_unit_speed : false_type {};

template <class _Rep, class _SysNum, class _DimensionNum, class _SysDen, class _DimensionDen>
struct __is_unit_speed<__unit_speed<_Rep, _SysNum, _DimensionNum, _SysDen, _DimensionDen> > : true_type  {};

template <class _Rep, class _SysNum, class _DimensionNum, class _SysDen, class _DimensionDen>
struct __is_unit_speed<const __unit_speed<_Rep, _SysNum, _DimensionNum, _SysDen, _DimensionDen> > : true_type  {};

template <class _Rep, class _SysNum, class _DimensionNum, class _SysDen, class _DimensionDen>
struct __is_unit_speed<volatile __unit_speed<_Rep, _SysNum, _DimensionNum, _SysDen, _DimensionDen> > : true_type  {};

template <class _Rep, class _SysNum, class _DimensionNum, class _SysDen, class _DimensionDen>
struct __is_unit_speed<const volatile __unit_speed<_Rep, _SysNum, _DimensionNum, _SysDen, _DimensionDen> > : true_type  {};

} // unit

template <class _SysNum, class _SysDen,
    class _Rep1, class _DimensionNum1, class _DimensionDen1,
    class _Rep2, class _DimensionNum2, class _DimensionDen2>
struct _LIBCPP_TEMPLATE_VIS common_type<unit::__unit_speed<_Rep1, _SysNum, _DimensionNum1, _SysDen, _DimensionDen1>,
                                         unit::__unit_speed<_Rep2, _SysNum, _DimensionNum2, _SysDen, _DimensionDen2> >
{
    typedef unit::__unit_speed<typename common_type<_Rep1, _Rep2>::type,
                         _SysNum, typename __ratio_gcd<_DimensionNum1, _DimensionNum2>::type,
                         _SysDen, typename __ratio_gcd<_DimensionDen1, _DimensionDen2>::type> type;
};

// template <class _Rep1, class _Sys1, class _Dimension1, class _Rep2, class _Sys2, class _Dimension2>
// struct _LIBCPP_TEMPLATE_VIS common_type<unit::__unit<_Rep1, _Sys1, _Dimension1>,
//                                          unit::__unit<_Rep2, _Sys2, _Dimension2> >
// {
//     // typedef unit::__unit<typename common_type<_Rep1, _Rep2>::type,
//     //                      _Sys1,
//     //                      typename __ratio_gcd<_Dimension1, _Dimension2>::type> type;
// };


namespace unit {

// unit_cast

// template <class _FromUnit, class _ToUnit,
//           class _Dimension = typename ratio_divide<typename _FromUnit::dimension, typename _ToUnit::dimension>::type,
//           bool = _Dimension::num == 1,
//           bool = _Dimension::den == 1>
// struct __unit_cast;

// template <class _FromUnit, class _ToUnit, class _Dimension>
// struct __unit_cast<_FromUnit, _ToUnit, _Dimension, true, true>
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     _ToUnit operator()(const _FromUnit& __fu) const
//     {
//         return _ToUnit(static_cast<typename _ToUnit::rep>(__fu.count()));
//     }
// };

// template <class _FromUnit, class _ToUnit, class _Dimension>
// struct __unit_cast<_FromUnit, _ToUnit, _Dimension, true, false>
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     _ToUnit operator()(const _FromUnit& __fu) const
//     {
//         typedef typename common_type<typename _ToUnit::rep, typename _FromUnit::rep, intmax_t>::type _Ct;
//         return _ToUnit(static_cast<typename _ToUnit::rep>(
//                            static_cast<_Ct>(__fu.count()) / static_cast<_Ct>(_Dimension::den)));
//     }
// };

// template <class _FromUnit, class _ToUnit, class _Dimension>
// struct __unit_cast<_FromUnit, _ToUnit, _Dimension, false, true>
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     _ToUnit operator()(const _FromUnit& __fu) const
//     {
//         typedef typename common_type<typename _ToUnit::rep, typename _FromUnit::rep, intmax_t>::type _Ct;
//         return _ToUnit(static_cast<typename _ToUnit::rep>(
//                            static_cast<_Ct>(__fu.count()) * static_cast<_Ct>(_Dimension::num)));
//     }
// };

// template <class _FromUnit, class _ToUnit, class _Dimension>
// struct __unit_cast<_FromUnit, _ToUnit, _Dimension, false, false>
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     _ToUnit operator()(const _FromUnit& __fu) const
//     {
//         typedef typename common_type<typename _ToUnit::rep, typename _FromUnit::rep, intmax_t>::type _Ct;
//         return _ToUnit(static_cast<typename _ToUnit::rep>(
//                            static_cast<_Ct>(__fu.count()) * static_cast<_Ct>(_Dimension::num)
//                                                           / static_cast<_Ct>(_Dimension::den)));
//     }
// };

// template <class _ToUnit, class _Rep, class _Sys, class _Dimension>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename enable_if
// <
//     __is_unit<_ToUnit>::value,
//     _ToUnit
// >::type
// unit_cast(const __unit<_Rep, _Sys, _Dimension>& __fu)
// {
//     return __unit_cast<__unit<_Rep, _Sys, _Dimension>, _ToUnit>()(__fu);
// }

// template <class _Rep>
// struct _LIBCPP_TEMPLATE_VIS treat_as_floating_point : is_floating_point<_Rep> {};

// #if _LIBCPP_STD_VER > 14 && !defined(_LIBCPP_HAS_NO_VARIABLE_TEMPLATES)
// template <class _Rep>
// _LIBCPP_INLINE_VAR _LIBCPP_CONSTEXPR bool treat_as_floating_point_v
//     = treat_as_floating_point<_Rep>::value;
// #endif

// template <class _Rep>
// struct _LIBCPP_TEMPLATE_VIS unit_values
// {
// public:
//     _LIBCPP_INLINE_VISIBILITY static _LIBCPP_CONSTEXPR _Rep zero() _NOEXCEPT {return _Rep(0);}
//     _LIBCPP_INLINE_VISIBILITY static _LIBCPP_CONSTEXPR _Rep max()  _NOEXCEPT {return numeric_limits<_Rep>::max();}
//     _LIBCPP_INLINE_VISIBILITY static _LIBCPP_CONSTEXPR _Rep min()  _NOEXCEPT {return numeric_limits<_Rep>::lowest();}
// };

// #if _LIBCPP_STD_VER > 14
// template <class _ToUnit, class _Rep, class _Sys, class _Dimension>
// inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
// typename enable_if
// <
//     __is_unit<_ToUnit>::value,
//     _ToUnit
// >::type
// floor(const __unit<_Rep, _Sys, _Dimension>& __u)
// {
//     _ToUnit __t = unit_cast<_ToUnit>(__u);
//     if (__t > __u)
//         __t = __t - _ToUnit{1};
//     return __t;
// }

// template <class _ToUnit, class _Rep, class _Sys, class _Dimension>
// inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
// typename enable_if
// <
//     __is_unit<_ToUnit>::value,
//     _ToUnit
// >::type
// ceil(const __unit<_Rep, _Sys, _Dimension>& __u)
// {
//     _ToUnit __t = unit_cast<_ToUnit>(__u);
//     if (__t < __u)
//         __t = __t + _ToUnit{1};
//     return __t;
// }

// template <class _ToUnit, class _Rep, class _Sys, class _Dimension>
// inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
// typename enable_if
// <
//     __is_unit<_ToUnit>::value,
//     _ToUnit
// >::type
// round(const __unit<_Rep, _Sys, _Dimension>& __u)
// {
//     _ToUnit __lower = floor<_ToUnit>(__u);
//     _ToUnit __upper = __lower + _ToUnit{1};
//     auto __lowerDiff = __u - __lower;
//     auto __upperDiff = __upper - __u;
//     if (__lowerDiff < __upperDiff)
//         return __lower;
//     if (__lowerDiff > __upperDiff)
//         return __upper;
//     return __lower.count() & 1 ? __upper : __lower;
// }
// #endif

// unit

template <class _Rep, class _SysNum, class _DimensionNum, class _SysDen, class _DimensionDen>
class _LIBCPP_TEMPLATE_VIS __unit_speed : public __unit<_Rep, _SysNum, _DimensionNum>
{
    using base = __unit<_Rep, _SysNum, _DimensionNum>;
    // static_assert(!__is_unit<_Rep>::value, "A unit representation can not be a unit");
    static_assert(__is_ratio<_DimensionDen>::value, "Fifth template parameter of unit_speed must be a std::ratio");
    static_assert(_DimensionDen::num > 0, "unit_speed denominator dimension must be positive");

    template <class _R1, class _R2>
    struct __no_overflow
    {
    private:
        static const intmax_t __gcd_n1_n2 = __static_gcd<_R1::num, _R2::num>::value;
        static const intmax_t __gcd_d1_d2 = __static_gcd<_R1::den, _R2::den>::value;
        static const intmax_t __n1 = _R1::num / __gcd_n1_n2;
        static const intmax_t __d1 = _R1::den / __gcd_d1_d2;
        static const intmax_t __n2 = _R2::num / __gcd_n1_n2;
        static const intmax_t __d2 = _R2::den / __gcd_d1_d2;
        static const intmax_t max = -((intmax_t(1) << (sizeof(intmax_t) * CHAR_BIT - 1)) + 1);

        template <intmax_t _Xp, intmax_t _Yp, bool __overflow>
        struct __mul    // __overflow == false
        {
            static const intmax_t value = _Xp * _Yp;
        };

        template <intmax_t _Xp, intmax_t _Yp>
        struct __mul<_Xp, _Yp, true>
        {
            static const intmax_t value = 1;
        };

    public:
        static const bool value = (__n1 <= max / __d2) && (__n2 <= max / __d1);
        typedef ratio<__mul<__n1, __d2, !value>::value,
                      __mul<__n2, __d1, !value>::value> type;
    };

public:
    // typedef _Rep rep;
    // typedef _Sys system;
    // typedef typename _Dimension::type dimension;
    typedef typename base::rep rep;
    typedef typename base::system system_num;
    typedef typename base::dimension dimension_num;

    typedef _SysDen system_den;
    typedef typename _DimensionDen::type dimension_den;
// private:
//     rep __rep_;
public:

    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
#ifndef _LIBCPP_CXX03_LANG
        __unit_speed() = default;
#else
        __unit_speed() {}
#endif

    template <class _Rep2>
        _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
        explicit __unit_speed(const _Rep2& __r,
            typename enable_if
            <
               is_convertible<_Rep2, rep>::value &&
               (treat_as_floating_point<rep>::value ||
               !treat_as_floating_point<_Rep2>::value)
            >::type* = 0)
                : base(__r) {}

    // conversions
    template <class _Rep2, class _DimensionNum2, class _DimensionDen2>
        _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
        __unit_speed(const __unit_speed<_Rep2, system_num, _DimensionNum2, system_den, _DimensionDen2>& __u,
            typename enable_if
            <
                __no_overflow<_DimensionNum2, dimension_num>::value && (
                treat_as_floating_point<rep>::value ||
                (__no_overflow<_DimensionNum2, dimension_num>::type::den == 1 &&
                 !treat_as_floating_point<_Rep2>::value))
            >::type* = 0)
                : base(unit::unit_cast<__unit<rep, system_num, dimension_num>>(__u).count() / _DimensionDen2::num) {}
                // : base(_VSTD::unit::unit_cast<__unit<rep, system_num, dimension_num>>(__u).count()) {}


    // observer

    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR rep count() const {return __rep_;}

    // arithmetic

    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR typename common_type<__unit>::type operator+() const {return typename common_type<__unit>::type(*this);}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR typename common_type<__unit>::type operator-() const {return typename common_type<__unit>::type(-__rep_);}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit& operator++()      {++__rep_; return *this;}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit  operator++(int)   {return __unit(__rep_++);}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit& operator--()      {--__rep_; return *this;}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit  operator--(int)   {return __unit(__rep_--);}

    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit& operator+=(const __unit& __u) {__rep_ += __u.count(); return *this;}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit& operator-=(const __unit& __u) {__rep_ -= __u.count(); return *this;}

    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit& operator*=(const rep& rhs) {__rep_ *= rhs; return *this;}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit& operator/=(const rep& rhs) {__rep_ /= rhs; return *this;}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit& operator%=(const rep& rhs) {__rep_ %= rhs; return *this;}
    // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14 __unit& operator%=(const __unit& rhs) {__rep_ %= rhs.count(); return *this;}

    // // special values

    // _LIBCPP_INLINE_VISIBILITY static _LIBCPP_CONSTEXPR __unit zero() _NOEXCEPT {return __unit(unit_values<rep>::zero());}
    // _LIBCPP_INLINE_VISIBILITY static _LIBCPP_CONSTEXPR __unit min()  _NOEXCEPT {return __unit(unit_values<rep>::min());}
    // _LIBCPP_INLINE_VISIBILITY static _LIBCPP_CONSTEXPR __unit max()  _NOEXCEPT {return __unit(unit_values<rep>::max());}
};

// Unit ==

// Different system's types comparisons are defined in other header files.
// Same System, different type
// template <class _LhsUnit, class _RhsUnit>
// struct __unit_speed_eq
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     bool operator()(const _LhsUnit& __lhs, const _RhsUnit& __rhs) const
//         {
//             typedef typename common_type<_LhsUnit, _RhsUnit>::type _Ct;
//             return _Ct(__lhs).count() == _Ct(__rhs).count();
//         }
// };

// Different types
template <class _SysNum, class _SysDen, 
    class _Rep1, class _DimensionNum1, class _DimensionDen1,
    class _Rep2, class _DimensionNum2, class _DimensionDen2>
struct __unit_speed_eq
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    bool operator()(const __unit_speed<_Rep1, _SysNum, _DimensionNum1, _SysDen, _DimensionDen1>& __lhs, 
                    const __unit_speed<_Rep2, _SysNum, _DimensionNum2, _SysDen, _DimensionDen2>& __rhs) const
        {
            typedef typename common_type<
            __unit_speed<_Rep1, _SysNum, _DimensionNum1, _SysDen, _DimensionDen1>,
            __unit_speed<_Rep2, _SysNum, _DimensionNum2, _SysDen, _DimensionDen2> >::type _Ct;
            return _Ct(__lhs).count() == _Ct(__rhs).count();
            // return false;
        }    
};

// template <class _SysNum, class _SysDen, 
//     class _Rep, class _DimensionNum, class _DimensionDen>
// struct __unit_speed_eq<_SysNum, _SysDen, 
//     _Rep, _DimensionNum, _DimensionDen,
//     _Rep, _DimensionNum, _DimensionDen>
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     bool operator()(const __unit_speed<_Rep, _SysNum, _DimensionNum, _SysDen, _DimensionDen>& __lhs, 
//                     const __unit_speed<_Rep, _SysNum, _DimensionNum, _SysDen, _DimensionDen>& __rhs) const
//         {
//             return __lhs.count() == __rhs.count();
//         }    
// };

//Same types
// template <class _LhsUnit>
// struct __unit_speed_eq<_LhsUnit, _LhsUnit>
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     bool operator()(const _LhsUnit& __lhs, const _LhsUnit& __rhs) const
//         {return __lhs.count() == __rhs.count();}
// };

// template <class _Rep, class _SysNum, class _DimensionNum, class _SysDen, class _DimensionDen>

template <class _SysNum, class _SysDen, 
    class _Rep1, class _DimensionNum1, class _DimensionDen1, 
    class _Rep2, class _DimensionNum2, class _DimensionDen2>
inline _LIBCPP_INLINE_VISIBILITY
_LIBCPP_CONSTEXPR
bool
operator==(
    const __unit_speed<_Rep1, _SysNum, _DimensionNum1, _SysDen, _DimensionDen1>& __lhs, 
    const __unit_speed<_Rep2, _SysNum, _DimensionNum2, _SysDen, _DimensionDen2>& __rhs)
{
    return __unit_speed_eq<_SysNum, _SysDen,
        _Rep1, _DimensionNum1, _DimensionDen1, 
        _Rep2, _DimensionNum2, _DimensionDen2>
        ()(__lhs, __rhs);
    // return __unit_speed_eq<
    //     __unit_speed<_Rep1, _SysNum, _DimensionNum1, _SysDen, _DimensionDen1>, 
    //     __unit_speed<_Rep2, _SysNum, _DimensionNum2, _SysDen, _DimensionDen2> >
    //     ()(__lhs, __rhs);
}

// Comparing two units of the same system works by casting left and right arguments to their common type
// and comparing their count.
// Comparison between two differents systems won't have a common type, hence the need to implement
// the logic in the equality operator.

// TODO: Check if we can move some calculation to compile time by using a common type that would use the ratio between two systems.
// TODO: Check if this specialization could be moved under the __unit_speed_eq helper struct here as well as in unit.h
template <class _SysDen,
    class _Rep1, class _SysNum1, class _DimensionNum1, class _DimensionDen1,
    class _Rep2, class _SysNum2, class _DimensionNum2, class _DimensionDen2>
inline _LIBCPP_INLINE_VISIBILITY
_LIBCPP_CONSTEXPR
bool
operator==(
    const __unit_speed<_Rep1, _SysNum1, _DimensionNum1, _SysDen, _DimensionDen1>& __lhs, 
    const __unit_speed<_Rep2, _SysNum2, _DimensionNum2, _SysDen, _DimensionDen2>& __rhs)
{
    return false;
    // return __lhs == unit_cast<__unit<_Rep1, _Sys1, _Dimension1> >(__rhs);
}

// Unit !=

// template <class _Rep1, class _Sys1, class _Dimension1, class _Rep2, class _Sys2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// bool
// operator!=(const __unit<_Rep1, _Sys1, _Dimension1>& __lhs, const __unit<_Rep2, _Sys2, _Dimension2>& __rhs)
// {
//     return !(__lhs == __rhs);
// }

// // Unit <

// template <class _LhsUnit, class _RhsUnit>
// struct __unit_lt
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     bool operator()(const _LhsUnit& __lhs, const _RhsUnit& __rhs) const
//         {
//             typedef typename common_type<_LhsUnit, _RhsUnit>::type _Ct;
//             return _Ct(__lhs).count() < _Ct(__rhs).count();
//         }
// };

// template <class _LhsUnit>
// struct __unit_lt<_LhsUnit, _LhsUnit>
// {
//     _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
//     bool operator()(const _LhsUnit& __lhs, const _LhsUnit& __rhs) const
//         {return __lhs.count() < __rhs.count();}
// };

// template <class _Rep1, class _Sys1, class _Dimension1, class _Rep2, class _Sys2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// bool
// operator< (const __unit<_Rep1, _Sys1, _Dimension1>& __lhs, const __unit<_Rep2, _Sys2, _Dimension2>& __rhs)
// {
//     return __unit_lt<__unit<_Rep1, _Sys1, _Dimension1>, __unit<_Rep2, _Sys2, _Dimension2> >()(__lhs, __rhs);
// }

// // Unit >

// template <class _Rep1, class _Sys1, class _Dimension1, class _Rep2, class _Sys2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// bool
// operator> (const __unit<_Rep1, _Sys1, _Dimension1>& __lhs, const __unit<_Rep2, _Sys2, _Dimension2>& __rhs)
// {
//     return __rhs < __lhs;
// }

// // Unit <=

// template <class _Rep1, class _Sys1, class _Dimension1, class _Rep2, class _Sys2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// bool
// operator<=(const __unit<_Rep1, _Sys1, _Dimension1>& __lhs, const __unit<_Rep2, _Sys2, _Dimension2>& __rhs)
// {
//     return !(__rhs < __lhs);
// }

// // Unit >=

// template <class _Rep1, class _Sys1, class _Dimension1, class _Rep2, class _Sys2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// bool
// operator>=(const __unit<_Rep1, _Sys1, _Dimension1>& __lhs, const __unit<_Rep2, _Sys2, _Dimension2>& __rhs)
// {
//     return !(__lhs < __rhs);
// }

// // Unit +

// template <class _Rep1, class _Sys1, class _Dimension1, class _Rep2, class _Sys2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename common_type<__unit<_Rep1, _Sys1, _Dimension1>, __unit<_Rep2, _Sys2, _Dimension2> >::type
// operator+(const __unit<_Rep1, _Sys1, _Dimension1>& __lhs, const __unit<_Rep2, _Sys2, _Dimension2>& __rhs)
// {
//     typedef typename common_type<__unit<_Rep1, _Sys1, _Dimension1>, __unit<_Rep2, _Sys2, _Dimension2> >::type _Cd;
//     return _Cd(_Cd(__lhs).count() + _Cd(__rhs).count());
// }

// // Unit -

// template <class _Rep1, class _Sys1, class _Dimension1, class _Rep2, class _Sys2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename common_type<__unit<_Rep1, _Sys1, _Dimension1>, __unit<_Rep2, _Sys2, _Dimension2> >::type
// operator-(const __unit<_Rep1, _Sys1, _Dimension1>& __lhs, const __unit<_Rep2, _Sys2, _Dimension2>& __rhs)
// {
//     typedef typename common_type<__unit<_Rep1, _Sys1, _Dimension1>, __unit<_Rep2, _Sys2, _Dimension2> >::type _Cd;
//     return _Cd(_Cd(__lhs).count() - _Cd(__rhs).count());
// }

// // Unit *

// template <class _Sys, class _Rep1, class _Dimension, class _Rep2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename enable_if
// <
//     is_convertible<_Rep2, typename common_type<_Rep1, _Rep2>::type>::value,
//     __unit<typename common_type<_Rep1, _Rep2>::type, _Dimension>
// >::type
// operator*(const __unit<_Rep1, _Sys, _Dimension>& __u, const _Rep2& __s)
// {
//     typedef typename common_type<_Rep1, _Rep2>::type _Cr;
//     typedef __unit<_Sys, _Cr, _Dimension> _Cd;
//     return _Cd(_Cd(__u).count() * static_cast<_Cr>(__s));
// }

// template <class _Sys, class _Rep1, class _Dimension, class _Rep2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename enable_if
// <
//     is_convertible<_Rep1, typename common_type<_Rep1, _Rep2>::type>::value,
//     __unit<typename common_type<_Rep1, _Rep2>::type, _Dimension>
// >::type
// operator*(const _Rep1& __s, const __unit<_Rep2, _Sys, _Dimension>& __u)
// {
//     return __u * __s;
// }

// // Unit /

// template <class _Unit, class _Rep, bool = __is_unit<_Rep>::value>
// struct __unit_divide_result
// {
// };

// template <class _Unit, class _Rep2,
//     bool = is_convertible<_Rep2,
//                           typename common_type<typename _Unit::rep, _Rep2>::type>::value>
// struct __unit_divide_imp
// {
// };

// template <class _Sys, class _Rep1, class _Dimension, class _Rep2>
// struct __unit_divide_imp<__unit<_Rep1, _Sys, _Dimension>, _Rep2, true>
// {
//     typedef __unit<_Sys, typename common_type<_Rep1, _Rep2>::type, _Dimension> type;
// };

// template <class _Sys, class _Rep1, class _Dimension, class _Rep2>
// struct __unit_divide_result<__unit<_Rep1, _Sys, _Dimension>, _Rep2, false>
//     : __unit_divide_imp<__unit<_Rep1, _Sys, _Dimension>, _Rep2>
// {
// };

// template <class _Sys, class _Rep1, class _Dimension, class _Rep2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename __unit_divide_result<__unit<_Rep1, _Sys, _Dimension>, _Rep2>::type
// operator/(const __unit<_Rep1, _Sys, _Dimension>& __u, const _Rep2& __s)
// {
//     typedef typename common_type<_Rep1, _Rep2>::type _Cr;
//     typedef __unit<_Sys, _Cr, _Dimension> _Cd;
//     return _Cd(_Cd(__u).count() / static_cast<_Cr>(__s));
// }

// template <class _Sys, class _Rep1, class _Dimension1, class _Rep2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename common_type<_Rep1, _Rep2>::type
// operator/(const __unit<_Rep1, _Sys, _Dimension1>& __lhs, const __unit<_Rep1, _Sys, _Dimension2>& __rhs)
// {
//     typedef typename common_type<__unit<_Rep1, _Sys, _Dimension1>, __unit<_Rep1, _Sys, _Dimension2> >::type _Ct;
//     return _Ct(__lhs).count() / _Ct(__rhs).count();
// }

// // Unit %

// template <class _Sys, class _Rep1, class _Dimension, class _Rep2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename __unit_divide_result<__unit<_Rep1, _Sys, _Dimension>, _Rep2>::type
// operator%(const __unit<_Rep1, _Sys, _Dimension>& __u, const _Rep2& __s)
// {
//     typedef typename common_type<_Rep1, _Rep2>::type _Cr;
//     typedef __unit<_Sys, _Cr, _Dimension> _Cd;
//     return _Cd(_Cd(__u).count() % static_cast<_Cr>(__s));
// }

// template <class _Sys, class _Rep1, class _Dimension1, class _Rep2, class _Dimension2>
// inline _LIBCPP_INLINE_VISIBILITY
// _LIBCPP_CONSTEXPR
// typename common_type<__unit<_Rep1, _Sys, _Dimension1>, __unit<_Rep2, _Sys, _Dimension2> >::type
// operator%(const __unit<_Rep1, _Sys, _Dimension1>& __lhs, const __unit<_Rep2, _Sys, _Dimension2>& __rhs)
// {
//     typedef typename common_type<_Rep1, _Rep2>::type _Cr;
//     typedef typename common_type<__unit<_Rep1, _Sys, _Dimension1>, __unit<_Rep2, _Sys, _Dimension2> >::type _Cd;
//     return _Cd(static_cast<_Cr>(_Cd(__lhs).count()) % static_cast<_Cr>(_Cd(__rhs).count()));
// }

} // unit

// _LIBCPP_END_NAMESPACE_STD

// _LIBCPP_POP_MACROS

#endif  // _LIBCPP_UNIT_SPEED
