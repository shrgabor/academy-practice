cmake_minimum_required(VERSION 3.7)

set(SOURCES
        main.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(starter ${SOURCES})
