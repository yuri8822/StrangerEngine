#pragma once

#include <SDL.h>
#include <glad/glad.h>
#include <iostream>

class Renderer
{
public:
    SDL_Window *window;
    SDL_GLContext context;

    Renderer();
    void renderScene();
    void swapBuffers();
    ~Renderer();
};