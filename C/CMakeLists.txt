cmake_minimum_required(VERSION 3.15)
project(TSanTest)

find_library(PTHREAD_LIBRARY pthread)

set(CMAKE_CXX_STANDARD 14)

add_executable(TSanTest example1.c example2.c example3.c example4.c example5.c example7.cpp)

target_link_libraries(TSanTest ${PTHREAD_LIBRARY})