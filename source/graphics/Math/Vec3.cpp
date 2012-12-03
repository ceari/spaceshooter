/*
 * Vec3.cpp
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#include "Vec3.h"

Vec3::Vec3(double x, double y, double z): x(x), y(y), z(z)
{

}

Vec3::~Vec3()
{
	// TODO Auto-generated destructor stub
}

Vec3 Vec3::operator +(const Vec3 & other)
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator -(const Vec3 & other)
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 & Vec3::operator =(const Vec3 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vec3 operator *(const Vec3 & v, const float f)
{
	return Vec3(f * v.x, f * v.y, f * v.z);
}

Vec3 & Vec3::operator +=(const Vec3 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vec3 & Vec3::operator -=(const Vec3 & other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vec3::Vec3()
{
	x = y = z = 0.0;
}

Vec3 operator *(const float f, const Vec3 & v)
{
	return Vec3(f * v.x, f * v.y, f * v.z);
}

Vec3::Vec3(const Vec3 &other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

double Vec3::getLength()
{
	return sqrt(x*x + y*y + z*z);
}

double Vec3::getLengthSquared()
{
	return x*x + y*y + z*z;
}


