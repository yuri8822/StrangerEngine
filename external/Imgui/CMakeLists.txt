# Add source files
set(IMGUI_SRC
    imgui.cpp
    imgui_draw.cpp
    imgui_demo.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    backends/imgui_impl_sdl2.cpp
    backends/imgui_impl_opengl3.cpp
)

# Create a library target
add_library(imgui STATIC ${IMGUI_SRC})

# Include directories
target_include_directories(imgui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/backends
)

# Link libraries
target_link_libraries(imgui PUBLIC OpenGL::GL SDL2::SDL2)