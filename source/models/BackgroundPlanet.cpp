/*
 * BackgroundPlanet.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "BackgroundPlanet.h"

BackgroundPlanet::BackgroundPlanet()
{
	// TODO Auto-generated constructor stub

}

BackgroundPlanet::~BackgroundPlanet()
{
	// TODO Auto-generated destructor stub
}

void BackgroundPlanet::render(DFXEngine::Renderer& renderer)
{
	renderer.enableLighting();
	renderer.renderTexturedSphere(this->position, this->orientation, this->radius, this->sphere_slices, this->texture);
	renderer.disableLighting();
}


