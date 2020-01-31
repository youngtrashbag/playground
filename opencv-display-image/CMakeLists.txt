cmake_minimum_required(VERSION 3.13)
project(display-image)

# Libraries
find_package(OpenCV REQUIRED)

# C++ Configuration
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

# Variables
set(SOURCE_FILES src/open.cpp src/header.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link Libraries with executable
target_link_libraries(${PROJECT_NAME}  ${OpenCV_LIBS})

