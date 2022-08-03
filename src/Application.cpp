#include "Application.hpp"
#include "WindowManager.hpp"
#include "RenderManager.hpp"
#include "Transform.hpp"

#include <raylib.h>
#include <iostream>

namespace Patchwork {
    void Application::OnStart() {
        Texture2D texture = LoadTexture("./assets/12 Frame Test.png");

        GameObject* rectangle = new GameObject("Rectangle", new Transform({ 0, 0 }, 0, { 1, 1 }));
        rectangle->SetRectangleRenderer(new RectangleRenderer(GRAY, 50, 50, 1));
        renderables_->push_back(rectangle);
        gameObjects_->push_back(rectangle);

        GameObject* circle = new GameObject("Circle", new Transform({ 10, 10 }, 0, { 1, 1 }));
        circle->SetCircleRenderer(new CircleRenderer(RED, 5, 1));
        renderables_->push_back(circle);
        gameObjects_->push_back(circle);

        circle = new GameObject("Circle", new Transform({ 10, 13 }, 0, { 1, 1 }));
        circle->SetCircleRenderer(new CircleRenderer(BLUE, 2, 1));
        renderables_->push_back(circle);
        gameObjects_->push_back(circle);

        rectangle = new GameObject("Rectangle", new Transform({ -15, -5 }, 0, { 1, 1 }));
        rectangle->SetRectangleRenderer(new RectangleRenderer(GREEN, 5, 10, 1));
        renderables_->push_back(rectangle);
        gameObjects_->push_back(rectangle);

        GameObject* animatedSprite = new GameObject("Sprite", new Transform({ 0, 0 }, 0, { 5, 5 }));
        animatedSprite->SetAnimatedSpriteRenderer(new AnimatedSpriteRenderer(texture, 1, 1, 12, 12, 1));
        renderables_->push_back(animatedSprite);
        gameObjects_->push_back(animatedSprite);
    }

    void Application::OnUpdate() {
        camera_->GetTransform()->RotateByDegrees(0.05);
        camera_->GetCamera()->SetFOVLength(camera_->GetCamera()->GetFOVLength() + 0.05);
        renderables_->at(4)->GetTransform()->MoveTowardsVector(renderables_->at(3)->GetTransform()->GetPosition(), 0.01);
    }

    void Application::Run() {
        WindowManager* windowManager = new WindowManager(screenWidth_, screenHeight_, targetFPS_, title_);
        windowManager->InitializeWindow();
        RenderManager* renderSystem = new RenderManager(screenWidth_, screenHeight_, targetFPS_, renderables_, camera_);

        OnStart();
        while (!WindowShouldClose()) {
            renderSystem->DrawFrame();
            OnUpdate();
        }

        windowManager->CloseWindow();
    }

    //Initialzes application's resources.
    Application::Application(uint16_t screenWidth, uint16_t screenHeight, uint16_t targetFPS, const char* title)
        : screenWidth_(screenWidth)
        , screenHeight_(screenHeight)
        , targetFPS_(targetFPS) 
        , title_(title)
        
        , camera_(0)
        , gameObjects_(new std::vector<GameObject*>)
        , renderables_(new std::vector<GameObject*>) {
        camera_ = new GameObject("Camera", new Transform({ 0, 0 }, 0, { 1, 1 }));
        camera_->SetCamera(new Camera(WHITE, 40));
        gameObjects_->push_back(camera_);
    }
    Application::~Application() {
        gameObjects_->clear();
        renderables_->clear();
        delete camera_;
        delete gameObjects_;
        delete renderables_;
    }
}