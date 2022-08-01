#pragma once
#include "V2.h"

namespace Patchwork {
	
	struct M2 {
	public:
		static M2 GetRotationMatrixByDegrees(double degrees);

		static M2 Cross(M2 m1, M2 m2);

		double GetM11() const;
		double SetM11(double m11);
		double GetM12() const;
		double SetM12(double m12);
		double GetM21() const;
		double SetM21(double m21);
		double GetM22() const;
		double SetM22(double m22);

		M2(double m11, double m12, double m21, double m22);
		~M2();
	private:
		double m11_;
		double m12_;
		double m21_;
		double m22_;
	};
}

