#include "RenderManager.h"

#include "V2.h"
#include "M2.h"
#include "Transform.h"

#include <stdexcept>

namespace Patchwork {
	void RenderManager::Draw(GameObject* renderable, double pixelsPerUnit) const {
		if (renderable->GetCircleRenderer()) {
			if (renderable->GetCircleRenderer()->GetIsVisible()) {
				Transform transform(*renderable->GetTransform());
				transform.SetPosition(transform.GetPosition() - camera_->GetTransform()->GetPosition());
				transform.SetPosition(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
				transform.SetRotation(transform.GetRotation() - camera_->GetTransform()->GetRotation());
				DrawCircle(screenWidth_ / 2 + transform.GetPosition().GetX() * pixelsPerUnit, 
					       screenHeight_ / 2 - transform.GetPosition().GetY() * pixelsPerUnit,
					       renderable->GetCircleRenderer()->GetRadius() * pixelsPerUnit, 
					       renderable->GetCircleRenderer()->GetColor());
			}
		}
		if (renderable->GetRectangleRenderer()) {
			if (renderable->GetRectangleRenderer()->GetIsVisible()) {
				Transform transform(*renderable->GetTransform());
				transform.SetPosition(transform.GetPosition() - camera_->GetTransform()->GetPosition());
				transform.SetPosition(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
				transform.SetRotation(transform.GetRotation() - camera_->GetTransform()->GetRotation());
				DrawRectanglePro({ static_cast<float>(screenWidth_ / 2 + transform.GetPosition().GetX() * pixelsPerUnit),
								   static_cast<float>(screenHeight_ / 2 - transform.GetPosition().GetY() * pixelsPerUnit),
								   static_cast<float>(renderable->GetRectangleRenderer()->GetWidth() * pixelsPerUnit),
								   static_cast<float>(renderable->GetRectangleRenderer()->GetHeight() * pixelsPerUnit) },
					             { static_cast<float>(renderable->GetRectangleRenderer()->GetWidth() * pixelsPerUnit) / 2,
					               static_cast<float>(renderable->GetRectangleRenderer()->GetHeight() * pixelsPerUnit) / 2 },
					             transform.GetRotation(),
					             renderable->GetRectangleRenderer()->GetColor());
			}
		}
	}

	//Starts rendering all GameObjects with visible renderers.
	void RenderManager::DrawFrame() {
		BeginDrawing();

		for (GameObject* renderable : *renderables_) {
			double pixelsPerUnit = screenHeight_/ camera_->GetCamera()->GetFOVLength();
			if (renderable->GetCircleRenderer() || renderable->GetRectangleRenderer()) {
				Draw(renderable, pixelsPerUnit);
			}
		}

		camera_->GetTransform()->SetRotation(camera_->GetTransform()->GetRotation() + 0.05);
		camera_->GetCamera()->SetFOVLength(camera_->GetCamera()->GetFOVLength() + 0.05);

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
	RenderManager::RenderManager(uint16_t screenWidth, uint16_t screenHeight, const std::vector<GameObject*>* renderables, GameObject* camera)
		: screenWidth_(screenWidth)
		, screenHeight_(screenHeight)
		, renderables_(renderables) 
		, camera_(0){
		this->SetCamera(camera);
	}
	RenderManager::~RenderManager() {}
}