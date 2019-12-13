#ifndef PLAYGROUND_METRIC
#define PLAYGROUND_METRIC

#include "playground.h"

namespace playground
{
    struct metric_tag{};
    using metric = distance<std::ratio<1>, metric_tag>;
} // namespace playground

#endif //PLAYGROUND_METRIC