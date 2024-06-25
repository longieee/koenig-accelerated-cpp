cmake_minimum_required(VERSION 3.8...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(
    Exercise5-1 VERSION 1.0
    DESCRIPTION "Koenig's Accelerated C++ Chapter 5 Exercise 5.1 - Building a Permuted Index"
    LANGUAGES CXX
)
# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include the directories
include_directories(${PROJECT_SOURCE_DIR}/header)

# Add the executable
file(GLOB SOURCE_FILES "source/*.cpp")

add_executable(create_permutation_index "main.cpp" ${SOURCE_FILES})
target_link_libraries(create_permutation_index)