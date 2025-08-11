#pragma once

#include "graphicsAPI.h"

class OpenGL_API : public GraphicsAPI
{
public:
    void InitializeAPI() override
    {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
        {
            std::string err = SDL_GetError();
            logger.log("SDL Error: " + err);
            return;
        }

        // Create a window
        window = SDL_CreateWindow("Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
        if (!window)
        {
            logger.log("Failed to create SDL window");
            SDL_Quit();
            return;
        }

        // Create an OpenGL context
        context = SDL_GL_CreateContext(window);
        if (!context)
        {
            logger.log("Failed to create OpenGL context");
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }

        SDL_GL_MakeCurrent(window, context);
        SDL_GL_SetSwapInterval(1); // Enable vsync

        // Initialize GLAD
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            logger.log("Failed to initialize GLAD");
            SDL_GL_DeleteContext(context);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }

        // Set up OpenGL state
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    }
    void SetViewport()
    {
    }
    void ClearScreen() override
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void CreateVertexBuffer()
    {
    }
    void CreateIndexBuffer()
    {
    }
    void CreateTexture()
    {
    }
    void SetTextureSampler()
    {
    }
    void CreateShader()
    {
    }
    void BindShaderProgram()
    {
    }
    void SetUniforms()
    {
    }
    void BindVertexLayout()
    {
    }
    void BindVertexBuffer()
    {
    }
    void BindIndexBuffer()
    {
    }
    void Draw()
    {
    }
    void DrawIndexed()
    {
    }
    void SwapBuffers() override
    {
        SDL_GL_SwapWindow(window);
    }
    void EnableDepthTesting()
    {
    }
    void EnableBlending()
    {
    }
    void SetScissorRect()
    {
    }
    void Fence()
    {
    }
    void DeleteBuffer()
    {
    }
    void DeleteTexture()
    {
    }
    void DeleteShader()
    {
    }
    void DestroyDevice() override
    {
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};