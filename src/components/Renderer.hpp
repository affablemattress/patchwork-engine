#pragma once
#include "Component.hpp"

#include <stdint.h>

namespace Patchwork {
	class Renderer : public Component
	{
	public:
		bool GetIsVisible() const;
		void SetIsVisible(bool isVisible);

		//TO DO: Add SetZIndex()
		int8_t GetZIndex() const;
		void SetZIndex(int8_t zIndex);

		Renderer(int8_t zIndex);
		virtual ~Renderer();
	protected:
		bool isVisible_;
		int8_t zIndex_;
	};
}