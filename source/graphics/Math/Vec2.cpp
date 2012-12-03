/*
 * Vec2.cpp
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#include "Vec2.h"

namespace DFXEngine
{

	Vec2::Vec2(double x, double y)
	{
		this->x = x;
		this->y = y;

	}

	Vec2::~Vec2()
	{
		// TODO Auto-generated destructor stub
	}

	Vec2 Vec2::operator +(const Vec2 & other)
	{
		return Vec2(x + other.x, y + other.y);
	}

	Vec2 Vec2::operator -(const Vec2 & other)
	{
		return Vec2(x - other.x, y - other.y);
	}

	Vec2 & Vec2::operator =(const Vec2 & other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	Vec2 operator *(const Vec2 & v, const float f)
	{
		return Vec2(f * v.x, f * v.y);
	}

	Vec2 & Vec2::operator +=(const Vec2 & other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2 & Vec2::operator -=(const Vec2 & other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2::Vec2()
	{
		x = y = 0.0;
	}

	Vec2 operator *(const float f, const Vec2 & v)
	{
		return Vec2(f * v.x, f * v.y);
	}

	Vec2::Vec2(const Vec2 &other)
	{
		x = other.x;
		y = other.y;
	}

	double Vec2::getLength()
	{
		return sqrt(x*x + y*y);
	}

	double Vec2::getLengthSquared()
	{
		return x*x + y*y;
	}

}
