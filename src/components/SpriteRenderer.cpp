#include "SpriteRenderer.h"

#include <stdexcept>

namespace Patchwork {
	Component::Type SpriteRenderer::GetType() const { return Component::Type::SpriteRenderer; }

	Texture2D SpriteRenderer::GetTexture() {return texture_; }
	void SpriteRenderer::SetTexture(Texture2D texture) {
		texture_ = texture;
	}

	double SpriteRenderer::GetWidth() const { return width_; }
	void SpriteRenderer::SetWidth(double width) {
		if (width > 0) {
			width_ = width;
		}
		else {
			throw std::invalid_argument("SpriteRenderer::SetWidth: arg must be [> 0]");
		}
	}

	double SpriteRenderer::GetHeight() const { return height_; }
	void SpriteRenderer::SetHeight(double height) {
		if (height > 0) {
			height_ = height;
		}
		else {
			throw std::invalid_argument("SpriteRenderer::SetHeight: arg must be [> 0]");
		}
	}

	SpriteRenderer::SpriteRenderer(const Texture2D& texture, double width, double height, int8_t zIndex)
		: texture_(texture)
		, width_(0)
		, height_(0)
		, Renderer(zIndex) {
		this->SetHeight(height);
		this->SetWidth(width);
	}
	SpriteRenderer::~SpriteRenderer() {}
}