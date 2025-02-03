#pragma once

#include "renderer.h"

// This is essentially the main part of the core of my engine. It is responsible for maintaining the runtime of the game via:
// the main loop
// the input handling

class Core
{
private:
    Renderer *renderer;
    // soon to add other components as well, IA:
    // audio
    // physics
    // entityComponentSystem

public:
    Core();
    void run();
    Renderer *getRenderer();
    ~Core();
};