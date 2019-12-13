#ifndef MEASURES_METRIC_H
#define MEASURES_METRIC_H

#include "measures.h"

namespace measures::metric
{
    // ratios
    // using ratios defines in ratio header

    // aliases
    using nanometers = distance<unsigned long long, std::nano>;
    using micrometers = distance<unsigned long long, std::micro>;
    using millimeters = distance<unsigned long long, std::milli>;
    using meters = distance<unsigned long long>;

    constexpr meters operator""_m(unsigned long long m)
    {
        return meters(m);
    }
} // namespace metric

#endif // MEASURES_METRIC_H