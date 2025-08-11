#pragma once

// Logger:
#include "../logger.h"
extern Logger logger;

// OpenGL:
#include <SDL.h>
#include <glad/glad.h>

#include <iostream>

class GraphicsAPI // All APIs will use SDL
{
public:
    SDL_Window *window;
    SDL_GLContext context;

    virtual void InitializeAPI() = 0;
    virtual void SetViewport() = 0;
    virtual void ClearScreen() = 0;
    virtual void CreateVertexBuffer() = 0;
    virtual void CreateIndexBuffer() = 0;
    virtual void CreateTexture() = 0;
    virtual void SetTextureSampler() = 0;
    virtual void CreateShader() = 0;
    virtual void BindShaderProgram() = 0;
    virtual void SetUniforms() = 0;
    virtual void BindVertexLayout() = 0;
    virtual void BindVertexBuffer() = 0;
    virtual void BindIndexBuffer() = 0;
    virtual void Draw() = 0;
    virtual void DrawIndexed() = 0;
    virtual void SwapBuffers() = 0;
    virtual void EnableDepthTesting() = 0;
    virtual void EnableBlending() = 0;
    virtual void SetScissorRect() = 0;
    virtual void Fence() = 0;
    virtual void DeleteBuffer() = 0;
    virtual void DeleteTexture() = 0;
    virtual void DeleteShader() = 0;
    virtual void DestroyDevice() = 0;
};