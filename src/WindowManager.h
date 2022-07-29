#pragma once
#include <stdint.h>

namespace Patchwork {
	class WindowManager
	{
	public:
		void InitializeWindow();
		void CloseWindow();
		WindowManager(uint16_t screenWidth, uint16_t screenHeight, const char* title, uint16_t targetFPS);
		~WindowManager();
	private:
		uint16_t screenWidth_;
		uint16_t screenHeight_;
		const char* title_; 
		uint16_t targetFPS_;
	};
}

