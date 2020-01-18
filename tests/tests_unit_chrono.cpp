#include <gtest/gtest.h>

#include "../unit_chrono.h"

using namespace unit::chrono;
// using namespace std::unit;

constexpr auto year = 31556952ll; // seconds in average Gregorian year

using shakes = duration<int, std::ratio<1, 100000000>>;
using jiffies = duration<int, std::centi>;
using microfortnights = duration<float, std::ratio<14*24*60*60, 1000000>>;
using nanocenturies = duration<float, std::ratio<100*year, 1000000000>>;

TEST(chrono, cppreference)
{
    seconds sec(1);
 
    EXPECT_EQ(sec,  microseconds(1000000));
    EXPECT_EQ(sec, shakes(100000000));
    EXPECT_EQ(sec, jiffies(100));
    EXPECT_EQ(duration_cast<minutes>(sec), minutes(0));
    EXPECT_FLOAT_EQ(microfortnights(sec).count(), 0.82671958f);
    EXPECT_FLOAT_EQ(nanocenturies(sec).count(), 0.31688738f);
}