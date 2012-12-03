/*
 * Engine.h
 *
 * composite part of Spaceships
 *
 *  Created on: Mar 30, 2009
 *      Author: daniel
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include "../graphics/Math/Vec3.h"
#include "../graphics/ParticleSystem.h"
#include <vector>


class Engine
{
	friend class Spaceship;
	friend class SpaceshipController;
protected:
	std::vector<DFXEngine::ParticleSystem*> particle_systems;

	Vec3 position;
    float angle;
public:
    Engine(Vec3 position, float angle);
    virtual ~Engine();
    void addParticleSystem(DFXEngine::ParticleSystem *ps)
    {
        particle_systems.push_back(ps);
    }

    std::vector<DFXEngine::ParticleSystem*> & getParticleSystems()
    {
        return particle_systems;
    }

    virtual void render(DFXEngine::Renderer & renderer);


    Vec3 getPosition() const
    {
        return position;
    }

    void setPosition(Vec3 position)
    {
        this->position = position;
    }

    float getAngle() const
    {
        return angle;
    }

    void setAngle(float angle)
    {
        this->angle = angle;
    }

};

#endif /* ENGINE_H_ */
