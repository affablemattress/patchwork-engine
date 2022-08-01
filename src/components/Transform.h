#pragma once
#include "V2.h"
#include "Component.h"

namespace Patchwork {
	class Transform : public Component {
	public:
		Component::Type GetType() const override;
		V2 GetPosition() const;
		void SetPosition(const V2& position);
		double GetRotation() const;
		//Set GameObject's rotation to mod(rotation, 360).
		void SetRotation(double rotation);
		V2 GetScale() const;
		//@param[in] scale X&Y must be [> 0]
		void SetScale(const V2& scale);

		Transform(const V2& position, double rotation, const V2& scale);
		//@returns Transform with position (0, 0), rotation 0, and scale 1
		Transform();
		~Transform();
	private:
		V2 position_;
		double rotation_;
		V2 scale_;
	};
}

