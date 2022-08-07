#pragma once

#include "GameObject.hpp"
#include "Scene.hpp"

#include <stdint.h>
#include <vector>

namespace Patchwork {
	class Application {
	public:
		void OnStart(Scene* scene);
		void OnUpdate(Scene* scene);

		void Run();

		Application(uint16_t screenWidth, uint16_t screenHeight, uint16_t targetFPS, const char* title);
		virtual ~Application();
	private: 
		uint16_t screenWidth_;
		uint16_t screenHeight_;
		uint16_t targetFPS_;
		const char* title_;
	};
}