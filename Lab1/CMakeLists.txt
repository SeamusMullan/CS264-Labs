cmake_minimum_required(VERSION 3.10)
project(MultiExe)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# For each source file, create an executable
foreach(SRC_FILE ${SRC_FILES})
    # Extract filename without extension
    get_filename_component(EXE_NAME ${SRC_FILE} NAME_WE)

    # Create an executable with that name
    add_executable(${EXE_NAME} ${SRC_FILE})
endforeach()

