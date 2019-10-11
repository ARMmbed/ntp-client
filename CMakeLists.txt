cmake_minimum_required(VERSION 2.8.3)

project(mbed_ntp_client)

FILE(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.c*")
FILE(GLOB_RECURSE ${PROJECT_NAME}_INCLUDES "include/*.h*")

install(DIRECTORY include
    DESTINATION src/${PROJECT_NAME}
    FILES_MATCHING PATTERN "*.h*"
    PATTERN "*~" EXCLUDE
)
    
install(DIRECTORY src
    DESTINATION src/${PROJECT_NAME}
    FILES_MATCHING PATTERN "*.c*"
    PATTERN "*~" EXCLUDE
)
