# Add the core library
add_library(core
    src/core.cpp
    include/core.h
)

# Include directories for the core library
target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)