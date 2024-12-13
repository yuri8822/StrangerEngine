#include "core.h"

// This is essentially the core of the core of my engine. It is responsible for maintaining the runtime of the game via:
// the main loop
// the input handling

Core::Core()
{
    renderer = new Renderer();
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
}

// Define the global instance of Core, this will be included using the extern keyword in all other files that require it
Core core;