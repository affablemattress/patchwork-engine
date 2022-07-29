#pragma once
#include "Renderer.h"

#include <raylib.h>
#include <raygui.h>
#include <stdint.h>

namespace Patchwork {
	class CircleRenderer : public Renderer {
	public:
		Renderer::Type GetRendererType() const override;

		CircleRenderer(Color color, int8_t zIndex);
		~CircleRenderer();
	private:
		Color color_;
	};
}

