#pragma once

#include "audio.h"
#include "entityComponentSystem.h"
#include "fileManager.h"
#include "physics.h"
#include "renderer.h"

#include "logger.h"
extern Logger logger;

// This is the center of my engine. It is responsible for Initializing, Linking and Managing all of the modules of the engine
// to then be used in the Runtime and/or Editor, as a library.

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
    Renderer *getRenderer();
    ~Core();
};