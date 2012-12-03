/*
 * OpenGLTexture.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef OPENGLTEXTURE_H_
#define OPENGLTEXTURE_H_

#include "includes.h"
#include <string>
using std::string;

#include "../Texture.h"

namespace DFXEngine
{

	class OpenGLTexture : public Texture
	{
	protected:
		string mFilename;
		GLuint mpTexture;
		int mWidth, mHeight;
	public:
		OpenGLTexture();
		virtual ~OpenGLTexture();

		bool loadFromFile(string filename);

		GLuint getGLTexturePtr() const;

		int getWidth() const;
		int getHeight() const;
	};

}

#endif /* OPENGLTEXTURE_H_ */
