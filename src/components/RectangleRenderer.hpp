#pragma once
#pragma once
#include "Renderer.hpp"

#include <raylib.h>
#include <stdint.h>

namespace Patchwork {
	class RectangleRenderer : public Renderer {
	public:
		Renderer::Type GetRendererType() const override;

		Color GetColor() const;
		void SetColor(const Color& color);

		double GetHeight() const;
		//Sets rectangle's relative height to its scale to parameter if parameter > 0.
		void SetHeight(double height);

		double GetWidth() const;
		//Sets rectangle's relative width to its scale to parameter if parameter > 0.
		void SetWidth(double width);

		RectangleRenderer(const Color& color, double width, double height, int8_t zIndex);
		virtual ~RectangleRenderer();
	private:
		Color color_;
		double width_;
		double height_;
	};
}