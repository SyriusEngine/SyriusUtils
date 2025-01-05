include(ExternalProject)

cmake_minimum_required(VERSION 3.16)
project(SyriusUtils)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building in Debug Mode")
    add_compile_definitions(SR_CORE_DEBUG)
else()
    message(STATUS "Building in Release Mode")
endif()

message(${CMAKE_CURRENT_LIST_DIR})

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/SyriusBuildUtils/CMakeUtils.cmake")
    message(STATUS "Initializing submodule SyriusBuildUtils...")
    execute_process(COMMAND git submodule update --init --remote --recursive
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE result)
    if(result)
        message(FATAL_ERROR "Failed to initialize SyriusBuildUtils!")
    endif()
else()
    message(STATUS "Submodule SyriusBuildUtils already initialized.")
endif()