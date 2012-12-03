/*
 * BackgroundPlanet.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef BACKGROUNDPLANET_H_
#define BACKGROUNDPLANET_H_

#include "BackgroundObject.h"
#include "../graphics/Renderer.h"

class BackgroundPlanet: public BackgroundObject
{
	friend class BackgroundPlanetController;
protected:
	float radius;
	float sphere_slices;
	DFXEngine::Texture* texture;
public:
	BackgroundPlanet();
	virtual ~BackgroundPlanet();

	virtual void render(DFXEngine::Renderer& renderer);
    float getRadius() const
    {
        return radius;
    }

    void setRadius(float radius)
    {
        this->radius = radius;
    }

    float getSphere_slices() const
    {
        return sphere_slices;
    }

    void setSphere_slices(float sphere_slices)
    {
        this->sphere_slices = sphere_slices;
    }

    DFXEngine::Texture *getTexture() const
    {
        return texture;
    }

    void setTexture(DFXEngine::Texture *texture)
    {
        this->texture = texture;
    }

};

#endif /* BACKGROUNDPLANET_H_ */
