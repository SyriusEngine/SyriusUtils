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

set(CMAKE_POSITION_INDEPENDENT_CODE ON) # Needed to link this static lib into a dynamic lib

set(SYRIUS_UTILS_HEADERS
    include/SyriusUtils/SyriusUtils.hpp
    include/SyriusUtils/PlatformDetection.hpp
    include/SyriusUtils/ResourceView.hpp
    include/SyriusUtils/ExportUtils.hpp
    include/SyriusUtils/Logger/Conditions.hpp

    include/SyriusUtils/Types/Types.hpp
    include/SyriusUtils/Types/SymbolicTypes.hpp

    include/SyriusUtils/Logger/Logger.hpp
    include/SyriusUtils/Logger/LoggerDefs.hpp
    include/SyriusUtils/Logger/LoggerMacros.hpp
    include/SyriusUtils/Random.hpp
    include/SyriusUtils/Clock/Clock.hpp
    include/SyriusUtils/Clock/TimeProfiler.hpp
    include/SyriusUtils/Clock/ClockMacros.hpp
    include/SyriusUtils/MemoryProfiler.hpp
    include/SyriusUtils/Srstl/Srstl.hpp
    include/SyriusUtils/Srstl/KeyVector.hpp
    include/SyriusUtils/DevUtils/TestingMacros.hpp
    include/SyriusUtils/Math.hpp
    include/SyriusUtils/Conversions/FromString.hpp
    include/SyriusUtils/Conversions/ToString.hpp
)

set(SYRIUS_UTILS_SRC
    src/SyriusUtils.cpp

    src/Types/SymbolicTypes.cpp

    src/Logger/Logger.cpp
    src/Logger/LoggerDefs.cpp
    src/Random.cpp
    src/Clock/Clock.cpp
    src/Clock/TimeProfiler.cpp
    src/MemoryProfiler.cpp
    src/Conversions/FromString.cpp
    src/Conversions/ToString.cpp)

set(SYRIUS_UTILS_TEST_SRC
    ${SYRIUS_UTILS_SRC}
    test/TestTypes.cpp
    test/Logger/TestLogger.cpp
    test/Logger/TestConditions.cpp
    test/TestUtils.cpp
    test/Srstl/TestKeyVector.cpp
    test/Conversions/TestFromString.cpp
    test/Conversions/TestToString.cpp
)

fetch_fmt()

set(SYRIUS_UTILS_LIBS
    fmt
)

add_library(SyriusUtils STATIC ${SYRIUS_UTILS_HEADERS} ${SYRIUS_UTILS_SRC})
target_include_directories(SyriusUtils PUBLIC include)
target_link_libraries(SyriusUtils PUBLIC ${SYRIUS_UTILS_LIBS})

if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND BUILD_TESTS)
    # Add GTest
    fetch_gtest()

    enable_testing()
    add_compile_definitions(SR_TESTING)

    message(STATUS "Building tests")

    add_executable(TestSyriusUtils ${SYRIUS_UTILS_TEST_SRC})
    add_dependencies(TestSyriusUtils SyriusUtils gtest)

    target_link_libraries(TestSyriusUtils PUBLIC SyriusUtils GTest::gtest GTest::gtest_main)

    add_test(NAME CTestSyriusUtils COMMAND ${PROOT} $<TARGET_FILE:TestSyriusUtils>)
    set_tests_properties(CTestSyriusUtils PROPERTIES
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif ()






