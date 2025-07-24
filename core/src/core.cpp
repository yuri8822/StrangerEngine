#include "core.h"

Core::Core()
{
    logger.isActive = true; // logging on or off

    logger.log("----------------------------------------------------------------------");
    logger.log("|                           [Engine Started]                         |");
    logger.log("----------------------------------------------------------------------\n");

    // =================== Module Initialization ===================
    // audio = new Audio();
    fileManager = new FileManager();
    ecs = new ECS(fileManager);
    // physicsEngine = new PhysicsEngine();
    renderer = new Renderer(ecs);
}
void Core::run()
{
    // Main loop
    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(renderer->window))
                done = true;
        }

        // Render the scene
        renderer->renderScene();

        // Swap buffers
        renderer->swapBuffers();
    }
}
Renderer *Core::getRenderer()
{
    return renderer;
}
Core::~Core()
{
    delete renderer;
    delete ecs;
    delete fileManager;
}

// Define the global instance of Core, this will be included using the extern keyword in all other files that require it
Core core;