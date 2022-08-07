#pragma once

#include "GameObject.hpp"

#include <vector>
#include <functional>

namespace Patchwork {
	class PhysicsManager
	{
	public:
		void Update();

		PhysicsManager(std::vector<GameObject*>* collidables, std::vector<GameObject*>* rigidbodies);
		~PhysicsManager();
	private:
		std::vector<GameObject*>* collidables_;
		std::vector<GameObject*>* rigidbodies_;
	};
}

