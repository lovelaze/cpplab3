cmake_minimum_required(VERSION 2.8.4)
project(game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES
    "*.h"
    "*.cpp"
    )

add_executable(game ${SOURCE_FILES})