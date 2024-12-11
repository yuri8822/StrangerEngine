#pragma once

#include "renderer.h"

class Core
{
private:
    Renderer *renderer;

public:
    Core();
    void run();
    Renderer *getRenderer();
    ~Core();
};