include_directories(include)

execute_process(COMMAND python3 setup.py build
                WORKING_DIRECTORY bridge.py/)

