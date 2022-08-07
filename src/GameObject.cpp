#include "GameObject.hpp"

#include "UniqueID.hpp"

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

	Renderer* GameObject::GetRenderer() const {
		return renderer_;
	}
	void GameObject::SetRenderer(Renderer* renderer) {
		delete renderer_;
		renderer_ = renderer;
	}
	void GameObject::DeleteRenderer() {
		delete renderer_;
		renderer_ = 0;
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
		, renderer_(0)
		, camera_(0) {}
	GameObject::~GameObject() {
		delete transform_;
		delete renderer_;
		delete camera_;
	};
}

