/*
 * SDLOpenGLRenderDevice.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef SDLOPENGLRENDERDEVICE_H_
#define SDLOPENGLRENDERDEVICE_H_

#include "includes.h"

#include "../RenderDevice.h"
#include "OpenGLRenderer.h"
#include "OpenGLTextureManager.h"
#include "../ParticleSystemManager.h"

namespace DFXEngine
{
	class SDLOpenGLRenderDevice : public RenderDevice
	{
	protected:
		SDL_Surface* mScreen;
		OpenGLRenderer mRenderer;
		OpenGLTextureManager mTextureManager;
		ParticleSystemManager mParticleSystemManager;
	public:
		SDLOpenGLRenderDevice();
		virtual ~SDLOpenGLRenderDevice();

		bool initialize(int width, int height);
		Renderer& getRenderer();
		TextureManager& getTextureManager();
		ParticleSystemManager& getParticleSystemManager();
	};
}

#endif /* SDLOPENGLRENDERDEVICE_H_ */
