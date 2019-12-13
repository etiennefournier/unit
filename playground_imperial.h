#ifndef PLAYGROUND_IMPERIAL
#define PLAYGROUND_IMPERIAL

#include "playground.h"

namespace playground
{
    struct imperial_tag{};
    using imperial = distance<std::ratio<3,1>, imperial_tag>;
}

#endif // PLAYGROUND_IMPERIAL