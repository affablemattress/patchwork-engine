#pragma once
#include <stdint.h>

namespace Patchwork {
	class WindowManager
	{
	public:
		void InitializeWindow();
		void CloseWindow();
		WindowManager(uint16_t screenWidth, uint16_t screenHeight, uint16_t targetFPS, const char* title);
		~WindowManager();
	private:
		uint16_t screenWidth_;
		uint16_t screenHeight_;
		uint16_t targetFPS_;
		const char* title_; 
	};
}

