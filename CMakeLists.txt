cmake_minimum_required(VERSION 3.0.0)
project(unit VERSION 0.1.0)

set(CMAKE_C_STRANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(CTest)
enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)
add_library(unit unit.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
