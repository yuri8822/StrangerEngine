#include "runtime.h"

Runtime::Runtime()
{
    // Initialize Runtime
}

void Runtime::run()
{
    // This is the main loop of the Runtime, it is seperate from the main loop of the Editor.
    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(core.getRenderer()->window))
                done = true;
        }

        // Render the scene:
        core.getRenderer()->renderScene();

        // Swap buffers
        core.getRenderer()->swapBuffers(); // Note: still need to understand how this works
    }
}
