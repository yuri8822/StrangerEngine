cmake_minimum_required(VERSION 3.10)
project(GLAD)

# Add source files
set(GLAD_SRC
    src/glad.c
)

# Create a library target
add_library(glad STATIC ${GLAD_SRC})

# Include directories
target_include_directories(glad PUBLIC include)