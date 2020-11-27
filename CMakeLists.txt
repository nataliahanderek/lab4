cmake_minimum_required( VERSION 3.0 )

project(lab_3)

include_directories( ./src ./test ./include )

add_executable(test ./test/lab3.cpp ./include/matrix.hpp ./src/matrix.cpp)