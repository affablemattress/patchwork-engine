#include "Renderer.hpp"

#include <stdint.h>

namespace Patchwork {
	bool Renderer::GetIsVisible() const { return isVisible_; }
	void Renderer::SetIsVisible(bool isVisible) {
		isVisible_ = isVisible;
	}

	int8_t Renderer::GetZIndex() const { return zIndex_; }
	void Renderer::SetZIndex(int8_t zIndex) {
		zIndex_ = zIndex;
	}

	Renderer::Renderer(int8_t zIndex) 
		: zIndex_(zIndex)
		, isVisible_(true) {}
	Renderer::~Renderer() {}
}