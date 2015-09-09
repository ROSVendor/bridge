set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_SUFFIX .so)

# Bridge.Foundation
add_library(foundation _logger.c _error.c _runtime.cpp _memory.c _io.c)

# Bridge.Runtime
add_library(runtime runtime.c)
target_link_libraries(runtime foundation)

# Bridge.ModLoader
add_library(modloader modloader.c _modloader.cpp)
target_link_libraries(modloader foundation)

# Bridge.Error
add_library(error   SHARED error.c)
target_link_libraries(error foundation)

# Bridge.Memory
add_library(memory  SHARED memory.c)
target_link_libraries(memory foundation)

# Bridge.Logger
add_library(logger  SHARED logger.c)
target_link_libraries(logger foundation)

# Bridge.IO
add_library(io SHARED io.c)
target_link_libraries(io foundation)

# Bridge - Exposed
add_library(core bridge.c)
target_link_libraries(core foundation modloader runtime)

# 安装
install(TARGETS error memory logger io modloader
    LIBRARY DESTINATION lib/bridge/bridge
    ARCHIVE DESTINATION lib/bridge/bridge)
