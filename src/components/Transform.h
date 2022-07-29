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
		double GetScale() const;
		//Set GameObject's scale to scale if scale > 0, to 1 if not.
		void SetScale(double rotation);

		Transform(const V2& position, double rotation, double scale);
		//@returns Transform with position (0, 0), rotation 0, and scale 1
		Transform();
		~Transform();
	private:
		V2 position_;
		double rotation_;
		double scale_;
	};
}

