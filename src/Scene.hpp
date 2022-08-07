#pragma once

#include "GameObject.hpp"

#include <vector>

namespace Patchwork {
	class Scene {
	public:
		void Push(GameObject* gameObject);

		GameObject* GetCamera();

		std::vector<GameObject*>* GetAllGameObjects();
		std::vector<GameObject*>* GetRenderables();
		std::vector<GameObject*>* GetCollidables();
		std::vector<GameObject*>* GetRigidbodies();

		Scene();
		~Scene();
	private:
		GameObject* camera_;
		std::vector<GameObject*>* gameObjects_;
		std::vector<GameObject*>* renderables_;
		std::vector<GameObject*>* collidables_;
		std::vector<GameObject*>* rigidbodies_;
	};
}

