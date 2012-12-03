/*
 * PlayerSpaceshipController.cpp
 *
 *  Created on: Mar 29, 2009
 *      Author: daniel
 */

#include "PlayerSpaceshipController.h"
#include <iostream>

PlayerSpaceshipController::PlayerSpaceshipController()
{
	// TODO Auto-generated constructor stub

}

PlayerSpaceshipController::~PlayerSpaceshipController()
{
	// TODO Auto-generated destructor stub
}

void PlayerSpaceshipController::update(double dt)
{
	const double PI = 3.14159265f;

	updateEngines(dt);

	float z_angle = (mSpaceship->orientation.z - 90) * PI / 180.0f;

	mSpaceship->acceleration.x = 0;
	mSpaceship->acceleration.y = 0;
	mSpaceship->angular_velocity.z = 0;

	if (DFXEngine::Input::Instance()->isKeyDown(SDLK_w))
	{
		mSpaceship->acceleration.x = cos(z_angle) * mSpaceship->max_acceleration;
		mSpaceship->acceleration.y = sin(z_angle) * mSpaceship->max_acceleration;
	}

	if (DFXEngine::Input::Instance()->isKeyDown(SDLK_a))
	{
		mSpaceship->angular_velocity.z = -mSpaceship->max_angular_velocity;
	}

	if (DFXEngine::Input::Instance()->isKeyDown(SDLK_d))
	{
		mSpaceship->angular_velocity.z = mSpaceship->max_angular_velocity;
	}

	// translation
	mSpaceship->velocity += mSpaceship->acceleration * dt;
	if (mSpaceship->velocity.getLength() > mSpaceship->getMax_velocity())
	{
		mSpaceship->velocity = mSpaceship->velocity * (mSpaceship->getMax_velocity() / mSpaceship->velocity.getLength());
	}
	mSpaceship->position += mSpaceship->velocity * dt;


	// rotation
	mSpaceship->angular_velocity += mSpaceship->angular_acceleration * dt;
	if (mSpaceship->angular_velocity.getLength() > mSpaceship->getMax_angular_velocity())
	{
		mSpaceship->angular_velocity = mSpaceship->angular_velocity * (mSpaceship->getMax_angular_velocity() / mSpaceship->angular_velocity.getLength());
	}
	mSpaceship->orientation += mSpaceship->angular_velocity * dt;

}


