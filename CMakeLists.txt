cmake_minimum_required(VERSION 2.8)

project(hello)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_EXE test/main-test.cpp)

include_directories(src/func)

add_executable(test ${SOURCE_EXE})

add_subdirectory(src/func)

target_link_libraries(test func gtest sfml-window sfml-system sfml-graphics)

