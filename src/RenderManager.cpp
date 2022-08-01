#include "RenderManager.h"

#include "V2.h"
#include "M2.h"

#include <stdexcept>
namespace Patchwork {
	void RenderManager::Draw(GameObject* renderable) const {
		switch (renderable->GetRenderer()->GetRendererType()) {
			case Renderer::Type::Circle:
				//TODO: Add camera logic and draw.
				break;
		}
	}

	//Starts rendering all GameObjects with visible renderers.
	void RenderManager::DrawFrame() {
		BeginDrawing();

		for (GameObject* renderable : *renderables_) {
			if (renderable->GetRenderer()) {
				if (renderable->GetRenderer()->GetIsVisible()) {
					Draw(renderable);
				}
			}
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
	RenderManager::RenderManager(uint16_t screenWidth, uint16_t screenHeight, const std::vector<GameObject*>* renderables, GameObject* camera)
		: screenWidth_(screenWidth)
		, screenHeight_(screenHeight)
		, renderables_(renderables) 
		, camera_(0){
		this->SetCamera(camera);
	}
	RenderManager::~RenderManager() {}
}