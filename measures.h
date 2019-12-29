#ifndef MEASURES__H
#define MEASURES__H

#include <limits>
#include <ratio>
#include <type_traits>

namespace measures
{
    // distance_cast keeps complaining about not knowing distance class.
    template<class _Tag, class _Rep,
	class _Dimension = std::ratio < 1 >>
	class distance;


    // Pour des tags de système identique, on veut la représentation commune et 
    // le greatest common divison pour la dimension.
    // Pour des tags différents, même chose pour la représentation,
    // mais à travailler pour la dimension. 

    // forward declare to use in distance constructor.
    template<class _To, class _Tag, class _Rep, class _Dimension>
    constexpr
    // typename std::enable_if<_Is_distance<_To>::value,
	// _To>::type
    _To distance_cast(const distance<_Tag, _Rep, _Dimension>& dist);

    template<class _Tag, class _Rep, class _Dimension>
    class distance
    {
        using _MyT = distance<_Tag, _Rep, _Dimension>;
        
        public:
        using tag = _Tag;
        using rep = _Rep;
        using dimension = _Dimension;
                
        // constructors
        constexpr distance() = default;
        constexpr explicit distance(const _Rep& rep)
        : m_Rep(rep)
        {
        }

        template<class _Rep2, class _Dimension2>
        constexpr distance(const distance<_Tag, _Rep2, _Dimension2>& dist)
        : m_Rep(distance_cast<distance>(dist).count())
        {
        }

        constexpr _Rep count() const
		{
			return (m_Rep);
		}

        private:
        _Rep m_Rep;

        public:
        // arithmetic

        constexpr typename std::common_type<distance>::type operator+() const {return typename std::common_type<distance>::type(*this);}
        constexpr typename std::common_type<distance>::type operator-() const {return typename std::common_type<distance>::type(-m_Rep);}
        constexpr distance& operator++()      {++m_Rep; return *this;}
        constexpr distance  operator++(int)   {return distance(m_Rep++);}
        constexpr distance& operator--()      {--m_Rep; return *this;}
        constexpr distance  operator--(int)   {return distance(m_Rep--);}

        constexpr distance& operator+=(const distance& __d) {m_Rep += __d.count(); return *this;}
        constexpr distance& operator-=(const distance& __d) {m_Rep -= __d.count(); return *this;}

        constexpr distance& operator*=(const rep& rhs) {m_Rep *= rhs; return *this;}
        constexpr distance& operator/=(const rep& rhs) {m_Rep /= rhs; return *this;}
        constexpr distance& operator%=(const rep& rhs) {m_Rep %= rhs; return *this;}
        constexpr distance& operator%=(const distance& rhs) {m_Rep %= rhs.count(); return *this;}

    };


// Distance +

template <class _Tag1, class _Rep1, class _Period1, class _Tag2, class _Rep2, class _Period2>
inline constexpr
typename std::common_type<distance<_Tag1, _Rep1, _Period1>, distance<_Tag2, _Rep2, _Period2> >::type
operator+(const distance<_Tag1, _Rep1, _Period1>& __lhs, const distance<_Tag2, _Rep2, _Period2>& __rhs)
{
    using _Cd = typename std::common_type<distance<_Tag1, _Rep1, _Period1>, distance<_Tag2, _Rep2, _Period2> >::type;
    return _Cd(_Cd(__lhs).count() + _Cd(__rhs).count());
}

// Distance -

template <class _Tag1, class _Rep1, class _Period1, class _Tag2, class _Rep2, class _Period2>
inline constexpr
typename std::common_type<distance<_Tag1, _Rep1, _Period1>, distance<_Tag2, _Rep2, _Period2> >::type
operator-(const distance<_Tag1, _Rep1, _Period1>& __lhs, const distance<_Tag2, _Rep2, _Period2>& __rhs)
{
    using _Cd = typename std::common_type<distance<_Tag1, _Rep1, _Period1>, distance<_Tag2, _Rep2, _Period2> >::type;
    return _Cd(_Cd(__lhs).count() - _Cd(__rhs).count());
}

    // template<class _Ty>
	// struct _Is_distance
	// 	: std::false_type
	// {	 // tests for distance
	// };

	// template<class _Rep,
	// class _Dimension>
	// struct _Is_distance<distance<_Rep, _Dimension>>
	// 	: std::true_type
	// {	// tests for distance
	// };

	template<
    class _Tag1, class _Rep1, class _Dimension1,
	class _Tag2, class _Rep2, class _Dimension2> inline
		constexpr bool operator == (
			const distance<_Tag1, _Rep1, _Dimension1>& _Left,
			const distance<_Tag2, _Rep2, _Dimension2>& _Right)
	{
        static_assert(std::is_same_v<_Tag1, _Tag2>, 
        "Trying to compare two distances of differents systems. Comparison needs to be defined!");

        using _CT = typename std::common_type<
        distance<_Tag1, _Rep1, _Dimension1>,
        distance<_Tag2, _Rep2, _Dimension2 >>::type;

        return (_CT(_Left).count() == _CT(_Right).count());            
	}

    template<class _To, class _Tag, class _Rep, class _Dimension>
    constexpr
    // typename std::enable_if<_Is_distance<_To>::value,
	// _To>::type
    _To distance_cast(const distance<_Tag, _Rep, _Dimension>& dist)
    {
		using _CommonFactor = std::ratio_divide<_Dimension, typename _To::dimension>;

		using /*template*/ _ToRep = typename _To::rep;
		using /*template*/ _CommonRep = typename std::common_type<_ToRep, _Rep, intmax_t>::type;

		return (_CommonFactor::num == 1 && _CommonFactor::den == 1
			? _To(static_cast<_ToRep>(dist.count()))
			: _CommonFactor::num != 1 && _CommonFactor::den == 1
			? _To(static_cast<_ToRep>(static_cast<_CommonRep>(dist.count()) * static_cast<_CommonRep>(_CommonFactor::num)))
			: _CommonFactor::num == 1 && _CommonFactor::den != 1
			? _To(static_cast<_ToRep>(static_cast<_CommonRep>(dist.count()) / static_cast<_CommonRep>(_CommonFactor::den)))
			: _To(static_cast<_ToRep>(static_cast<_CommonRep>(dist.count()) * static_cast<_CommonRep>(_CommonFactor::num) / static_cast<_CommonRep>(_CommonFactor::den))));        
    }

    // distance /

    template<class _Distance, class _Rep, bool = false/*__is_distance<_Rep>::value*/>
    struct __distance_divide_result
    {
    };
 
    template<class _Distance, class _Rep2,
    bool = std::is_convertible_v<_Rep2, typename std::common_type<typename _Distance::rep, _Rep2>::type>>
    struct __distance_divide_imp
    {
    }; 

    template<class _Tag, class _Rep1, class _Dimension, class _Rep2>
    struct __distance_divide_imp<distance<_Tag, _Rep1, _Dimension>, _Rep2, true>
    {
        using type = distance<_Tag, typename std::common_type<_Rep1, _Rep2>::type, _Dimension>;
    };

    template<class _Tag, class _Rep1, class _Dimension, class _Rep2>
    struct __distance_divide_result<distance<_Tag, _Rep1, _Dimension>, _Rep2> :
    __distance_divide_imp<distance<_Tag, _Rep1, _Dimension>, _Rep2>
    {
    };

    template<class _Tag, class _Rep1, class _Dimension, class _Rep2>
    inline constexpr
    typename __distance_divide_result<distance<_Tag, _Rep1, _Dimension>, _Rep2>::type
    operator / (const distance<_Tag, _Rep1, _Dimension>& _dist, const _Rep2& _s)
    {
        using _Cr = typename std::common_type<_Rep1, _Rep2>::type;
        using _Cd = distance<_Tag, _Cr, _Dimension>;
        return _Cd(_Cd(_dist).count()/static_cast<_Cr>(_s));
    }

    template<class _Tag, class _Rep1, class _Dimension1, class _Rep2, class _Dimension2>
    inline constexpr
    typename std::common_type<_Rep1, _Rep2>::type
    operator / (const distance<_Tag, _Rep1, _Dimension1>& _lhs, const distance<_Tag, _Rep2, _Dimension2>& _rhs)
    {
        using _Ct = typename std::common_type<distance<_Tag, _Rep1, _Dimension1>, distance<_Tag, _Rep2, _Dimension2>>::type;
        return _Ct(_lhs).count() / _Ct(_rhs).count();
    }
}

namespace std
{
    template<class _Tag1, class _Rep1, class _Dimension1, class _Tag2, class _Rep2, class _Dimension2>
    struct common_type<measures::distance<_Tag1, _Rep1, _Dimension1>, measures::distance<_Tag2, _Rep2, _Dimension2>>
    {
	    using type = measures::distance<_Tag1, typename common_type<_Rep1, _Rep2>::type,
		    ratio< __static_gcd<_Dimension1::num, _Dimension2::num>::value,
		 __static_lcm<_Dimension1::den, _Dimension2::den>::value>>;
    };
}

#endif // MEASURES_METRIC_H
