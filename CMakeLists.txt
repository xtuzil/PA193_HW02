cmake_minimum_required(VERSION 3.17)
project(HW02)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW02 main.cpp)

set(CMAKE_CXX_FLAGS "-fno-stack-protector -Wall -Wextra -g")
