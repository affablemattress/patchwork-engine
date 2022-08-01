#pragma once
#include "V2.h"
#include "Transform.h"
#include "Renderer.h"
#include "Camera.h"

#include <stdint.h>

namespace Patchwork {
	class GameObject {
	public:
		uint32_t GetID() const;

		const char* GetTag() const;
		void SetTag(const char* tag);

		Transform* GetTransform() const;
		//Sets GameObject's Transform compnent to the one passed by parameter and deletes the old one.
		void SetTransform(Transform* component);

		Renderer* GetRenderer() const;
		//Sets GameObject's Renderer compnent to the one passed by parameter and deletes the old one.
		void SetRenderer(Renderer* component);
		void DeleteRenderer();

		Camera* GetCamera() const;
		void SetCamera(Camera* camera);
		void DeleteCamera();

		GameObject(const char* tag, Transform* transform);
		~GameObject();
	private: 
		const uint32_t kID_;
		const char* tag_;
		Transform* transform_;
		Renderer* renderer_;
		Camera* camera_;
	};
}
