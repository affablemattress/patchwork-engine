#include "GameObject.h"

#include "UniqueID.h"

namespace Patchwork {
	uint32_t GameObject::GetID() const { return kID_; }
	const char* GameObject::GetTag() const { return tag_; }

	Transform* GameObject::GetTransform() const {
		return transform_;
	}
	void GameObject::SetTransform(Transform* transform) {
		delete transform_;
		transform_ = transform;
	}
	void GameObject::DeleteTransform() {
		delete transform_;
		transform_ = 0;
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

	GameObject::GameObject(const char* tag)
		: kID_(UniqueID::GenerateID())
		, tag_(tag)
		, transform_(0) 
		, renderer_(0) {}
	GameObject::~GameObject() {
		delete transform_;
		delete renderer_;
	};
}

