cmake_minimum_required(VERSION 2.8)
project(insertsort)

set(cmake_build_type debug)
set(cmake_cxx_flags "-std=c++11 -O3")

add_executable(main main.cpp)