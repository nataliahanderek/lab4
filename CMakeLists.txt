cmake_minimum_required( VERSION 3.0 )

project(lab_3)

include_directories( ./src ./test ./include)

add_executable(test ./src/lab3.cpp ./src/matrix.cpp )