/*
 * Texture.h
 *
 * Texture interface class
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <string>
using std::string;

namespace DFXEngine
{

	class Texture
	{
	public:
		Texture();
		virtual ~Texture();

		virtual bool loadFromFile(string filename) = 0;
		//virtual void bindTexture() const = 0;

		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
	};

}

#endif /* TEXTURE_H_ */
