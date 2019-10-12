cmake_minimum_required(VERSION 3.7)
project(starter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src)

add_subdirectory(src)
