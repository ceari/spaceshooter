/*
 * Vec3.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef VEC3_H_
#define VEC3_H_

#include <cmath>

class Vec3
{
public:
	double x, y, z;

	Vec3();
	Vec3(double x, double y, double z);
	virtual ~Vec3();

	Vec3(const Vec3 &other);
	Vec3 operator+(const Vec3& other);
	Vec3 operator-(const Vec3& other);
	Vec3& operator=(const Vec3& other);
	Vec3& operator+=(const Vec3& other);
	Vec3& operator-=(const Vec3& other);
	friend Vec3 operator*(const Vec3 &v, const float f);
	friend Vec3 operator*(const float f, const Vec3 &v);

	double getLength();
	double getLengthSquared();	// saves costly sqrt operation in some cases
};


#endif /* VEC3_H_ */
