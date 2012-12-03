/*
 * Particle.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Math/Vec3.h"

namespace DFXEngine
{

	class CParticleSystem;	// forward declaration to avoid mutual #include

	class Particle
	{
	public:
		bool mActive;
		float mLife;
		float mFadeSpeed;			// fade speed per millisecond (life -= fade_speed * dt) with dt in ms
		float mRed, mGreen, mBlue;
		Vec3 mPosition, mVelocity, mAcceleration;			// position, velocity, acceleration
	public:
		Particle();
		virtual ~Particle();
	};

}

#endif /* PARTICLE_H_ */
