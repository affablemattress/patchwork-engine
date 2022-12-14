#pragma once
#include "V2.hpp"
#include "Transform.hpp"
#include "CircleRenderer.hpp"
#include "RectangleRenderer.hpp"
#include "SpriteRenderer.hpp"
#include "AnimatedSpriteRenderer.hpp"
#include "Camera.hpp"

#include <stdint.h>

namespace Patchwork {
	class GameObject {
	public:
		uint32_t GetID() const;

		const char* GetTag() const;
		void SetTag(const char* tag);

		Transform* GetTransform() const;
		void SetTransform(Transform* transform);

		Renderer* GetRenderer() const;
		void SetRenderer(Renderer* renderer);
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
