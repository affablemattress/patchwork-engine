#include "RenderManager.hpp"

#include "V2.hpp"
#include "M2.hpp"
#include "Transform.hpp"

#include <stdexcept>
#include <iostream>

namespace Patchwork {
	void RenderManager::Draw(GameObject* renderable, double pixelsPerUnit) const {
		switch (renderable->GetRenderer()->GetRendererType()) {
			case Renderer::Type::Circle:
			{
				if (renderable->GetRenderer()->GetIsVisible()) {
					CircleRenderer* renderer = static_cast<CircleRenderer*>(renderable->GetRenderer());
					Transform transform(*renderable->GetTransform());
					transform.MoveByVector(-camera_->GetTransform()->GetPosition());
					transform.MoveToVector(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
					transform.RotateByDegrees(-camera_->GetTransform()->GetRotation());
					DrawCircle(screenWidth_ / 2 + transform.GetPosition().GetX() * transform.GetScale().GetX() * pixelsPerUnit,
						screenHeight_ / 2 - transform.GetPosition().GetY() * transform.GetScale().GetX() * pixelsPerUnit,
						renderer->GetRadius() * transform.GetScale().GetX() * pixelsPerUnit,
						renderer->GetColor());
				}
			}
			break;
			case Renderer::Type::Rectangle:
			{
				if (renderable->GetRenderer()->GetIsVisible()) {
					RectangleRenderer* renderer = static_cast<RectangleRenderer*>(renderable->GetRenderer());
					Transform transform(*renderable->GetTransform());
					transform.MoveByVector(-camera_->GetTransform()->GetPosition());
					transform.MoveToVector(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
					transform.RotateByDegrees(-camera_->GetTransform()->GetRotation());
					DrawRectanglePro(Rectangle{ static_cast<float>(screenWidth_ / 2 + transform.GetPosition().GetX() * pixelsPerUnit),
												static_cast<float>(screenHeight_ / 2 - transform.GetPosition().GetY() * pixelsPerUnit),
												static_cast<float>(renderer->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit),
												static_cast<float>(renderer->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) },
						Vector2{ static_cast<float>(renderer->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit) / 2,
								 static_cast<float>(renderer->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) / 2 },
						transform.GetRotation(),
						renderer->GetColor());
				}
			}
			break;
			case Renderer::Type::Sprite:
			{
				if (renderable->GetRenderer()->GetIsVisible()) {
					SpriteRenderer* renderer = static_cast<SpriteRenderer*>(renderable->GetRenderer());
					Transform transform(*renderable->GetTransform());
					transform.MoveByVector(-camera_->GetTransform()->GetPosition());
					transform.MoveToVector(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
					transform.RotateByDegrees(-camera_->GetTransform()->GetRotation());
					DrawTexturePro(renderer->GetTexture(),
						Rectangle{ 0,
								   0,
								   static_cast<float>(renderer->GetTexture().width),
								   static_cast<float>(renderer->GetTexture().height) },
						Rectangle{ static_cast<float>(screenWidth_ / 2 + transform.GetPosition().GetX() * pixelsPerUnit),
								   static_cast<float>(screenHeight_ / 2 - transform.GetPosition().GetY() * pixelsPerUnit),
								   static_cast<float>(renderer->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit),
								   static_cast<float>(renderer->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) },
						Vector2{ static_cast<float>(renderer->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit) / 2,
								 static_cast<float>(renderer->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) / 2 },
						transform.GetRotation(),
						WHITE);
				}
			}
			break;
			case Renderer::Type::AnimatedSprite:
			{
				if (renderable->GetRenderer()->GetIsVisible()) {
					AnimatedSpriteRenderer* renderer = static_cast<AnimatedSpriteRenderer*>(renderable->GetRenderer());
					Transform transform(*renderable->GetTransform());
					transform.MoveByVector(-camera_->GetTransform()->GetPosition());
					transform.MoveToVector(V2::RotatedByDegrees(transform.GetPosition(), camera_->GetTransform()->GetRotation()));
					transform.RotateByDegrees(-camera_->GetTransform()->GetRotation());
					renderer->UpdateSprite();
					DrawTexturePro(renderer->GetTexture(),
						Rectangle{ static_cast<float>((renderer->GetTexture().width / renderer->GetFrameCount()) * renderer->GetCurrentFrame()),
								   0,
								   static_cast<float>(renderer->GetTexture().width / renderer->GetFrameCount()),
								   static_cast<float>(renderer->GetTexture().height) },
						Rectangle{ static_cast<float>(screenWidth_ / 2 + transform.GetPosition().GetX() * pixelsPerUnit),
								   static_cast<float>(screenHeight_ / 2 - transform.GetPosition().GetY() * pixelsPerUnit),
								   static_cast<float>(renderer->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit),
								   static_cast<float>(renderer->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) },
						Vector2{ static_cast<float>(renderer->GetWidth() * transform.GetScale().GetX() * pixelsPerUnit) / 2,
								 static_cast<float>(renderer->GetHeight() * transform.GetScale().GetY() * pixelsPerUnit) / 2 },
						transform.GetRotation(),
						WHITE);
				}
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