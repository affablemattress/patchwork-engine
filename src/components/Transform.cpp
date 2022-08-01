#include "Transform.h"

#include "Component.h"

#include <math.h>
#include <stdexcept>

namespace Patchwork {
	Component::Type Transform::GetType() const { return Component::Type::Transform; }

	V2 Transform::GetPosition() const { return position_; }
	void Transform::SetPosition(const V2& position) {
		position_ = position;
	}

	double Transform::GetRotation() const { return rotation_; }
	void Transform::SetRotation(double rotation) {
		rotation_ = fmod(rotation, 360);
	}
	
	V2 Transform::GetScale() const { return scale_; }
	void Transform::SetScale(const V2& scale) {
		if (scale.GetX() > 0 && scale.GetY() > 0) {
			scale_ = scale;
		} 
		else {
			throw std::invalid_argument("Transform::SetScale: arg's X or Y cannot be [<= 0]");
		}
	}

	Transform::Transform(const V2& position, double rotation, const V2& scale)
		: position_(position)
		, rotation_(fmod(rotation, 360))
		, scale_({ 1, 1 }) {
		this->SetScale(scale);
	}
	Transform::Transform()
		: position_(V2(0, 0))
		, rotation_(0)
		, scale_({ 1, 1 }) {}
	Transform::~Transform() {}
}
