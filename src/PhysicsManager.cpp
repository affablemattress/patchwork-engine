#include "PhysicsManager.h"

namespace Patchwork {
	void PhysicsManager::Update() {

	}

	PhysicsManager::PhysicsManager(std::vector<GameObject*>* collidables, std::vector<GameObject*>* rigidbodies)
		: collidables_(collidables)
		, rigidbodies_(rigidbodies) {}
	PhysicsManager::~PhysicsManager() {}
}