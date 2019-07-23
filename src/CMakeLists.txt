cmake_minimum_required(VERSION 3.5)
include_directories(../include)

file(GLOB SOURCES "*.c")
add_library(threadpool SHARED ${SOURCES})

target_link_libraries (threadpool pthread)

