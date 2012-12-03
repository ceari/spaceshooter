/*
 * ParticleSystem.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef PARTICLESYSTEM_H_
#define PARTICLESYSTEM_H_

#include "Texture.h"
#include "Particle.h"
#include "Renderer.h"
#include "Math/Vec3.h"
#include <cstdlib>
#include <vector>

namespace DFXEngine
{

	class Renderer;
	class ParticleSystem
	{
	protected:
		Texture* mTexture;
		std::vector<Particle> mParticles;
		bool mPaused;

		/* emitter parameters */
		Vec3 mPosition, mVelocity, mAcceleration;
		float mRed, mGreen, mBlue;
		float mFadeRandomFactor;
		float mFadeSpeed;

		Vec3 mPositionDeviation;
		Vec3 mVelocityDeviation;
	public:
		ParticleSystem();
		virtual ~ParticleSystem();

		virtual void update(double dt);
		virtual void draw(Renderer& renderer);
		virtual void initialize(Texture* texture, int count, Vec3 p, Vec3 v, Vec3 a, float r, float g, float b, float fade_per_ms, float random_factor, Vec3 p_deviation, Vec3 v_deviation);
		virtual void setPosition(Vec3 p);
		virtual void setVelocity(Vec3 v);
		virtual void setAcceleration(Vec3 a);
		virtual void pause();
		virtual void resume();

		virtual const Texture* getTexture() const;
		virtual const std::vector<Particle>& getParticles() const;

	};

}

#endif /* PARTICLESYSTEM_H_ */
