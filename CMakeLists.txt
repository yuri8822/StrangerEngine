# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(StrangerEngine VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set SDL2 paths
set(SDL2_PATH "C:/msys64/mingw64")
set(CMAKE_MODULE_PATH "${SDL2_PATH}/share/cmake/Modules")

# Find packages
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

# Add subdirectories
add_subdirectory(core)
add_subdirectory(editor)
add_subdirectory(runtime)
add_subdirectory(external/imgui)
add_subdirectory(external/glad)