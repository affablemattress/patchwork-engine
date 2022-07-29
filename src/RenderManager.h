#pragma once

#include "Transform.h"
#include "CircleRenderer.h"
#include "Renderer.h"
#include "GameObject.h"

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

		RenderManager();
		~RenderManager();
	private:
		//Vector of renderers sorted (ascending) to their Z index.
		std::vector<GameObject*> renderables_;
		Transform* cameraTransform_;
		Color backgroundColor_;
	};
}

