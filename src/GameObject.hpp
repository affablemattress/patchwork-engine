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

		CircleRenderer* GetCircleRenderer() const;
		void SetCircleRenderer(CircleRenderer* circleRenderer);
		void DeleteCircleRenderer();

		RectangleRenderer* GetRectangleRenderer() const;
		void SetRectangleRenderer(RectangleRenderer* rectangleRenderer);
		void DeleteRectangleRenderer();

		SpriteRenderer* GetSpriteRenderer() const;
		void SetSpriteRenderer(SpriteRenderer* spriteRenderer);
		void DeleteSpriteRenderer();

		AnimatedSpriteRenderer* GetAnimatedSpriteRenderer() const;
		void SetAnimatedSpriteRenderer(AnimatedSpriteRenderer* animatedSpriteRenderer);
		void DeleteAnimatedSpriteRenderer();

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
		RectangleRenderer* rectangleRenderer_;
		SpriteRenderer* spriteRenderer_;
		AnimatedSpriteRenderer* animatedSpriteRenderer_;
		Camera* camera_;
	};
}
