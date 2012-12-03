/*
 * BackgroundPlanetController.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef BACKGROUNDPLANETCONTROLLER_H_
#define BACKGROUNDPLANETCONTROLLER_H_

#include "Controller.h"
#include "../models/BackgroundPlanet.h"

class BackgroundPlanetController: public Controller
{
protected:
	BackgroundPlanet* mPlanet;
public:
	BackgroundPlanetController(BackgroundPlanet* planet);
	virtual ~BackgroundPlanetController();

	void update(double dt);
};

#endif /* BACKGROUNDPLANETCONTROLLER_H_ */
