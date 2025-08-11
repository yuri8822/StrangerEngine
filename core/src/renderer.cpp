#include "core.h"

Renderer::Renderer() // Empty to pass "default constructor undefined" issue
{
}

Renderer::Renderer(ECS *ecs)
{
    logger.log("========================= [Renderer] Initializing:");

    // Startup tasks of the Renderer when the Engine starts:
    this->ecs = ecs;
    logger.log("ECS linked to Renderer");

    graphicsAPI = new OpenGL_API; // Hardcoded to OpenGL for now!!!
    graphicsAPI->InitializeAPI();

    logger.log("************************* [Renderer] Initialized\n");
}

void Renderer::Render()
{
    graphicsAPI->ClearScreen();
}

Renderer::~Renderer()
{
    // Cleanup
    graphicsAPI->DestroyDevice();
}