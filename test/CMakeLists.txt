set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)

add_executable(test.main main.c)
target_link_libraries(test.main core)

add_executable(test.io io.c)
target_link_libraries(test.io core)

add_executable(test.logger logger.c)
target_link_libraries(test.logger core)

add_executable(test.modloader modloader.c)
target_link_libraries(test.modloader core)
