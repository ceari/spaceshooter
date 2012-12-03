/*
 * BackgroundTexture.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "BackgroundTexture.h"

BackgroundTexture::BackgroundTexture(): fixed_to_camera(false), texture_scale(1)
{

}

BackgroundTexture::~BackgroundTexture()
{
	// TODO Auto-generated destructor stub
}

void BackgroundTexture::render(DFXEngine::Renderer& renderer)
{
	renderer.renderTexturedQuad(this->position, this->orientation, this->texture, this->texture_scale);
}


