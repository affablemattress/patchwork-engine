#include "GameObject.h"

#include "UniqueID.h"

namespace Patchwork {
	uint32_t GameObject::GetID() const { return kID_; }

	const char* GameObject::GetTag() const { return tag_; }
	void GameObject::SetTag(const char* tag) {
		tag_ = tag;
	}

	Transform* GameObject::GetTransform() const {
		return transform_;
	}
	void GameObject::SetTransform(Transform* transform) {
		delete transform_;
		transform_ = transform;
	}

	CircleRenderer* GameObject::GetCircleRenderer() const {
		return circleRenderer_;
	}
	void GameObject::SetCircleRenderer(CircleRenderer* circleRenderer) {
		delete circleRenderer_;
		circleRenderer_ = circleRenderer;
	}
	void GameObject::DeleteCircleRenderer() {
		delete circleRenderer_;
		circleRenderer_ = 0;
	}

	Camera* GameObject::GetCamera() const {
		return camera_;
	}
	void GameObject::SetCamera(Camera* camera) {
		delete camera_;
		camera_ = camera;
	}
	void GameObject::DeleteCamera() {
		delete camera_;
		camera_ = 0;
	}

	GameObject::GameObject(const char* tag, Transform* transform)
		: kID_(UniqueID::GenerateID())
		, tag_(tag)
		, transform_(transform) 
		, circleRenderer_(0)
		, camera_(0) {}
	GameObject::~GameObject() {
		delete transform_;
		delete circleRenderer_;
		delete camera_;
	};
}

