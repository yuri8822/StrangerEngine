# Add the runtime executable
add_executable(runtime
    src/main.cpp
)

# Link libraries
target_link_libraries(runtime
    PRIVATE
    core  # Link the core library
)

# Include directories
target_include_directories(runtime PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_SOURCE_DIR}/external/glad/include
)