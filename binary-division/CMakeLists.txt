cmake_minimum_required(VERSION 3.13)
project(binary-long-division)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

set(PROJECT_FILES
	main.cpp
	header.h
	argument.cpp
	division.cpp
	)

add_executable(${PROJECT_NAME} ${PROJECT_FILES}) 

