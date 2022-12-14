#pragma once
#include "Renderer.hpp"

#include <raylib.h>
#include <raygui.h>
#include <stdint.h>

namespace Patchwork {
	class CircleRenderer : public Renderer {
	public:
		Renderer::Type GetRendererType() const override;

		Color GetColor() const;
		void SetColor(const Color& color);

		double GetRadius() const;
		//Sets circle's radius to parameter if parameter > 0.
		void SetRadius(double radius);

		CircleRenderer(const Color& color, double radius, int8_t zIndex);
		virtual ~CircleRenderer();
	private:
		Color color_;
		double radius_;
	};
}

