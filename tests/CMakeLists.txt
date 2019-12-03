cmake_minimum_required(VERSION 3.8)

set(This test_measures)

set(Sources
    tests.cpp
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