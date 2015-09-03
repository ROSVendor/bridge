cmake_minimum_required(VERSION 3.2)
project(bridge)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -g")
include_directories(.)

# 核心模块的默认实现
add_library(bridgedefault SHARED lib/_logger.c lib/_error.c lib/_memory.c lib/_io.c)

# Bridge
add_library(bridge        SHARED lib/bridge.c)
target_link_libraries(bridge bridgedefault)

# Bridge.Error
add_library(bridgeerror   SHARED lib/error.c)
target_link_libraries(bridgeerror bridgedefault)


# Bridge.Memory
add_library(bridgememory  SHARED lib/memory.c)
target_link_libraries(bridgememory bridgedefault)


# Bridge.Logger
add_library(bridgelogger  SHARED lib/logger.c)
target_link_libraries(bridgelogger bridgedefault)


add_executable(test.main test/main.c)
target_link_libraries(test.main bridge)

add_executable(test.io test/io.c)
target_link_libraries(test.io bridge)