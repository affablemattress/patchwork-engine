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

    WindowManager::WindowManager(uint16_t screenWidth, uint16_t screenHeight, const char* title, uint16_t targetFPS) 
        : screenWidth_(screenWidth)
        , screenHeight_(screenHeight)
        , title_(title)
        , targetFPS_(targetFPS) {}
    WindowManager::~WindowManager() {}
}