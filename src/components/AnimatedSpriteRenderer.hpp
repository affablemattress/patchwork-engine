#pragma once

#include "Renderer.hpp"

#include <raylib.h>
#include <stdint.h>

namespace Patchwork {
	class AnimatedSpriteRenderer : public Renderer {
	public:
		void UpdateSprite();

		int GetFrameCount() const;

		int GetCurrentFrame() const;

		Component::Type GetType() const override;

		Texture2D GetTexture();
		void SetTexture(const Texture2D& texture, int frameCount, int FPS);

		double GetHeight() const;
		//Sets rectangle's relative height to its scale to parameter if parameter > 0.
		void SetHeight(double height);

		double GetWidth() const;
		//Sets rectangle's relative width to its scale to parameter if parameter > 0.
		void SetWidth(double width);

		AnimatedSpriteRenderer(const Texture2D& texture, double width, double height, int frameCount, int FPS, int8_t zIndex);
		~AnimatedSpriteRenderer();
	private:
		Texture2D texture_;
		double width_;
		double height_;
		int frameCount_;
		int FPS_;


		double initTime_;
		int currentFrame_;
	};
}
