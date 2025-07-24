# Add the executable
add_executable(editor
    src/main.cpp
    src/editor.cpp
)

# Link libraries
target_link_libraries(editor
    PRIVATE
    core  # Link the core library
    imgui
)

# Include directories
target_include_directories(editor PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/editor/include
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_SOURCE_DIR}/external/glad/include
    ${CMAKE_SOURCE_DIR}/external/Imgui
    ${CMAKE_SOURCE_DIR}/external/Imgui/backends
)