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
    void InitializeImGui(SDL_Window *, SDL_GLContext);
    void RenderImGui();
    void Update(bool &);
    void Run();
    void CleanUp();
};