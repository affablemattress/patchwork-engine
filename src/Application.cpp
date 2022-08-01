#include "Application.h"
#include "WindowManager.h"
#include "RenderManager.h"
#include "Transform.h"

#include <raylib.h>
#include <raygui.h>
#include <iostream>

namespace Patchwork {
    //Code located inside this function runs for every application.
    void Application::Run() {
        std::vector<GameObject*> allGameObjects;
        const std::vector<GameObject*>* renderables = &allGameObjects; //TO DO: renderables must be sorted to their 
                                                                       //renderable->GetRenderer()->GetZIndex() for 
                                                                       //the Z Index ordered rendering to work properly.

        GameObject* camera = new GameObject("Camera", new Transform({ -3, -3 }, 0, { 1, 1 }));
        camera->SetCamera(new Camera(WHITE, 20));
        allGameObjects.push_back(camera);

        GameObject* circle = new GameObject("Circle", new Transform({ 10, 10 }, 0, { 1, 1 }));
        circle->SetCircleRenderer(new CircleRenderer(RED, 5, 1));
        allGameObjects.push_back(circle);

        circle = new GameObject("Circle", new Transform({ 10, 13 }, 0, { 1, 1 }));
        circle->SetCircleRenderer(new CircleRenderer(BLUE, 2, 1));
        allGameObjects.push_back(circle);

        WindowManager* windowManager = new WindowManager(screenWidth_, screenHeight_, title_, targetFPS_);
        RenderManager* renderSystem = new RenderManager(screenWidth_, screenHeight_, renderables, camera);

        windowManager->InitializeWindow();

        while (!WindowShouldClose()) {
            renderSystem->DrawFrame();
        }

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