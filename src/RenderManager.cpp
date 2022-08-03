#include "RenderManager.h"

#include "V2.h"
#include "M2.h"
#include "Transform.h"

#include <stdexcept>
#include <iostream>

namespace Patchwork {
	void RenderManager::Draw(GameObject* renderable, double pixelsPerUnit) const {
		if (renderable->GetCircleRenderer()) {
			if (renderable->GetCircleRenderer()->GetIsVisible()) {
				Transform transform(*renderable->GetTransform());
				transform.MoveByVector(-camera_->GetTransform()->GetPosition());
				transform.MoveToVector(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
				transform.RotateByDegrees(-camera_->GetTransform()->GetRotation());
				DrawCircle(screenWidth_ / 2 + transform.GetPosition().GetX() * transform.GetScale().GetX() * pixelsPerUnit,
					       screenHeight_ / 2 - transform.GetPosition().GetY() * transform.GetScale().GetX() * pixelsPerUnit,
					       renderable->GetCircleRenderer()->GetRadius() * transform.GetScale().GetX() * pixelsPerUnit,
					       renderable->GetCircleRenderer()->GetColor());
			}
		}
		else if (renderable->GetRectangleRenderer()) {
			if (renderable->GetRectangleRenderer()->GetIsVisible()) {
				Transform transform(*renderable->GetTransform());
				transform.MoveByVector(-camera_->GetTransform()->GetPosition());
				transform.MoveToVector(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
				transform.RotateByDegrees(-camera_->GetTransform()->GetRotation());
				DrawRectanglePro(Rectangle{ static_cast<float>(screenWidth_ / 2 + transform.GetPosition().GetX() * pixelsPerUnit),
								            static_cast<float>(screenHeight_ / 2 - transform.GetPosition().GetY() * pixelsPerUnit),
								            static_cast<float>(renderable->GetRectangleRenderer()->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit),
								            static_cast<float>(renderable->GetRectangleRenderer()->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) },
								 Vector2{ static_cast<float>(renderable->GetRectangleRenderer()->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit) / 2,
					                      static_cast<float>(renderable->GetRectangleRenderer()->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) / 2 },
					             transform.GetRotation(),
					             renderable->GetRectangleRenderer()->GetColor());
			}
		}
		else if (renderable->GetSpriteRenderer()) {
			if (renderable->GetSpriteRenderer()->GetIsVisible()) {
				Transform transform(*renderable->GetTransform());
				transform.MoveByVector(-camera_->GetTransform()->GetPosition());
				transform.MoveToVector(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
				transform.RotateByDegrees(-camera_->GetTransform()->GetRotation());
				DrawTexturePro(renderable->GetSpriteRenderer()->GetTexture(),
					           Rectangle{ 0,
						                  0,
								          static_cast<float>(renderable->GetSpriteRenderer()->GetTexture().width),
								          static_cast<float>(renderable->GetSpriteRenderer()->GetTexture().height)},
					           Rectangle{ static_cast<float>(screenWidth_ / 2 + transform.GetPosition().GetX() * pixelsPerUnit),
						                  static_cast<float>(screenHeight_ / 2 - transform.GetPosition().GetY() * pixelsPerUnit),
						                  static_cast<float>(renderable->GetSpriteRenderer()->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit),
						                  static_cast<float>(renderable->GetSpriteRenderer()->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) },
					           Vector2{ static_cast<float>(renderable->GetSpriteRenderer()->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit) / 2,
					                    static_cast<float>(renderable->GetSpriteRenderer()->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) / 2 },
					           transform.GetRotation(),
					           WHITE);
			}
		}
	}

	//Starts rendering all GameObjects with visible renderers.
	void RenderManager::DrawFrame() {
		BeginDrawing();

		for (GameObject* renderable : *renderables_) {
			double pixelsPerUnit = screenHeight_/ camera_->GetCamera()->GetFOVLength();
			Draw(renderable, pixelsPerUnit);
		}

		ClearBackground(WHITE);
		EndDrawing();
	}

	GameObject* RenderManager::GetCamera() { return camera_; }
	//@param[in] camera must have a camera component.
	void RenderManager::SetCamera(GameObject* camera) {
		if (camera->GetCamera()) {
			camera_ = camera;
		} 
		else {
			throw std::invalid_argument("RenderManager::SetCamera: arg must have a camera component");
		}
	}

	 //@param[in] camera must have a camera component.
	RenderManager::RenderManager(uint16_t screenWidth, uint16_t screenHeight, uint16_t targetFPS, std::vector<GameObject*>* renderables, GameObject* camera)
		: screenWidth_(screenWidth)
		, screenHeight_(screenHeight)
		, targetFPS_(targetFPS)
		, renderables_(renderables) 
		, camera_(0){
		this->SetCamera(camera);
	}
	RenderManager::~RenderManager() {}
}