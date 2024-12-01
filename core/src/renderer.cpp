#include "renderer.h"
#include <glad/glad.h>
#include <SDL.h>
#include <stdexcept>

void initializeRenderer(SDL_Window* window) {
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        throw std::runtime_error("Failed to create OpenGL context");
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    // Set up OpenGL state
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void renderScene() {
    // Rendering logic
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Add your rendering code here
}