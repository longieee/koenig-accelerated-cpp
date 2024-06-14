cmake_minimum_required(VERSION 3.8...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(
    MyProject VERSION 1.0
    DESCRIPTION "Koenig's Accelerated C++ Chapter 4 Exercise 4.5"
    LANGUAGES CXX
)

add_executable(4-5.out main.cpp WordCounter.cpp)