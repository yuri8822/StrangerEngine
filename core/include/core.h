#pragma once

#include "renderer.h"

class Core
{
private:
    Renderer *renderer;
    // soon to add other components as well, such as audio and physics

public:
    Core();
    void run();
    Renderer *getRenderer();
    ~Core();
};