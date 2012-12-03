/*
 * GameRenderer.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef GAMERENDERER_H_
#define GAMERENDERER_H_

#include "graphics/RenderDevice.h"
#include "graphics/Renderer.h"
#include "graphics/Light.h"

#include "Camera.h"
#include "Level.h"
#include "models/BackgroundObject.h"

class GameRenderer
{
private:
	static GameRenderer* mInstance;
	GameRenderer();
protected:
	DFXEngine::RenderDevice* render_device;
public:
	static GameRenderer* Instance();
	virtual ~GameRenderer();

	void setRenderDevice(DFXEngine::RenderDevice* device);

	void beginRender();
	void finishRender();
	void renderLevel(Level& level);
};

#endif /* GAMERENDERER_H_ */
