#include <limits>
#include <ratio>

namespace measures
{
    template<class _Rep, class _Dimension = std::ratio<1>>
    class distance
    {
        using _MyT = distance<_Rep, _Dimension>;
        
        public:
        using rep = _Rep;
        using dimension = _Dimension;
                
        // constructors
        constexpr distance() = default;
        constexpr explicit distance(const _Rep& rep)
        : m_Rep(rep)
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

	template<class _Rep1,
	class _Dimension1,
	class _Rep2,
	class _Dimension2> inline
		constexpr bool operator == (
			const distance<_Rep1, _Dimension1>& _Left,
			const distance<_Rep2, _Dimension2>& _Right)
	{	// test if dimension == dimension
		using _CT = typename std::common_type <
			distance<_Rep1, _Dimension1>,
			distance<_Rep2, _Dimension2 >> ::type;
		return (_CT(_Left).count() == _CT(_Right).count());
	}

    template<class _To, class _Rep, class _Dimension>
    constexpr
    // typename std::enable_if<_Is_distance<_To>::value,
	// _To>::type
    _To distance_cast(const distance<_Rep, _Dimension>& dist)
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


    namespace metric
    {
        // ratios
        // using ratios defines in ratio header

        // aliases
        //using micrometer = ;
        using millimeters = distance<unsigned long long, std::milli>;
        using meters = distance<unsigned long long>;

        constexpr meters operator ""_m(unsigned long long m)
        {
            return meters(m);
        }
    }

    namespace imperial
    {
        // ratios
        using inches_in_feet = std::ratio<1, 12>;
        using foots_in_yard = std::ratio<1, 3>;
        
        //12 inches = 1 foot
		//3 feet = 1 yard
		//220 yards = 1 furlong
		//8 furlongs = 1 mile
		//5280 feet = 1 mile
		//1760 yards = 1 mile

        //aliases
    }
}
