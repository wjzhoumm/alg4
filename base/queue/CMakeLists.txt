# cmake needs this line
cmake_minimum_required(VERSION 2.8)

# Define project name
project(queue)
set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

add_executable(main main.cpp)