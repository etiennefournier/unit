#ifndef MEASURES_IMPERIAL_H
#define MEASURES_IMPERIAL_H

#include "measures.h"

namespace measures::imperial
{
    // tag
    struct imperial_tag{};

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
    using yards  = distance<imperial_tag, unsigned long long>;
    using foots  = distance<imperial_tag, unsigned long long, std::ratio_multiply<yards::dimension, foots_in_yard>>;
    using inches = distance<imperial_tag, unsigned long long, std::ratio_multiply<foots::dimension, inches_in_feet>>;
} // namespace imperial

#endif // MEASURES_IMPERIAL_H