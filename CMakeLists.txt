cmake_minimum_required(VERSION 3.20)
project(c_star C)

set(CMAKE_C_STANDARD 99)

add_executable(c_star main.c Base64.h Base64.c)
