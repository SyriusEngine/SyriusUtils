cmake_minimum_required(VERSION 3.16)
project(SyriusUtils)

include(FetchContent)

# Check if SyriusBuildUtils has been initialized
if (NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/SyriusBuildUtils/CMakeUtils.cmake")
    message("SyriusBuildUtils not found, cloning from git...")
    execute_process(COMMAND git submodule init
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE INIT_RESULT)
    if(INIT_RESULT)
        message(FATAL_ERROR "Failed to init SyriusBuildUtils")
    endif()
    execute_process(COMMAND git submodule update
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE UPDATE_RESULT)
    if(UPDATE_RESULT)
        message(FATAL_ERROR "Failed to update SyriusBuildUtils")
    endif()
else()
    message(STATUS "SyriusBuildUtils found!")
endif()
include(SyriusBuildUtils/CMakeUtils.cmake)

set(SYRIUS_UTILS_HEADERS
    include/SyriusUtils/SyriusUtils.hpp
    include/SyriusUtils/PlatformDetection.hpp
    include/SyriusUtils/ResourceView.hpp
    include/SyriusUtils/ExportUtils.hpp
    include/SyriusUtils/Conditions.hpp

    include/SyriusUtils/Types/Types.hpp
    include/SyriusUtils/Types/SymbolicTypes.hpp

    include/SyriusUtils/Logger/Logger.hpp
    include/SyriusUtils/Logger/LoggerDefs.hpp
    include/SyriusUtils/Logger/LoggerMacros.hpp
    include/SyriusUtils/Random.hpp
)

set(SYRIUS_UTILS_SRC
    src/SyriusUtils.cpp

    src/Types/SymbolicTypes.cpp

    src/Logger/Logger.cpp
    src/Logger/LoggerDefs.cpp
    src/Random.cpp)

set(SYRIUS_UTILS_TEST_SRC
    ${SYRIUS_UTILS_SRC}
    test/TestTypes.cpp
    test/TestTypes.hpp
    test/Logger/TestLogger.cpp
    test/TestRandom.cpp
    test/TestRandom.hpp
)

add_library(SyriusUtils STATIC ${SYRIUS_UTILS_HEADERS} ${SYRIUS_UTILS_SRC})
target_include_directories(SyriusUtils PUBLIC include)

if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND BUILD_TESTS)
    # Add GTest
    fetch_gtest()

    message(STATUS "Building tests")

    add_executable(TestSyriusUtils ${SYRIUS_UTILS_TEST_SRC})
    add_dependencies(TestSyriusUtils gtest)

    target_link_libraries(TestSyriusUtils GTest::gtest GTest::gtest_main)
endif ()






