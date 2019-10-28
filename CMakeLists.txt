cmake_minimum_required(VERSION 3.7)
project(starter)
SET(CMAKE_CXX_FLAGS -pthread)

include_directories(src)

add_subdirectory(src)
