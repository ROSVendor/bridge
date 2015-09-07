cmake_minimum_required(VERSION 3.2)
project(bridge)

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)

# 核心模块的默认实现
add_subdirectory(lib      ${CMAKE_BINARY_DIR}/lib/bridge)

# 默认支持的语言
add_subdirectory(language ${CMAKE_BINARY_DIR}/lib/language)

# 测试例程
add_subdirectory(test     ${CMAKE_BINARY_DIR}/test)

