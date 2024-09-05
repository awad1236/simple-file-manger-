cmake_minimum_required(VERSION 3.28)
project(filemanger_with_c C)

set(CMAKE_C_STANDARD 11)

add_executable(filemanger_with_c
        main.c
        operations.h
        operations.cpp
        operations.c
        operations.c)
