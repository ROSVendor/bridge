cmake_minimum_required(VERSION 3.2)
project(bridge)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall")
include_directories(.)

add_library(libbridge SHARED lib/bridge.c lib/_error.c lib/_memory.c)
add_library(libbridgeerror SHARED lib/error.c lib/_error.c)
add_library(libbridgemem   SHARED lib/memory.c lib/_memory.c)

