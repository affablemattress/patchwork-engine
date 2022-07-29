#pragma once
#include "Component.h"

#include <stdint.h>

namespace Patchwork {
	class Renderer : public Component
	{
	public:
		enum Type {
			Circle = 0
		};
		Component::Type GetType() const override;
		//@returns RendererType enum corresponding to the renderer.
		virtual Type GetRendererType() const = 0;

		bool GetIsVisible() const;
		void SetIsVisible(bool isVisible);
		//TO DO: Add SetZIndex()
		int8_t GetZIndex() const;

		Renderer(int8_t zIndex);
		virtual ~Renderer();
	protected:
		bool isVisible_;
		int8_t zIndex_;
	};
}

