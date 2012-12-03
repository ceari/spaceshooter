/*
 * Spaceship.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include "GameObject.h"
#include "../graphics/Renderer.h"
#include "WeaponSystem.h"
#include "../graphics/Texture.h"
#include "../graphics/ParticleSystem.h"
#include "Engine.h"

#include <vector>

class Spaceship: public GameObject
{
	friend class SpaceshipController;
	friend class PlayerSpaceshipController;
	friend class AISpaceshipController;
protected:
	float hull;
	float shield;
	float weapon_energy;

	float max_velocity;
	float max_acceleration;

	float max_angular_velocity;
	float max_angular_acceleration;


	std::vector<WeaponSystem*> weapon_systems;
	std::vector<Engine*> engines;

	DFXEngine::Texture* texture;

	int faction_id;
	bool hostile;
public:
	Spaceship();
	virtual ~Spaceship();

	virtual void render(DFXEngine::Renderer& renderer);

    float getMax_angular_velocity() const
    {
        return max_angular_velocity;
    }

    void setMax_angular_velocity(float max_angular_velocity)
    {
        this->max_angular_velocity = max_angular_velocity;
    }

    float getMax_angular_acceleration() const
    {
        return max_angular_acceleration;
    }

    void setMax_angular_acceleration(float max_angular_acceleration)
    {
        this->max_angular_acceleration = max_angular_acceleration;
    }

    DFXEngine::Texture *getTexture() const
    {
        return texture;
    }

    void setTexture(DFXEngine::Texture *texture)
    {
        this->texture = texture;
    }

    float getHull() const
    {
        return hull;
    }

    void setHull(float hull)
    {
        this->hull = hull;
    }

    float getShield() const
    {
        return shield;
    }

    void setShield(float shield)
    {
        this->shield = shield;
    }

    float getWeapon_energy() const
    {
        return weapon_energy;
    }

    void setWeapon_energy(float weapon_energy)
    {
        this->weapon_energy = weapon_energy;
    }

    float getMax_velocity() const
    {
        return max_velocity;
    }

    void setMax_velocity(float max_velocity)
    {
        this->max_velocity = max_velocity;
    }

    float getMax_acceleration() const
    {
        return max_acceleration;
    }

    void setMax_acceleration(float max_acceleration)
    {
        this->max_acceleration = max_acceleration;
    }

    void addEngine(Engine* engine)
    {
    	engines.push_back(engine);
    }

};

#endif /* SPACESHIP_H_ */
