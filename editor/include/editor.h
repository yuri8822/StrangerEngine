#pragma once

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include "core.h"
extern Core core;

class Editor
{
private:

public:
    Editor();
    void initializeImGui(SDL_Window *, SDL_GLContext);
    void renderImGui();
    void run();
    void cleanUp();
};