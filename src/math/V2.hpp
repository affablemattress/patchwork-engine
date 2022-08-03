#pragma once
#include "M2.hpp"

namespace Patchwork {
	struct V2 {
	public:
		static double Magnitude(const V2& u);
		static double SqrMagnitude(const V2& u);
		static V2 Normalized(const V2& u);
		static V2 RotatedByDegrees(const V2& v, double degrees);

		static double Dot(const V2& v, const V2& u);
		static V2 Cross(const M2& m, const V2& v);

		static V2 GetUnitVectorAtDegrees(double degrees);

		double GetX () const;
		void SetX(double x);
		double GetY() const;
		void SetY(double y);

		V2(double x, double y);
		~V2();
	private:
		double x_;
		double y_;
	};

	V2 operator+(const V2& v, const V2& u);
	V2 operator-(const V2& v, const V2& u);
	V2 operator-(const V2& v);
	V2 operator*(const V2& v, double c);
	V2 operator*(double c, const V2& v);
	V2 operator/(const V2& v, double c);
}

