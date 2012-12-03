/*
 * PlayerSpaceshipController.h
 *
 *  Created on: Mar 29, 2009
 *      Author: daniel
 */

#ifndef PLAYERSPACESHIPCONTROLLER_H_
#define PLAYERSPACESHIPCONTROLLER_H_

#include "SpaceshipController.h"
#include "../core/Input.h"
#include <cmath>

class PlayerSpaceshipController: public SpaceshipController
{
public:
	PlayerSpaceshipController();
	virtual ~PlayerSpaceshipController();

	void update(double dt);
};

#endif /* PLAYERSPACESHIPCONTROLLER_H_ */
