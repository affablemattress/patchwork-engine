#include "CircleRenderer.h"

#include <raylib.h>
#include <raygui.h>

namespace Patchwork {
	Renderer::Type CircleRenderer::GetRendererType() const { return Renderer::Type::Circle; }

	CircleRenderer::CircleRenderer(Color color, int8_t zIndex) 
		: color_(color)
		, Renderer(zIndex) {}
	CircleRenderer::~CircleRenderer() {}
}