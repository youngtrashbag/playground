cmake_minimum_required(VERSION 3.13)
project(random-picker)

# C executable
set(CMAKE_CC_STANDARD 11)
set(CMAKE_CC_COMPILER clang)

add_executable(${PROJECT_NAME}-c11 main.c)

# C++ executable
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

add_executable(${PROJECT_NAME}-cpp14 main.cpp)

set(SODIUM_DIR libsodium-1.0.18/src/libsodium/.libs)

# library variable, filename, folder
find_library(LIBSODIUM NAMES libsodium libsodium.so.23 libsodium.so.23.3.0 libsodium.so  ${SODIUM_DIR})
target_link_libraries(${PROJECT_NAME}-c11 LINK_PUBLIC ${LIBSODIUM})
target_link_libraries(${PROJECT_NAME}-cpp14 LINK_PUBLIC ${LIBSODIUM})

