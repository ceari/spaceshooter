/*
 * Engine.cpp
 *
 *  Created on: Mar 30, 2009
 *      Author: daniel
 */

#include "Engine.h"

Engine::Engine(Vec3 position, float angle): position(position), angle(angle)
{

}

Engine::~Engine()
{
	for (std::vector<DFXEngine::ParticleSystem*>::iterator it = particle_systems.begin(); it != particle_systems.end(); it++)
	{
		delete *it;
		*it = 0;
	}
}

void Engine::render(DFXEngine::Renderer& renderer)
{
	for (std::vector<DFXEngine::ParticleSystem*>::iterator it = particle_systems.begin(); it != particle_systems.end(); it++)
	{
		(*it)->draw(renderer);
	}
}


