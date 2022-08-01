#include "CircleRenderer.h"

#include <raylib.h>
#include <raygui.h>

namespace Patchwork {
	Component::Type CircleRenderer::GetType() const { return Component::Type::CircleRenderer; }

	Color CircleRenderer::GetColor() const { return color_; }
	void CircleRenderer::SetColor(Color color) {
		color_ = color;
	}

	double CircleRenderer::GetRadius() const { return radius_;  }
	void CircleRenderer::SetRadius(double radius) {
		if (radius > 0) {
			radius_ = radius;
		}
	}

	CircleRenderer::CircleRenderer(Color color, double radius, int8_t zIndex) 
		: color_(color)
		, radius_(radius)
		, Renderer(zIndex) {}
	CircleRenderer::~CircleRenderer() {}
}