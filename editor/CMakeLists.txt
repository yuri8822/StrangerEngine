# Add the executable
add_executable(editor
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
)

# Link Qt and core library
target_link_libraries(editor Qt6::Widgets core)

# Include directories for the editor executable
target_include_directories(editor PUBLIC
    ${Qt6Widgets_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)