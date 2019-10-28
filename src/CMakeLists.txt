cmake_minimum_required(VERSION 3.7)

file(GLOB source_files "*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(starter ${source_files})
