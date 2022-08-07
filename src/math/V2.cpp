#include "V2.hpp"

#include <stdexcept>
#include <math.h>

#define PI 3.14159265


namespace Patchwork {

	double V2::Magnitude(const V2& u) {
		return sqrt(u.GetX() * u.GetX() + u.GetY() * u.GetY());
	}
	double V2::SqrMagnitude(const V2& u) {
		return u.GetX() * u.GetX() + u.GetY() * u.GetY();
	}
	V2 V2::Normalized(const V2& u) {
		double magnitude = V2::Magnitude(u);
		if (magnitude != 0) {
			double factor = 1 / magnitude;
			return u * factor;
		}
		else {
			throw std::invalid_argument("V2::Normalized: cannot normalize a 0 magnitude vector.");
		}
	}
	V2 V2::RotatedByDegrees(const V2& v, double degrees) {
		return Cross(M2::GetRotationMatrixByDegrees(degrees), v);
	}


	double V2::Dot(const V2& v, const V2& u) {
		return v.GetX() * u.GetX() + v.GetY() * u.GetY();
	}
	V2 V2::Cross(const M2& m, const V2& v) {
		return V2(v.GetX() * m.GetM11() + v.GetY() * m.GetM12(), v.GetX() * m.GetM21() + v.GetY() * m.GetM22());
	}

	V2 V2::GetUnitVectorAtDegrees(double degrees) {
		degrees = fmod(degrees, 360);
		return V2(cos((degrees * PI) / 180), sin((degrees * PI) / 180));
	}

	double V2::GetX() const { return x_; }
	void V2::SetX(double x) {
		x_ = x;
	}

	double V2::GetY() const { return y_; }
	void V2::SetY(double y) {
		y_ = y;
	}

	V2::V2(double x, double y) 
		: x_(x), y_(y) {}
	V2::~V2() {}

	V2 operator+(const V2& v, const V2& u) {
		return V2(v.GetX() + u.GetX(), v.GetY() + u.GetY());
	}
	V2 operator-(const V2& v, const V2& u) {
		return V2(v.GetX() - u.GetX(), v.GetY() - u.GetY());
	}
	V2 operator-(const V2& v) {
		return V2(-v.GetX(), -v.GetY());
	}
	V2 operator*(const V2& v, double c) {
		return V2(v.GetX() * c, v.GetY() * c);
	}
	V2 operator*(double c, const V2& v) {
		return V2(v.GetX() * c, v.GetY() * c);
	}
	V2 operator/(const V2& v, double c) {
		return V2(v.GetX() / c, v.GetY() / c);
	}
}
