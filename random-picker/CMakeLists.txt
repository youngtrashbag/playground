cmake_minimum_required(VERSION 3.13)
project(random-picker)

set(CMAKE_CC_STANDARD 11)
set(CMAKE_CC_COMPILER clang)
set(SODIUM_DIR libsodium-1.0.18/src/libsodium/.libs)

add_executable(${PROJECT_NAME} main.c)

# library variable, filename, folder
find_library(LIBSODIUM NAMES libsodium libsodium.so.23 libsodium.so.23.3.0 libsodium.so  ${SODIUM_DIR})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${LIBSODIUM})

