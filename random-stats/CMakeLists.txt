cmake_minimum_required(VERSION 3.13)
project(random-stats)

# C++ executable
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

# Files
set(SOURCE_FILES src/header.h src/func.cpp src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(SODIUM_DIR libsodium-1.0.18/src/libsodium/.libs)

# library variable, filename, folder
find_library(LIBSODIUM NAMES libsodium libsodium.so.23 libsodium.so.23.3.0 libsodium.so  ${SODIUM_DIR})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${LIBSODIUM})

