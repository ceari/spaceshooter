/*
 * ParticleSystemManager.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef PARTICLESYSTEMMANAGER_H_
#define PARTICLESYSTEMMANAGER_H_

#include "Renderer.h"
#include "ParticleSystem.h"
#include <map>
#include <string>
using std::string;

namespace DFXEngine
{

	class ParticleSystemManager
	{
	protected:
		std::map<string, ParticleSystem*> mParticleSystems;
	public:
		ParticleSystemManager();
		virtual ~ParticleSystemManager();

		virtual bool add(string name, ParticleSystem* system);
		virtual void remove(string name);
		virtual ParticleSystem* get(string name);

		virtual void update(double dt);
		virtual void draw(Renderer& renderer);
	};

}

#endif /* PARTICLESYSTEMMANAGER_H_ */
