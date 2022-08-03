#include "RectangleRenderer.h"

#include <raylib.h>
#include <stdexcept>

namespace Patchwork {
	Component::Type RectangleRenderer::GetType() const { return Component::Type::RectangleRenderer; }

	Color RectangleRenderer::GetColor() const { return color_; }
	void RectangleRenderer::SetColor(const Color& color) {
		color_ = color;
	}

	double RectangleRenderer::GetWidth() const { return width_; }
	void RectangleRenderer::SetWidth(double width) {
		if (width > 0) {
			width_ = width;
		}
		else {
			throw std::invalid_argument("RectangleRenderer::SetWidth: arg must be [> 0]");
		}
	}

	double RectangleRenderer::GetHeight() const { return height_; }
	void RectangleRenderer::SetHeight(double height) {
		if (height > 0) {
			height_ = height;
		} 
		else {
			throw std::invalid_argument("RectangleRenderer::SetHeight: arg must be [> 0]");
		}
	}

	RectangleRenderer::RectangleRenderer(const Color& color, double width, double height, int8_t zIndex)
		: color_(color)
		, width_(0)
		, height_(0)
		, Renderer(zIndex) {
		this->SetHeight(height);
		this->SetWidth(width);
	}
	RectangleRenderer::~RectangleRenderer() {}
}