#include "AnimatedSpriteRenderer.hpp"

#include <raylib.h>
#include <math.h>
#include <stdexcept>

namespace Patchwork {
	//Updates sprite's current frame based on time passed.
	void AnimatedSpriteRenderer::UpdateSprite() {
		int passedFrameCount = static_cast<int>(floor((GetTime() - currentTime_) / (1. / FPS_)));
		currentTime_ += passedFrameCount * (1. / FPS_);
		currentFrame_ = (currentFrame_ + passedFrameCount) % frameCount_;
	}

	int AnimatedSpriteRenderer::GetFrameCount() const {
		return frameCount_;
	}
	int AnimatedSpriteRenderer::GetCurrentFrame() const {
		return currentFrame_;
	}

	Component::Type AnimatedSpriteRenderer::GetType() const { return Component::Type::AnimatedSpriteRenderer; }

	Texture2D AnimatedSpriteRenderer::GetTexture() { return texture_; }
	void AnimatedSpriteRenderer::SetTexture(const Texture2D& texture, int frameCount, int FPS) {
		if (frameCount > 0 || FPS > 0) {
			texture_ = texture;
			frameCount_ = frameCount;
			FPS_ = FPS;
		}
		else {
			throw std::invalid_argument("AnimatedSpriteRenderer::SetTexture: frameCount and FPS must be [> 0]");
		}
	}

	double AnimatedSpriteRenderer::GetWidth() const { return width_; }
	void AnimatedSpriteRenderer::SetWidth(double width) {
		if (width > 0) {
			width_ = width;
		}
		else {
			throw std::invalid_argument("SpriteRenderer::SetWidth: arg must be [> 0]");
		}
	}

	double AnimatedSpriteRenderer::GetHeight() const { return height_; }
	void AnimatedSpriteRenderer::SetHeight(double height) {
		if (height > 0) {
			height_ = height;
		}
		else {
			throw std::invalid_argument("SpriteRenderer::SetHeight: arg must be [> 0]");
		}
	}

	AnimatedSpriteRenderer::AnimatedSpriteRenderer(const Texture2D& texture, double width, double height, uint8_t frameCount, uint8_t FPS, int8_t zIndex)
		: texture_(texture)
		, width_(0)
		, height_(0)
		, frameCount_(0)
		, FPS_(0)
	    , currentTime_(GetTime())
	    , currentFrame_(0)
		, Renderer(zIndex) {
		this->SetHeight(height);
		this->SetWidth(width);
		this->SetTexture(texture, frameCount, FPS);
	}
	AnimatedSpriteRenderer::~AnimatedSpriteRenderer() {}
}