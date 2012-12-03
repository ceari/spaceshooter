/*
 * Color4.h
 *
 *  Created on: Mar 25, 2009
 *      Author: daniel
 */

#ifndef COLOR4_H_
#define COLOR4_H_

namespace DFXEngine
{
	class Color4
	{
	public:
		double r, g, b, a;
		Color4(): r(0), g(0), b(0), a(0) { };
		Color4(double r, double g, double b, double a) {this->r = r, this->g = g; this->b = b; this->a = a; };
		virtual ~Color4();
	};
}

#endif /* COLOR4_H_ */
