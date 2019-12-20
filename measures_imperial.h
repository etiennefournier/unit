#ifndef MEASURES_IMPERIAL_H
#define MEASURES_IMPERIAL_H

#include "measures.h"

namespace measures::imperial
{
    // tag
    struct imperial_tag{};

    // ratios
    using thous_in_inch     = std::ratio<1000, 1>;
    using inches_in_foot    = std::ratio<12, 1>;
    using feet_in_yard      = std::ratio<3, 1>;
    using yards_in_chain    = std::ratio<22, 1>;
    using chains_in_furlong = std::ratio<10, 1>;
    using furlongs_in_mile  = std::ratio<8, 1>;
    using miles_in_league   = std::ratio<3, 1>;

    //aliases
    using yards    = distance<imperial_tag, unsigned long long>;

    using feet     = distance<imperial_tag, unsigned long long, std::ratio_divide<yards::dimension , feet_in_yard>>;
    using inches   = distance<imperial_tag, unsigned long long, std::ratio_divide<feet::dimension  , inches_in_foot>>;
    using thous    = distance<imperial_tag, unsigned long long, std::ratio_divide<inches::dimension, thous_in_inch>>;
  
    using chains   = distance<imperial_tag, unsigned long long, std::ratio_multiply<yards::dimension   , yards_in_chain>>;
    using furlongs = distance<imperial_tag, unsigned long long, std::ratio_multiply<chains::dimension  , chains_in_furlong>>;
    using miles    = distance<imperial_tag, unsigned long long, std::ratio_multiply<furlongs::dimension, furlongs_in_mile>>;
    using leagues  = distance<imperial_tag, unsigned long long, std::ratio_multiply<miles::dimension   , miles_in_league>>;
} // namespace imperial

#endif // MEASURES_IMPERIAL_H