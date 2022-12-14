#pragma once

namespace Patchwork {
	struct M2 {
	public:
		static M2 GetRotationMatrixByDegrees(double degrees);

		static M2 Cross(M2 m1, M2 m2);

		double GetM11() const;
		void SetM11(double m11);
		double GetM12() const;
		void SetM12(double m12);
		double GetM21() const;
		void SetM21(double m21);
		double GetM22() const;
		void SetM22(double m22);

		M2(double m11, double m12, double m21, double m22);
		~M2();
	private:
		double m11_;
		double m12_;
		double m21_;
		double m22_;
	};
}

