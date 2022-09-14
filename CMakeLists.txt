cmake_minimum_required(VERSION 3.10.2)
project(coverage)

add_library(lib_under_test lib_under_test.cpp)

set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.8.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(lib_tests tests.cpp)
target_link_libraries(lib_tests lib_under_test gtest)
target_include_directories(lib_tests PRIVATE ${GTEST_INCLUDE_DIRS})
add_test(Lib.Test lib_tests)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    APPEND_COVERAGE_COMPILER_FLAGS()
    setup_target_for_coverage_lcov(
            NAME coverage
            EXECUTABLE ctest -j8
            DEPENDENCIES lib_tests)
endif()
