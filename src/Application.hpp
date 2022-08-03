#pragma once

#include "GameObject.hpp"

#include <stdint.h>
#include <vector>

namespace Patchwork {
	class Application {
	public:
		void OnStart();
		void OnUpdate();

		void Run();

		Application(uint16_t screenWidth, uint16_t screenHeight, uint16_t targetFPS, const char* title);
		virtual ~Application();
	private: 
		uint16_t screenWidth_;
		uint16_t screenHeight_;
		uint16_t targetFPS_;
		const char* title_;

		GameObject* camera_;
		std::vector<GameObject*>* gameObjects_;
		std::vector<GameObject*>* renderables_;
	};
}