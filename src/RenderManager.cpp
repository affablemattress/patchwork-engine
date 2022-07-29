#include "RenderManager.h"

namespace Patchwork {
	Color RenderManager::GetBackgroundColor() const { return backgroundColor_; }
	void RenderManager::SetBackgroundColor(Color color) {
		backgroundColor_ = color;
	}

	Transform* RenderManager::GetCameraTransform() const { return cameraTransform_; }
	void RenderManager::SetCameraTransform(Transform* transform) {
		delete cameraTransform_;
		cameraTransform_ = transform;
	}

	void RenderManager::AddRenderable(GameObject* renderable) {
		if (renderables_.size() == 0) {
			renderables_.push_back(renderable);
		}
		else {
			for (GameObject* item : renderables_)
			{
				if (renderable->GetID() == item->GetID()) {
					return;
				}
			}
			for (GameObject* item : renderables_)
			{
				for (int i = 0; i < renderables_.size(); i++) {
					if (renderables_.at(i)->GetRenderer()->GetZIndex() <= renderable->GetRenderer()->GetZIndex()) {
						renderables_.insert(renderables_.begin() + i, renderable);
						return;
					}
				}
				renderables_.push_back(renderable);
			}
		}
	}
	void RenderManager::RemoveRenderable(GameObject* renderable) {
		for (int i = 0; i < renderables_.size(); i++) {
			if (renderables_.at(i)->GetID() == renderable->GetID()) {
				renderables_.erase(renderables_.begin() + i);
				return;
			}
		}
	}

	void RenderManager::Draw(GameObject* renderable) const {
		switch (renderable->GetRenderer()->GetRendererType()) {
			case Renderer::Type::Circle:
				//TODO: Add camera logic and draw.
				break;
		}
	}

	//Starts rendering all GameObjects with visible renderers.
	void RenderManager::StartRender() {
		while (!WindowShouldClose()) {
			BeginDrawing();

			for (GameObject* renderable : renderables_) {
				if (renderable->GetRenderer()->GetIsVisible()) {
					Draw(renderable);
				}
			}

			ClearBackground(backgroundColor_);
			EndDrawing();
		}
	}

	RenderManager::RenderManager(uint16_t screenWidth, uint16_t screenHeight)
		: screenWidth_(screenWidth)
		, screenHeight_(screenHeight)
		, renderables_(std::vector<GameObject*>())
		, cameraTransform_(new Transform())
		, backgroundColor_(WHITE) {}
	RenderManager::~RenderManager() {
		delete cameraTransform_;
	}
}