cmake_minimum_required(VERSION 3.13)
project(data-structure)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CC_COMPILER clang)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

add_executable(${PROJECT_NAME} main.cpp header.h data.cpp)

