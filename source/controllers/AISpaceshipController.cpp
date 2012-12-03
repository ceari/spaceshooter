/*
 * AISpaceshipController.cpp
 *
 *  Created on: Mar 30, 2009
 *      Author: daniel
 */

#include "AISpaceshipController.h"
#include <cmath>
#include <iostream>
#include "../utility/algos.h"

AISpaceshipController::AISpaceshipController()
{
	// TODO Auto-generated constructor stub

}

AISpaceshipController::~AISpaceshipController()
{
	// TODO Auto-generated destructor stub
}

void AISpaceshipController::update(double dt)
{
	updateEngines(dt);

	Vec3 player_pos = GameEngine::Instance()->getPlayerShip()->getPosition();
	Vec3 v = player_pos - mSpaceship->position;

	const double PI = 3.1415;
	double desired_z_angle = atan2(v.y, v.x);

	if (desired_z_angle < 0) desired_z_angle += 2*PI;
	double cur_z_angle = (((int)mSpaceship->orientation.z % 360) - 90) * PI / 180.0f;
	if (cur_z_angle < 0) cur_z_angle += 2*PI;

	double angle_diff = desired_z_angle - cur_z_angle;
	if (angle_diff > PI) angle_diff -= 2*PI;
	else if (angle_diff < -PI) angle_diff += 2*PI;

	mSpaceship->angular_velocity.z = 0;

	if (angle_diff * angle_diff > 0.01)
	{
		if (angle_diff > 0)
			mSpaceship->angular_velocity.z = mSpaceship->max_angular_velocity;
		else
			mSpaceship->angular_velocity.z = -mSpaceship->max_angular_velocity;
	}

	mSpaceship->orientation += mSpaceship->angular_velocity * dt;

	mSpaceship->acceleration.x = 0;
	mSpaceship->acceleration.y = 0;

	if (v.getLength() > 200)
	{
		mSpaceship->acceleration.x = cos(cur_z_angle) * mSpaceship->max_acceleration;
		mSpaceship->acceleration.y = sin(cur_z_angle) * mSpaceship->max_acceleration;
	}

	mSpaceship->velocity += mSpaceship->acceleration * dt;
	if (mSpaceship->velocity.getLength() > mSpaceship->getMax_velocity())
	{
		mSpaceship->velocity = mSpaceship->velocity * (mSpaceship->getMax_velocity() / mSpaceship->velocity.getLength());
	}
	mSpaceship->position += mSpaceship->velocity * dt;
}
