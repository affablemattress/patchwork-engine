#pragma once
#include "V2.h"
#include "Transform.h"
#include "CircleRenderer.h"
#include "Camera.h"

#include <stdint.h>

namespace Patchwork {
	class GameObject {
	public:
		uint32_t GetID() const;

		const char* GetTag() const;
		void SetTag(const char* tag);

		Transform* GetTransform() const;
		void SetTransform(Transform* transform);

		CircleRenderer* GetCircleRenderer() const;
		void SetCircleRenderer(CircleRenderer* circleRenderer);
		void DeleteCircleRenderer();

		Camera* GetCamera() const;
		void SetCamera(Camera* camera);
		void DeleteCamera();

		GameObject(const char* tag, Transform* transform);
		~GameObject();
	private: 
		const uint32_t kID_;
		const char* tag_;
		Transform* transform_;
		CircleRenderer* circleRenderer_;
		Camera* camera_;
	};
}
