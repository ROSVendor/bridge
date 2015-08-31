cmake_minimum_required(VERSION 3.2)
project(bridge)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
include_directories(.)

add_library(libbridge SHARED lib/bridge.c)

