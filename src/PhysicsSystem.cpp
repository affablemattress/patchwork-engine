#include "PhysicsSystem.h"

namespace Patchwork {
	void PhysicsSystem::Update() {

	}

	PhysicsSystem::PhysicsSystem(std::vector<GameObject*>* collidables, std::vector<GameObject*>* rigidbodies)
		: collidables_(collidables)
		, rigidbodies_(rigidbodies) {}
	PhysicsSystem::~PhysicsSystem() {}
}