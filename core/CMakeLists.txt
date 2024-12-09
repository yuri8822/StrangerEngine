# Add the core library
add_library(core
    src/core.cpp
    src/renderer.cpp
)

# Link libraries
target_link_libraries(core PRIVATE
    ${SDL2_LIBRARIES}
    OpenGL::GL
    glad
)

# Include directories
target_include_directories(core PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_SOURCE_DIR}/external/glad/include
)