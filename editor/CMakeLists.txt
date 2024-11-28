# Find the Qt library
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Add the executable
add_executable(editor
    src/main.cpp
    src/mainwindow.cpp
)

# Link Qt and core library
target_link_libraries(editor Qt6::Widgets core)
target_include_directories(editor PUBLIC include ../core/include)