/*
 * BackgroundPlanetController.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "BackgroundPlanetController.h"

BackgroundPlanetController::BackgroundPlanetController(BackgroundPlanet* planet)
{
	mPlanet = planet;

}

BackgroundPlanetController::~BackgroundPlanetController()
{
	// TODO Auto-generated destructor stub
}

void BackgroundPlanetController::update(double dt)
{
	mPlanet->velocity += mPlanet->acceleration * dt;
	mPlanet->position += mPlanet->velocity * dt;

	mPlanet->angular_velocity += mPlanet->angular_acceleration * dt;
	mPlanet->orientation += mPlanet->angular_velocity * dt;
}


