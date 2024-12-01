# Add the core library
add_library(core
    src/core.cpp
    src/renderer.cpp
)

# Set SDL2 paths
set(SDL2_PATH "C:/msys64/mingw64")
set(CMAKE_MODULE_PATH "${SDL2_PATH}/share/cmake/Modules")

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Link libraries
target_link_libraries(core
    PRIVATE
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