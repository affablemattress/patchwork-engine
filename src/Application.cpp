#include "Application.hpp"
#include "WindowManager.hpp"
#include "Scene.hpp"
#include "RenderSystem.hpp"
#include "PhysicsSystem.h"
#include "Transform.hpp"

#include <raylib.h>
#include <iostream>

namespace Patchwork {
    void Application::OnStart(Scene* scene) {
        Texture2D texture = LoadTexture("./assets/12 Frame Test.png");

        GameObject* rectangle = new GameObject("Rectangle", new Transform({ 0, 0 }, 0, { 1, 1 }));
        rectangle->SetRenderer(new RectangleRenderer(GRAY, 50, 50, 1));
        scene->Push(rectangle);

        GameObject* circle = new GameObject("Circle", new Transform({ 10, 10 }, 0, { 1, 1 }));
        circle->SetRenderer(new CircleRenderer(RED, 5, 1));
        scene->Push(circle);

        circle = new GameObject("Circle", new Transform({ 10, 13 }, 0, { 1, 1 }));
        circle->SetRenderer(new CircleRenderer(BLUE, 2, 1));
        scene->Push(circle);

        rectangle = new GameObject("Rectangle", new Transform({ -15, -5 }, 0, { 1, 1 }));
        rectangle->SetRenderer(new RectangleRenderer(GREEN, 5, 10, 1));
        scene->Push(rectangle);

        GameObject* animatedSprite = new GameObject("Sprite", new Transform({ 0, 0 }, 0, { 5, 5 }));
        animatedSprite->SetRenderer(new AnimatedSpriteRenderer(texture, 1, 1, 12, 2, 1));
        scene->Push(animatedSprite);
    }

    void Application::OnUpdate(Scene* scene) {
        GameObject* camera = scene->GetCamera();
        std::vector<GameObject*>* renderables = scene->GetRenderables();

        camera->GetTransform()->RotateByDegrees(0.5);
        camera->GetCamera()->SetFOVLength(camera->GetCamera()->GetFOVLength() + 0.05);
        renderables->at(4)->GetTransform()->MoveTowardsVector(renderables->at(3)->GetTransform()->GetPosition(), 0.01);
    }

    void Application::Run() {
        WindowManager* windowManager = new WindowManager(screenWidth_, screenHeight_, targetFPS_, title_);
        windowManager->InitializeWindow();

        Scene* scene = new Scene();
        OnStart(scene);

        RenderSystem* renderSystem = new RenderSystem(screenWidth_, screenHeight_, targetFPS_, scene->GetRenderables(), scene->GetCamera());
        PhysicsSystem* physicsSystem = new PhysicsSystem(scene->GetCollidables(), scene->GetRigidbodies());
        
        while (!WindowShouldClose()) {
            renderSystem->DrawFrame();
            physicsSystem->Update();
            OnUpdate(scene);
        }

        delete physicsSystem;
        delete renderSystem;

        delete scene;

        windowManager->CloseWindow();
        delete windowManager;
    }

    //Initialzes application's resources.
    Application::Application(uint16_t screenWidth, uint16_t screenHeight, uint16_t targetFPS, const char* title)
        : screenWidth_(screenWidth)
        , screenHeight_(screenHeight)
        , targetFPS_(targetFPS) 
        , title_(title) {}
    Application::~Application() {}
}