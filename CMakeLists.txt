cmake_minimum_required(VERSION 3.23)
project(ASD_Lab_1)

set(CMAKE_CXX_STANDARD 17)

find_path (LIB_INCLUDES classes.h /home/kristofer/ASD_Lab_1/headers)
include_directories(${LIB_INCLUDES})

add_executable(ASD_Lab_1 main.cpp)
