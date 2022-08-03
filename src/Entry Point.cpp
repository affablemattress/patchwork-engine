#include "Application.hpp"
#include "Component.hpp"
#include "Transform.hpp"
#include "GameObject.hpp"

int main(int argc, char* argv[]) {
    Patchwork::Application* app = new Patchwork::Application(1024, 768, 120, "2D Soft Body");
    app->Run();
    delete app;
    return 0;
}