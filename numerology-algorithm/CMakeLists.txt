cmake_minimum_required(VERSION 3.13)

project(numerology-analysis)

# C++ Configuration
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

set(
    SOURCE_FILES
    src/main.cpp
    src/header.h
    src/functions.cpp
)

add_executable(${PROJECT_NAME}, ${SOURCE_FILES})
