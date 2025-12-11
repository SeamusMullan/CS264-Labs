cmake_minimum_required(VERSION 3.10)
project(CS264-Lab5)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Build the ModuleManagement executable
add_executable(ModuleManagement
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/Module.cpp
    ${SRC_DIR}/Module.h
    ${SRC_DIR}/Placement.cpp
    ${SRC_DIR}/Placement.h
    ${SRC_DIR}/Programme.cpp
    ${SRC_DIR}/Programme.h
)
