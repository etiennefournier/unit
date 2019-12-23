#ifndef MEASURES_METRIC_H
#define MEASURES_METRIC_H

#include <iostream>
#include "measures.h"

namespace measures::metric
{
    // tag
    struct metric_tag{};

    // ratios
    // using ratios defines in ratio header

    // aliases
    using nanometers  = distance<metric_tag, long long, std::nano>;
    using micrometers = distance<metric_tag, long long, std::micro>;
    using millimeters = distance<metric_tag, long long, std::milli>;
    using meters      = distance<metric_tag, long long>;

    constexpr meters operator""_m(unsigned long long m)
    {
        return meters(static_cast<meters::rep>(m));
    }

    std::ostream& operator<<(std::ostream& os, const meters& m)
    {
            return os << m.count() << " meters";
    }
} // namespace metric

#endif // MEASURES_METRIC_H