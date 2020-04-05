cmake_minimum_required(VERSION 3.13)

project(numerology-analysis)

# C++ Configuration
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

set(
    SOURCE_FILES
    main.cpp
    header.h
    functions.cpp
    date.cpp
)

add_executable(numerology ${SOURCE_FILES})

