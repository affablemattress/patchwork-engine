#include "Application.h"
#include "WindowManager.h"
#include "RenderManager.h"
#include "Transform.h"

#include <raylib.h>
#include <raygui.h>

namespace Patchwork {
    //Code located inside this function runs for every application.
    void Application::Run() {
        WindowManager* windowManager = new WindowManager(screenWidth_, screenHeight_, title_, targetFPS_);
        RenderManager* renderManager = new RenderManager();

        windowManager->InitializeWindow();

        renderManager->StartRender();

        windowManager->CloseWindow();
    }

    //Initialzes application's resources.
    Application::Application(uint16_t screenWidth, uint16_t screenHeight, const char* title, uint16_t targetFPS) 
        : screenWidth_(screenWidth)
        , screenHeight_(screenHeight)
        , title_(title)
        , targetFPS_(targetFPS) {}
    Application::~Application() {}
}