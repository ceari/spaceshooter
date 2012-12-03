/*
 * AISpaceshipController.h
 *
 *  Created on: Mar 30, 2009
 *      Author: daniel
 */

#ifndef AISPACESHIPCONTROLLER_H_
#define AISPACESHIPCONTROLLER_H_

#include "SpaceshipController.h"
#include "../GameEngine.h"

class AISpaceshipController: public SpaceshipController
{
public:
	AISpaceshipController();
	virtual ~AISpaceshipController();

	virtual void update(double dt);
};

#endif /* AISPACESHIPCONTROLLER_H_ */
