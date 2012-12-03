/*
 * WeaponSystem.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef WEAPONSYSTEM_H_
#define WEAPONSYSTEM_H_

#include "BaseModel.h"

#include "../graphics/Math/Vec3.h"
#include "../graphics/Renderer.h"

class WeaponSystem
{
protected:
	float hull;

	float fire_rate;		// fire rate in possible launches per second
	float t_last_shot;		// time of last shot
	float energy_per_shot;

	bool useAmmo;
	unsigned int ammo;

	float hull_damage;
	float shield_damage;

	int projectile_type;

public:
	WeaponSystem();
	virtual ~WeaponSystem();
};

#endif /* WEAPONSYSTEM_H_ */
