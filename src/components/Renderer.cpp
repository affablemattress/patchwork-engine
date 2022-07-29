#include "Renderer.h"

#include <stdint.h>

namespace Patchwork {
	Component::Type Renderer::GetType() const { return Component::Type::Renderer; }

	bool Renderer::GetIsVisible() const { return isVisible_; }
	void Renderer::SetIsVisible(bool isVisible) {
		isVisible_ = isVisible;
	}

	int8_t Renderer::GetZIndex() const { return zIndex_; }

	Renderer::Renderer(int8_t zIndex) 
		: zIndex_(zIndex)
		, isVisible_(false) {}
	Renderer::~Renderer() {}
}