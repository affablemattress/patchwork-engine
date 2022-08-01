#include "Application.h"
#include "Component.h"
#include "Transform.h"
#include "GameObject.h"

int main(int argc, char* argv[]) {
    Patchwork::Application* app = new Patchwork::Application(1024, 768, "2D Soft Body", 240);
    app->Run();
    delete app;
    return 0;
}