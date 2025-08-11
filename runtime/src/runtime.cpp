#include "runtime.h"

Runtime::Runtime()
{
    // Initialize Runtime
}

void Runtime::Update(bool &isDone)
{
    // Input Handling:
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            isDone = true;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(core.getRenderer()->graphicsAPI->window))
            isDone = true;
    }
}

void Runtime::Run()
{
    // This is the main loop of the Runtime, it is seperate from the main loop of the Editor.
    bool isDone = false;
    while (!isDone)
    {
        // Update Game State
        Update(isDone);

        // Render the scene:
        core.getRenderer()->Render();

        // Swap buffers
        core.getRenderer()->graphicsAPI->SwapBuffers(); // Note: still need to understand how this works
    }
}
