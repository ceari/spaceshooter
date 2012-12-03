/*
 * Spaceship.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "Spaceship.h"

Spaceship::Spaceship()
{
	// TODO Auto-generated constructor stub

}

Spaceship::~Spaceship()
{
	for (std::vector<Engine*>::iterator it = engines.begin(); it != engines.end(); it++)
	{
		delete *it;
		*it = 0;
	}
	for (std::vector<WeaponSystem*>::iterator it = weapon_systems.begin(); it != weapon_systems.end(); it++)
	{
		delete *it;
		*it = 0;
	}
}

void Spaceship::render(DFXEngine::Renderer& renderer)
{
	std::vector<Engine*>::iterator it;
	for (it = engines.begin(); it != engines.end(); it++)
		(*it)->render(renderer);
	renderer.renderTexturedQuad(position, orientation, texture);
}


