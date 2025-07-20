#pragma once

#include "audio.h"
#include "entityComponentSystem.h"
#include "fileManager.h"
#include "physics.h"
#include "renderer.h"

#include "logger.h"
extern Logger logger;

// This is essentially the main part of the core of my engine. It is responsible for maintaining the runtime of the game via:
// the main loop
// the input handling

class Core
{
private:
    // soon to add other components as well, IA.
    
    // audio
    ECS *ecs;
    FileManager *fileManager;
    // physics
    Renderer *renderer;

public:
    Core();
    void run();
    Renderer *getRenderer();
    ~Core();
};