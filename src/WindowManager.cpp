#include "WindowManager.h"

#include <stdint.h>
#include <raylib.h>
#include <raygui.h>

namespace Patchwork {
    void WindowManager::InitializeWindow() {
        InitWindow(screenWidth_, screenHeight_, title_);
        SetTargetFPS(targetFPS_);
    }
    void WindowManager::CloseWindow() {
        CloseWindow();
    }

    WindowManager::WindowManager(uint16_t screenWidth, uint16_t screenHeight, uint16_t targetFPS, const char* title)
        : screenWidth_(screenWidth)
        , screenHeight_(screenHeight)
        , targetFPS_(targetFPS) 
        , title_(title) {}
    WindowManager::~WindowManager() {}
}