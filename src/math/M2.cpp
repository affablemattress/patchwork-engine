#include "M2.hpp"

#include <math.h>

#define PI 3.14159265

namespace Patchwork {
	M2 M2::GetRotationMatrixByDegrees(double degrees) {
		degrees = fmod(degrees, 360);
		return M2(cos((degrees * PI) / 180), -sin((degrees * PI) / 180), sin((degrees * PI) / 180), cos((degrees * PI) / 180));
	}

	M2 M2::Cross(M2 m1, M2 m2) {
		return M2(m1.GetM11() * m2.GetM11() + m1.GetM21() * m2.GetM12(),
			      m1.GetM11() * m2.GetM21() + m1.GetM21() * m2.GetM22(), 
			      m1.GetM12() * m2.GetM11() + m1.GetM22() * m2.GetM12(),
			      m1.GetM12() * m2.GetM21() + m1.GetM22() * m2.GetM22());
	}

	double M2::GetM11() const { return m11_;}
	void M2::SetM11(double m11) {
		m11_ = m11;
	}
	double M2::GetM12() const { return m12_; }
	void M2::SetM12(double m12) {
		m12_ = m12;
	}
	double M2::GetM21() const { return m21_;}
	void M2::SetM21(double m21) {
		m21_ = m21;
	}
	double M2::GetM22() const { return m22_; }
	void M2::SetM22(double m22) {
		m22_ = m22;
	}

	M2::M2(double m11, double m12, double m21, double m22) 
		: m11_(m11)
		, m12_(m12)
		, m21_(m21)
		, m22_(m22) {}
	M2::~M2() {}
}