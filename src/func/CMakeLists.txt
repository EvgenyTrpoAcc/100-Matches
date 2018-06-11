cmake_minimum_required(VERSION 2.8)

project(func)

set(SOURCE_LIB func.cpp)

add_library(func STATIC ${SOURCE_LIB})
