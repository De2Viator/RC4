cmake_minimum_required(VERSION 3.29)
project(RC4)

set(CMAKE_CXX_STANDARD 26)

add_executable(RC4 main.cpp
        RC4.cpp
        RC4.h)
