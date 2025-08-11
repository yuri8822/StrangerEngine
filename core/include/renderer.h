#pragma once

#include "GraphicsAPIs/openGL.h"
#include "GraphicsAPIs/vulkan.h"
#include "GraphicsAPIs/directX.h"

class ECS;

// My renderer is designed to be renderer agnostic so it can use openGL, Vulkan and DirectX11.

// I will be using SDL to create a window and OpenGL to render graphics initially.
// I will be using glad to load OpenGL functions. need to research a bit more about this

// Perhaps in the future i will add my own custom software graphics api that i have been working on using only SDL2.
// link: https://github.com/yuri8822/3D_Renderer

class Renderer
{
public:
    ECS *ecs;
    GraphicsAPI *graphicsAPI;

    Renderer();
    Renderer(ECS *);
    void Render();

    ~Renderer();
};