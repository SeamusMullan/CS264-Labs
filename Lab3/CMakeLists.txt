cmake_minimum_required(VERSION 3.10)
project(CS264-Lab3)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Build the TestMatrix executable with Matrix.cpp
add_executable(TestMatrix 
    ${SRC_DIR}/TestMatrix.cpp 
    ${SRC_DIR}/Matrix.cpp
    ${SRC_DIR}/Matrix.h
)
