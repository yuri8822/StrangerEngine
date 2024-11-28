# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(StrangerEngine VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the Qt library
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Enable AUTOMOC
set(CMAKE_AUTOMOC ON)

# Add subdirectories
add_subdirectory(core)
add_subdirectory(editor)