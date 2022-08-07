#pragma once

#include "Renderer.hpp"

#include <raylib.h>
#include <stdint.h>

namespace Patchwork {
	class SpriteRenderer : public Renderer {
	public:
		Renderer::Type GetRendererType() const override;

		Texture2D GetTexture();
		void SetTexture(const Texture2D& texture);

		double GetHeight() const;
		//Sets rectangle's relative height to its scale to parameter if parameter > 0.
		void SetHeight(double height);

		double GetWidth() const;
		//Sets rectangle's relative width to its scale to parameter if parameter > 0.
		void SetWidth(double width);

		SpriteRenderer(const Texture2D& texture, double width, double height, int8_t zIndex);
		virtual ~SpriteRenderer();
	private:
		Texture2D texture_;
		double width_;
		double height_;
	};
}