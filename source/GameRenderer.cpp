/*
 * GameRenderer.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "GameRenderer.h"

GameRenderer* GameRenderer::mInstance = 0;

GameRenderer* GameRenderer::Instance()
{
	if (!mInstance)
		mInstance = new GameRenderer();
	return mInstance;
}

GameRenderer::GameRenderer()
{
}

GameRenderer::~GameRenderer()
{

}

void GameRenderer::setRenderDevice(DFXEngine::RenderDevice *device)
{
	render_device = device;
}

void GameRenderer::renderLevel(Level & level)
{
	DFXEngine::Renderer& renderer = render_device->getRenderer();

	// lighting test
	DFXEngine::Light l;
	l.setAmbient(DFXEngine::Color4(0.1, 0.1, 0.1, 1));
	l.setDiffuse(DFXEngine::Color4(0.7, 0.7, 0.7, 1));
	l.setPosition(Vec3(50000, 0, 30000));
	l.setId(0);
	l.setActive(true);
	renderer.enableLight(&l);
	renderer.updateLight(&l);


	for (std::vector<BackgroundObject*>::iterator it = level.getBackgroundObjects().begin(); it != level.getBackgroundObjects().end(); it++)
	{
		(*it)->render(renderer);
	}

	for (std::vector<GameObject*>::iterator it = level.getGameObjects().begin(); it != level.getGameObjects().end(); it++)
	{
		(*it)->render(renderer);
	}
}

void GameRenderer::beginRender()
{
	render_device->getRenderer().setCameraPosition(Camera::Instance()->getPosition());
	render_device->getRenderer().setCameraLookAt(Camera::Instance()->getLookAt());
	render_device->getRenderer().beginRender();
}

void GameRenderer::finishRender()
{
	render_device->getRenderer().finishRender();
}






