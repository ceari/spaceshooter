/*
 * BackgroundTextureController.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "BackgroundTextureController.h"

BackgroundTextureController::BackgroundTextureController(BackgroundTexture* bgtexture)
{
	this->mBGTexture = bgtexture;
}

BackgroundTextureController::~BackgroundTextureController()
{
	// TODO Auto-generated destructor stub
}

void BackgroundTextureController::update(double dt)
{
	if (mBGTexture->fixed_to_camera)
	{
		mBGTexture->position.x = Camera::Instance()->getPosition().x;
		mBGTexture->position.y = Camera::Instance()->getPosition().y;
	}
	else
	{
		mBGTexture->velocity += mBGTexture->acceleration * dt;
		mBGTexture->position += mBGTexture->velocity * dt;

		mBGTexture->angular_velocity += mBGTexture->angular_acceleration * dt;
		mBGTexture->orientation += mBGTexture->angular_velocity * dt;
	}

}


