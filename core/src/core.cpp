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