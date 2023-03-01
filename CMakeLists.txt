cmake_minimum_required(VERSION 3.24)
project(c_correction C)

set(CMAKE_C_STANDARD 11)

add_executable(c_correction main.c Pair.c Pair.h List.c List.h stack.c stack.h Queue.c Queue.h)
