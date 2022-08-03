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
        WindowManager* windowManager = new WindowManager(screenWidth_, screenHeight_, targetFPS_, title_);
        windowManager->InitializeWindow();
        
        std::vector<GameObject*>* allGameObjects = new std::vector<GameObject*>;
        std::vector<GameObject*>* renderables = new std::vector<GameObject*>; //TO DO: renderables must be sorted to their 
                                                                                      //renderable->GetRenderer()->GetZIndex() for 
                                                                                      //the Z Index ordered rendering to work properly.

        GameObject* camera = new GameObject("Camera", new Transform({ 0, 0 }, 0, { 1, 1 }));
        camera->SetCamera(new Camera(WHITE, 40));
        allGameObjects->push_back(camera);

        GameObject* rectangle = new GameObject("Rectangle", new Transform({ 0, 0 }, 0, { 1, 1 }));
        rectangle->SetRectangleRenderer(new RectangleRenderer(GRAY, 50, 50, 1));
        renderables->push_back(rectangle);
        allGameObjects->push_back(rectangle);

        GameObject* circle = new GameObject("Circle", new Transform({ 10, 10 }, 0, { 1, 1 }));
        circle->SetCircleRenderer(new CircleRenderer(RED, 5, 1));
        renderables->push_back(circle);
        allGameObjects->push_back(circle);

        circle = new GameObject("Circle", new Transform({ 10, 13 }, 0, { 1, 1 }));
        circle->SetCircleRenderer(new CircleRenderer(BLUE, 2, 1));
        renderables->push_back(circle);
        allGameObjects->push_back(circle);

        rectangle = new GameObject("Rectangle", new Transform({ -15, -5 }, 0, { 1, 1 }));
        rectangle->SetRectangleRenderer(new RectangleRenderer(GREEN, 5, 10, 1));
        renderables->push_back(rectangle);
        allGameObjects->push_back(rectangle);

        GameObject* sprite = new GameObject("Sprite", new Transform({ 0, 0 }, 0, { 1, 1 }));
        Texture2D texture = LoadTexture("./assets/Revolver.png");
        sprite->SetSpriteRenderer(new SpriteRenderer(texture, 1, 1, 1));
        renderables->push_back(sprite);
        allGameObjects->push_back(sprite);

        RenderManager* renderSystem = new RenderManager(screenWidth_, screenHeight_, targetFPS_, renderables, camera);


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