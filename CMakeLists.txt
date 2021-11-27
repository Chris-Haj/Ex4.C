cmake_minimum_required(VERSION 3.20)
project(Ex4 C)

set(CMAKE_C_STANDARD 99)

add_executable(Ex4 main.c StudentList.c GradesOperations.h GradesOperations.c)
