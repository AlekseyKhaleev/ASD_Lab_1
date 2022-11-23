cmake_minimum_required(VERSION 3.23)
project(ASD_Lab_1)

set(CMAKE_CXX_STANDARD 17)

find_path (LIB_INCLUDES classes.h functions.h C:/Users/user/Desktop/3_semestr/ASD_Lab_1/headers)
include_directories(${LIB_INCLUDES})

add_executable(ASD_Lab_1 main.cpp functions.cpp)
