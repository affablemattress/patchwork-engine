#include "Camera.h"

#include <stdexcept>

namespace Patchwork{
	Component::Type Camera::GetType() const { return Component::Type::Camera; }

	Color Camera::GetBackgroundColor() const { return backgroundColor_; }
	void Camera::SetBackgroundColor(const Color& backgroundColor) {
		backgroundColor_ = backgroundColor;
	}

	double Camera::GetFOVLength() const { return FOVLength_; }
	void Camera::SetFOVLength(double FOVLength) {
		if (FOVLength > 0)
		{
			FOVLength_ = FOVLength;
		}
		else {
			throw std::invalid_argument("Camera::SetFOVLength: FOVLength must be [> 0]");
		}
	}

	Camera::Camera(const Color& backgroundColor, double FOVLength)
		: backgroundColor_(backgroundColor)
		, FOVLength_(FOVLength) {}
	Camera::~Camera() {}
}