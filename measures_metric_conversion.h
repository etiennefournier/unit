#include "measures_metric.h"
#include "measures_imperial.h"

namespace measures
{
    using namespace metric;
    using namespace imperial;
    
    using thous_in_micrometers = std::ratio<5,127>;

    // Duration equality operator works by casting left and right arguments to their common type
    // and comparing their count.
    // Comparison between two differents systems won't have a common type, hence the need to implement
    // the logic in the equality operator.

    template<
    class _Rep1, class _Dimension1,
	class _Rep2, class _Dimension2> inline
		constexpr bool operator == (
			const distance<imperial_tag, _Rep1, _Dimension1>& _Left,
			const distance<metric_tag , _Rep2, _Dimension2>& _Right)
	{
        return (distance_cast<thous>(_Left) / thous_in_micrometers::num).count() == 
        (distance_cast<micrometers>(_Right) / thous_in_micrometers::den).count();
	}

        template<
    class _Rep1, class _Dimension1,
	class _Rep2, class _Dimension2> inline
		constexpr bool operator == (
			const distance<measures::metric::metric_tag    , _Rep1, _Dimension1>& _Left,
			const distance<measures::imperial::imperial_tag, _Rep2, _Dimension2>& _Right)
	{
        return _Right == _Left;
	}
}