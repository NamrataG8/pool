cmake_minimum_required(VERSION 3.5.1)
project(poolprog)
set(CMAKE_BUILD_TYPE Release)
include_directories(include)

file(GLOB SOURCES "src/*.c")
add_library(mypool STATIC ${SOURCES})

add_executable(static_pool ${SOURCES})
target_link_libraries (static_pool -lpthread)



