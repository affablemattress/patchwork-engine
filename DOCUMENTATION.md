## Patchwork Main Framework
Engine entry point function is located inside `EntryPoint.cpp`
* * *
## Patchwork `namespace Patchwork`
- *<span style="color: #7f7f7f;">Math</span>*
    - **V2** `struct V2`
    - **M2** `struct M2`
- *<span style="color: #7f7f7f;">Utility</span>*
    - **UniqueID** `namespace UniqueID`
* * *
- **GameObject** `class GameObject` : Every entity in the scene is a GameObject. You can add functionality to the GameObjects by using components. All GameObjects must have a Transform component.
- **Component** `class Component` : Component interface class for creating components. GetType() is a pure virtual function. All derived classes must implement it.
	- **Transform** `class Transform : public Component` : Holds the position, rotation and scale of a GameObject. Every GameObject must have a transform component. 
	- **Camera** `class Camera : public Component`
	- **Renderer** `class Renderer : public Component` : Renderer interface class. Every renderer component must inherit this class since all renderers must have a Z-Index and a visibility bool. 
		- **Circle Renderer** `class CircleRenderer : public Renderer` 
* * *
- **Window Manager** `class WindowManager` : Handles window creation and destruction.
- **Render Manager** `class RenderSystem` : Render system. Takes in a list of current gameobjects in the scene (std::vector<GameObjects*>) and a camera (GameObject*). Iterates through the list every frame and draws all visible GameObject using GameObjects' Renderer and Transform components.
* * *
- **Application** `class Application` : Engine creates an application instance when it starts. Then calls  `Application::Run()` to initialize the application. This class manages scene creation, handling of GameObjects and initialization of systems (WindowManager, RenderSystem etc.) and their handling.