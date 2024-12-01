# Add the executable
add_executable(editor
    src/main.cpp
)

# Link libraries
target_link_libraries(editor
    PRIVATE
    ${SDL2_LIBRARIES}
    OpenGL::GL
    glad
    imgui
    core  # Link the core library
)

# Include directories
target_include_directories(editor PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_SOURCE_DIR}/external/glad/include
    ${CMAKE_SOURCE_DIR}/external/Imgui
    ${CMAKE_SOURCE_DIR}/external/Imgui/backends
)