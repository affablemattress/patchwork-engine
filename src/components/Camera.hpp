#pragma once
#include "Component.hpp"

#include <raylib.h>

namespace Patchwork {
	class Camera : public Component {
	public:
		Component::Type GetType() const;

		Color GetBackgroundColor() const;
		void SetBackgroundColor(const Color& backgroundColor);

		double GetFOVLength() const;
		void SetFOVLength(double FOVLength);

		Camera(const Color& backgroundColor, double FOVLength);
		~Camera();
	private: 
		Color backgroundColor_;
		double FOVLength_;
	};
}

