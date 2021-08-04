cmake_minimum_required(VERSION 3.16)
project(brainf VERSION 0.0.1 LANGUAGES C)

add_definitions(-Wall)
include_directories(brainf PRIVATE "include/")

add_library(stack STATIC
			src/stack.c
			include/stack.h
)

add_executable(brainf src/main.c)
target_link_libraries(brainf stack)
