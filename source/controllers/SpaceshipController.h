/*
 * SpaceshipController.h
 *
 *  Created on: Mar 29, 2009
 *      Author: daniel
 */

#ifndef SPACESHIPCONTROLLER_H_
#define SPACESHIPCONTROLLER_H_

#include "Controller.h"
#include "../models/Spaceship.h"
#include "../models/Engine.h"
#include "../graphics/ParticleSystem.h"
#include <cmath>

class SpaceshipController: public Controller
{
protected:
	Spaceship* mSpaceship;

	void updateEngines(double dt);
public:
	SpaceshipController();
	virtual ~SpaceshipController();

	virtual void update(double dt) = 0;


    Spaceship *getSpaceship() const
    {
        return mSpaceship;
    }

    void setSpaceship(Spaceship *mSpaceship)
    {
        this->mSpaceship = mSpaceship;
    }

};

#endif /* SPACESHIPCONTROLLER_H_ */
