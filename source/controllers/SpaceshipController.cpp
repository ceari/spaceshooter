/*
 * SpaceshipController.cpp
 *
 *  Created on: Mar 29, 2009
 *      Author: daniel
 */

#include "SpaceshipController.h"

SpaceshipController::SpaceshipController()
{

}

SpaceshipController::~SpaceshipController()
{
	// TODO Auto-generated destructor stub
}


void SpaceshipController::updateEngines(double dt)
{
	std::vector<Engine*>::iterator it;
	for (it = mSpaceship->engines.begin(); it != mSpaceship->engines.end(); it++)
	{
		Engine& engine = **it;
		const double pi = 3.1415f;
		const double phi = (mSpaceship->orientation.z  + engine.angle) * pi / 180.0f;
		double x = mSpaceship->position.x + engine.position.x * cos(phi) + engine.position.y * -sin(phi);
		double y = mSpaceship->position.y + engine.position.x * sin(phi) + engine.position.y * cos(phi);

		for (std::vector<DFXEngine::ParticleSystem*>::iterator it2 = engine.getParticleSystems().begin(); it2 != engine.getParticleSystems().end(); it2++)
		{
			DFXEngine::ParticleSystem* ps = *it2;
			ps->setPosition(Vec3(x, y, mSpaceship->position.z));
			const double engine_flame_vel = mSpaceship->acceleration.getLength() / 2;
			ps->setVelocity(Vec3(mSpaceship->velocity.x + engine_flame_vel * cos(phi + 0.5*pi), mSpaceship->velocity.y + engine_flame_vel * sin(phi + 0.5* pi), 0));
			ps->update(dt);
		}
	}
}
