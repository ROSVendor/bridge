set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_SUFFIX .so)

# Default
add_library(default _logger.c _error.c _memory.c _io.c _modloader.cpp)

# Bridge.Core
add_library(core bridge.c)
target_link_libraries(core default)

# Bridge.Error
add_library(error   SHARED error.c)
target_link_libraries(error default)


# Bridge.Memory
add_library(memory  SHARED memory.c)
target_link_libraries(memory default)

# Bridge.Logger
add_library(logger  SHARED logger.c)
target_link_libraries(logger default)

# Bridge.IO
add_library(io SHARED io.c)
target_link_libraries(io default)

# Bridge.ModLoader
add_library(modloader modloader.c)
target_link_libraries(modloader default)

# 安装
install(TARGETS error memory logger io modloader
    LIBRARY DESTINATION lib/bridge
    ARCHIVE DESTINATION lib/bridge)
