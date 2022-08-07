#include "Scene.hpp"

namespace Patchwork {
    void Scene::Push(GameObject* gameObject) {
        gameObjects_->push_back(gameObject);
        if (gameObject->GetRenderer()) {
            renderables_->push_back(gameObject);
        }
    }

    GameObject* Scene::GetCamera() { return camera_; }

    std::vector<GameObject*>* Scene::GetAllGameObjects() { return gameObjects_; }
    std::vector<GameObject*>* Scene::GetRenderables() { return renderables_; }
    std::vector<GameObject*>* Scene::GetCollidables() { return collidables_; }
    std::vector<GameObject*>* Scene::GetRigidbodies() { return rigidbodies_; }

    Scene::Scene() 
        : camera_(0)
        , gameObjects_(new std::vector<GameObject*>)
        , renderables_(new std::vector<GameObject*>)
        , collidables_(new std::vector<GameObject*>)
        , rigidbodies_(new std::vector<GameObject*>) {
        camera_ = new GameObject("Camera", new Transform({ 0, 0 }, 0, { 1, 1 }));
        camera_->SetCamera(new Camera(WHITE, 40));
        gameObjects_->push_back(camera_);
    }

    Scene::~Scene() {
        gameObjects_->clear();
        delete gameObjects_;
        delete renderables_;
        delete collidables_;
        delete rigidbodies_;
    }
}