cmake_minimum_required(VERSION 3.8...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(
    Exercise5-1 VERSION 1.0
    DESCRIPTION "Koenig's Accelerated C++ Chapter 5 Exercise 5.1 - Building a Permuted Index"
    LANGUAGES CXX
)

# Set C++11 standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Gtest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

# Add the executable
file(GLOB SOURCE_FILES "source/*.cpp")

add_executable(create_permutation_index "main.cpp" ${SOURCE_FILES})
target_link_libraries(create_permutation_index)

# Tests
enable_testing()

add_executable(
    permutation_index_test
    tests/test_permutation_index.cpp
    ${SOURCE_FILES}
)
target_link_libraries(
    permutation_index_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(permutation_index_test)