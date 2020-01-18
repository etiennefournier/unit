cmake_minimum_required(VERSION 3.8)

set(This test_unit)

set(Sources
    tests_unit.cpp
    tests_unit_metric.cpp
    tests_unit_imperial.cpp
    tests_unit_conversions.cpp
    tests_unit_chrono.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    unit
)

add_test(
    NAME ${This}
    COMMAND ${This}
)