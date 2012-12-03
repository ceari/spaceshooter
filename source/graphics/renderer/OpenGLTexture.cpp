/*
 * OpenGLTexture.cpp
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#include "OpenGLTexture.h"

namespace DFXEngine
{

	OpenGLTexture::OpenGLTexture()
	{
		// TODO Auto-generated constructor stub

	}

	OpenGLTexture::~OpenGLTexture()
	{
		// TODO Auto-generated destructor stub
	}

	bool OpenGLTexture::loadFromFile(string filename)
	{
		SDL_Surface* surface = IMG_Load(filename.c_str());
		if (!surface) return false;

		GLenum texture_format;
		GLint  nOfColors;
		// get the number of channels in the SDL surface
		nOfColors = surface->format->BytesPerPixel;
		if (nOfColors == 4)     // contains an alpha channel
		{
			if (surface->format->Rmask == 0x000000ff)
				texture_format = GL_RGBA;
			else
				texture_format = GL_BGRA;
		}
		else if (nOfColors == 3)     // no alpha channel
		{
			if (surface->format->Rmask == 0x000000ff)
				texture_format = GL_RGB;
			else
				texture_format = GL_BGR;
		}
		else
		{
			// unrecognized image format
			SDL_FreeSurface(surface);
			return false;
		}

		glGenTextures( 1, &mpTexture );
		glBindTexture( GL_TEXTURE_2D, mpTexture );

		// TODO: anisotropy settings
		//float maximumAnisotropy;
		//glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maximumAnisotropy);
		//glTexParameterf(GL_TEXTURE_2D, 0x84FE, maximumAnisotropy);

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
						  texture_format, GL_UNSIGNED_BYTE, surface->pixels );

		mWidth = surface->w;
		mHeight = surface->h;
		mFilename = filename;

		SDL_FreeSurface(surface);
		return true;
	}

	//void OpenGLTexture::bindTexture() const
	//{
	//	glBindTexture(GL_TEXTURE_2D, mpTexture);
	//}

	int OpenGLTexture::getWidth() const
	{
		return mWidth;
	}

	GLuint OpenGLTexture::getGLTexturePtr() const
	{
		return this->mpTexture;
	}

	int OpenGLTexture::getHeight() const
	{
		return mHeight;
	}

}







