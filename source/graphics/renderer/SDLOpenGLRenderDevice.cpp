/*
 * SDLOpenGLRenderDevice.cpp
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#include "SDLOpenGLRenderDevice.h"

namespace DFXEngine
{

	SDLOpenGLRenderDevice::SDLOpenGLRenderDevice()
	{


	}

	SDLOpenGLRenderDevice::~SDLOpenGLRenderDevice()
	{
		SDL_Quit();
	}

	bool SDLOpenGLRenderDevice::initialize(int width, int height)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
			return false;

		mScreen = SDL_SetVideoMode(width, height, 24, SDL_OPENGL| SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE | SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF);
		if (!mScreen)
			return false;
		SDL_WM_SetCaption("SDL OpenGL Engine Window", 0);

		if (!mRenderer.initialize(width, height))
		{
			delete mScreen;
			return false;
		}

		return true;
	}

	Renderer & SDLOpenGLRenderDevice::getRenderer()
	{
		return mRenderer;
	}

	TextureManager & SDLOpenGLRenderDevice::getTextureManager()
	{
		return mTextureManager;
	}

	ParticleSystemManager & SDLOpenGLRenderDevice::getParticleSystemManager()
	{
		return mParticleSystemManager;
	}

}






