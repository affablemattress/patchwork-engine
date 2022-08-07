#pragma once

#include "GameObject.hpp"

#include <vector>
#include <functional>

namespace Patchwork {
	class PhysicsSystem
	{
	public:
		void Update();

		PhysicsSystem(std::vector<GameObject*>* collidables, std::vector<GameObject*>* rigidbodies);
		~PhysicsSystem();
	private:
		std::vector<GameObject*>* collidables_;
		std::vector<GameObject*>* rigidbodies_;
	};
}

