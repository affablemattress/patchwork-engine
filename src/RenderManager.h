#pragma once

#include "GameObject.h"
#include "Transform.h"

#include <raylib.h>
#include <vector>

namespace Patchwork {
	class RenderManager
	{
	public:
		void Draw(GameObject* gameObject, double pixelsPerUnit) const;
		void DrawFrame();

		GameObject* GetCamera();
		void SetCamera(GameObject* camera);

		RenderManager(uint16_t screenWidth, uint16_t screenHeight, uint16_t targetFPS, std::vector<GameObject*>* renderables, GameObject* camera);
		~RenderManager();
	private:
		uint16_t screenWidth_;
		uint16_t screenHeight_;
		uint16_t targetFPS_;
		//Vector of renderers sorted (ascending) to their Z index.
		std::vector<GameObject*>* renderables_;
		GameObject* camera_;
	};
}

