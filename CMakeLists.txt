cmake_minimum_required(VERSION 3.5.1)
project(poolprog)
set(CMAKE_BUILD_TYPE Release)
include_directories(include)

add_subdirectory(src)
add_executable(static_pool main.c)

target_link_libraries (static_pool threadpool)

