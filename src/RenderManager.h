#pragma once

#include "GameObject.h"
#include "Transform.h"

#include <raylib.h>
#include <raygui.h>
#include <vector>

namespace Patchwork {
	class RenderManager
	{
	public:
		Color GetBackgroundColor() const;
		void SetBackgroundColor(Color color);

		Transform* GetCameraTransform() const;
		void SetCameraTransform(Transform* transform);

		void AddRenderable(GameObject* renderer);
		void RemoveRenderable(GameObject* renderer);

		void Draw(GameObject* gameObject) const;

		//Starts rendering all GameObjects with visible renderers.
		void StartRender();

		RenderManager(uint16_t screenWidth, uint16_t screenHeight);
		~RenderManager();
	private:
		uint16_t screenWidth_;
		uint16_t screenHeight_;
		//Vector of renderers sorted (ascending) to their Z index.
		std::vector<GameObject*> renderables_;
		Transform* cameraTransform_;
		Color backgroundColor_;
	};
}

