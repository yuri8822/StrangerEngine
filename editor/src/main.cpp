#include "core.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <iostream>

extern Core core;

// Callback function for SDL errors
void sdl_error_callback(const char *description)
{
    std::cerr << "SDL Error: " << description << std::endl;
}

void initializeImGui(SDL_Window *window, SDL_GLContext context)
{
    // Initialize ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();

    // Initialize ImGui for SDL and OpenGL
    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init("#version 130");
}

void renderImGui()
{
    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // Create your ImGui interface here
    ImGui::Begin("Hello, ImGui!");
    ImGui::Text("This is a sample text");
    ImGui::End();

    // Render ImGui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

int main(int argc, char *argv[])
{

    // Initialize ImGui
    initializeImGui(core.getRenderer()->window, core.getRenderer()->context);

    // Main loop
    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(core.getRenderer()->window))
                done = true;
        }

        // Render ImGui and the scene
        core.getRenderer()->renderScene();

        renderImGui();

        // Swap buffers
        core.getRenderer()->swapBuffers();
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    return 0;
}