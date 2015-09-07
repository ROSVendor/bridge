include_directories(include)

execute_process(COMMAND python3 setup.py build
                WORKING_DIRECTORY bridge.py/)

add_library(python3 interface/Python3.c)

install(TARGETS python3
    LIBRARY DESTINATION lib/bridge/language
    ARCHIVE DESTINATION lib/bridge/language)
