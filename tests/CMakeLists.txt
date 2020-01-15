cmake_minimum_required(VERSION 3.8)

set(This test_measures)

set(Sources
    tests.cpp
    tests_unit.cpp
    tests_unit_metric.cpp
    tests_unit_imperial.cpp
    tests_unit_conversions.cpp
    tests_playground.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    measures
)

add_test(
    NAME ${This}
    COMMAND ${This}
)