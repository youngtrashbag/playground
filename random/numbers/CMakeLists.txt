cmake_minimum_required(VERSION 3.13)
project(random-numbers)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

# creating random numbers
set(SRC_FILES_C src/random.cpp src/header.h src/func.cpp)

# processing the numbers
set(SRC_FILES_P src/process.cpp src/header.h src/func.cpp)

add_executable(generate ${SRC_FILES_C})

set(SODIUM_DIR libsodium-1.0.18/src/libsodium/.libs)

# library variable, filename, folder
find_library(LIBSODIUM NAMES libsodium libsodium.so.23 libsodium.so.23.3.0 libsodium.so  ${SODIUM_DIR})
target_link_libraries(generate LINK_PUBLIC ${LIBSODIUM})

# executable for processing
add_executable(process ${SRC_FILES_P})

