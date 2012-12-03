/*
 * RenderDevice.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef RENDERDEVICE_H_
#define RENDERDEVICE_H_

#include "Renderer.h"
#include "TextureManager.h"
#include "ParticleSystemManager.h"

namespace DFXEngine
{

	class RenderDevice
	{
	public:
		RenderDevice();
		virtual ~RenderDevice();

		virtual bool initialize(int width, int height) = 0;

		virtual Renderer& getRenderer() = 0;
		virtual TextureManager& getTextureManager() = 0;
		virtual ParticleSystemManager& getParticleSystemManager() = 0;
	};

}

#endif /* RENDERDEVICE_H_ */
