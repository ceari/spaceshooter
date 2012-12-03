/*
 * Projectile.h
 *
 *  Created on: Apr 7, 2009
 *      Author: daniel
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "GameObject.h"
#include "Spaceship.h"

class Projectile: public GameObject
{
protected:
	bool homing;
	Spaceship* target;

	double lifetime;

public:
	Projectile();
	virtual ~Projectile();
};

#endif /* PROJECTILE_H_ */
