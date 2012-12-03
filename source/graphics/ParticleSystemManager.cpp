/*
 * ParticleSystemManager.cpp
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#include "ParticleSystemManager.h"

namespace DFXEngine
{

	ParticleSystemManager::ParticleSystemManager()
	{
		// TODO Auto-generated constructor stub

	}

	ParticleSystemManager::~ParticleSystemManager()
	{
		// TODO Auto-generated destructor stub
	}

	bool ParticleSystemManager::add(string name, ParticleSystem *system)
	{
		std::map<std::string, ParticleSystem*>::iterator it = mParticleSystems.find(name);
		if (it != mParticleSystems.end()) return false;

		mParticleSystems.insert(std::pair<std::string, ParticleSystem*>(name, system));
		return true;
	}

	void ParticleSystemManager::remove(std::string name)
	{
		std::map<string, ParticleSystem*>::iterator it = mParticleSystems.find(name);
		if (it != mParticleSystems.end())
		{
			delete it->second;
			mParticleSystems.erase(it);
		}
	}

	ParticleSystem *ParticleSystemManager::get(string name)
	{
		std::map<string, ParticleSystem*>::iterator it = mParticleSystems.find(name);
		if (it != mParticleSystems.end())
			return it->second;
		else
			return NULL;
	}

	void ParticleSystemManager::update(double dt)
	{
		std::map<string, ParticleSystem*>::iterator it;

		for (it = mParticleSystems.begin(); it != mParticleSystems.end(); it++)
		{
			it->second->update(dt);
		}
	}

	void ParticleSystemManager::draw(Renderer& renderer)
	{
		std::map<string, ParticleSystem*>::iterator it;
		for (it = mParticleSystems.begin(); it != mParticleSystems.end(); it++)
		{
			it->second->draw(renderer);
		}
	}

}
