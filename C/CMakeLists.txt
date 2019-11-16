cmake_minimum_required(VERSION 3.15)
project(TSanTest)

find_library(PTHREAD_LIBRARY pthread)

set(CMAKE_CXX_STANDARD 11)

add_executable(TSanTest example2.c example4.c example5.c example3.c example6.c)

target_link_libraries(TSanTest ${PTHREAD_LIBRARY})