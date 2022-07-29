#pragma once
#include "V2.h"
#include "Transform.h"
#include "Renderer.h"

#include <stdint.h>

namespace Patchwork {
	class GameObject {
	public:
		uint32_t GetID() const;
		const char* GetTag() const;

		Transform* GetTransform() const;
		//Sets GameObject's Transform compnent to the one passed by parameter and deletes the old one.
		void SetTransform(Transform* component);
		void DeleteTransform();

		Renderer* GetRenderer() const;
		//Sets GameObject's Renderer compnent to the one passed by parameter and deletes the old one.
		void SetRenderer(Renderer* component);
		void DeleteRenderer();

		GameObject(const char* tag);
		~GameObject();
	private: 
		const char* tag_;
		const uint32_t kID_;
		Transform* transform_;
		Renderer* renderer_;
	};
}
