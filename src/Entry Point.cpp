#include "Application.h"
#include "Component.h"
#include "Transform.h"
#include "GameObject.h"

int main(int argc, char* argv[]) {
    Patchwork::Application* app = new Patchwork::Application(1024, 768, 120, "2D Soft Body");
    app->Run();
    delete app;
    return 0;
}