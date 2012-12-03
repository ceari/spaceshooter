/*
 * Vec2.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef VEC2_H_
#define VEC2_H_

#include <cmath>

namespace DFXEngine
{

	class Vec2
	{
	public:
		double x, y;

		Vec2();
		Vec2(double x, double y);
		virtual ~Vec2();

		Vec2(const Vec2 &other);
		Vec2 operator+(const Vec2& other);
		Vec2 operator-(const Vec2& other);
		Vec2& operator=(const Vec2& other);
		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		friend Vec2 operator*(const Vec2 &v, const float f);
		friend Vec2 operator*(const float f, const Vec2 &v);

		double getLength();
		double getLengthSquared();	// saves costly sqrt operation in some cases
	};

}

#endif /* VEC2_H_ */
