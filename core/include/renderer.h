#pragma once

// My renderer will be using SDL and OpenGL.
// I will be using SDL to create a window and OpenGL to render graphics.
// I will be using glad to load OpenGL functions. Still need to figure out what thats all about, for now i only have starter code.

// Perhaps in the future i will replace the renderer with my own custom renderer that i have been working on using only SDL2.
// link: https://github.com/yuri8822/3D_Renderer

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