#ifndef MEASURES__H
#define MEASURES__H

#include <limits>
#include <ratio>

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
    };

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
	{	// test if dimension == dimension
		using _CT = typename std::common_type <
			distance<_Tag1, _Rep1, _Dimension1>,
			distance<_Tag2, _Rep2, _Dimension2 >> ::type;
            // auto a = _CT(_Left).count();
            // auto b = _CT(_Right).count();
            // return a == b;
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
