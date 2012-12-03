/*
 * ParticleSystem.cpp
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#include "ParticleSystem.h"

namespace DFXEngine
{

	int uniform_rand(int min, int max)
	{
		double d = rand() * ( 1.0 / ( RAND_MAX + 1.0 ) );
		return min + d * (max - min);
	}

	ParticleSystem::ParticleSystem()
	{
		// TODO Auto-generated constructor stub

	}

	ParticleSystem::~ParticleSystem()
	{
		// TODO Auto-generated destructor stub
	}

	void ParticleSystem::update(double dt)
	{
		if (mPaused) return;

		std::vector<Particle>::iterator it;
		for (it = mParticles.begin(); it != mParticles.end(); ++it)
		{
			if (it->mActive)
			{
				it->mVelocity += it->mAcceleration * dt;
				it->mPosition += it->mVelocity * dt;

				it->mLife -= it->mFadeSpeed * dt;

				if (it->mLife < 0) // particle dead, spawn new particle
				{
					it->mPosition.x = mPosition.x + ((float)uniform_rand(-100* mPositionDeviation.x, 100 * mPositionDeviation.x) / 100.0f) * mPositionDeviation.x;
					it->mPosition.y = mPosition.y + ((float)uniform_rand(-100* mPositionDeviation.y, 100 * mPositionDeviation.y) / 100.0f) * mPositionDeviation.y;
					it->mPosition.z = mPosition.z + ((float)uniform_rand(-100* mPositionDeviation.z, 100 * mPositionDeviation.z) / 100.0f) * mPositionDeviation.z;

					it->mVelocity.x = mVelocity.x + ((float)uniform_rand(-100* mVelocityDeviation.x, 100 * mVelocityDeviation.x) / 100.0f) * mVelocityDeviation.x;
					it->mVelocity.y = mVelocity.y + ((float)uniform_rand(-100* mVelocityDeviation.y, 100 * mVelocityDeviation.y) / 100.0f) * mVelocityDeviation.y;
					it->mVelocity.z = mVelocity.z + ((float)uniform_rand(-100* mVelocityDeviation.z, 100 * mVelocityDeviation.z) / 100.0f) * mVelocityDeviation.z;
					it->mAcceleration = mAcceleration;
					it->mRed = mRed;
					it->mGreen = mGreen;
					it->mBlue = mBlue;
					it->mLife = 1;
					it->mFadeSpeed = mFadeSpeed * (1 + (float)uniform_rand(-mFadeRandomFactor, mFadeRandomFactor) / 100.0f);
				}
			}
		}
	}

	void ParticleSystem::draw(Renderer& renderer)
	{
		renderer.renderParticleSystem(*this);
	}

	void ParticleSystem::initialize(Texture *texture, int count, Vec3 p, Vec3 v, Vec3 a, float r, float g, float b, float fade_per_ms, float random_factor, Vec3 p_deviation, Vec3 v_deviation)
	{
		mPosition = p;
		mVelocity = v;
		mAcceleration = a;
		mRed = r;
		mGreen = g;
		mBlue = b;

		mFadeRandomFactor = random_factor;
		mFadeSpeed = fade_per_ms;
		mVelocityDeviation = v_deviation;
		mPositionDeviation = p_deviation;

		mParticles.resize(count);
		mPaused = true;

		mTexture = texture;

		std::vector<Particle>::iterator it;
		for (it = mParticles.begin(); it != mParticles.end(); ++it)
		{
			it->mActive = true;

			it->mPosition.x = p.x + ((float)uniform_rand(-100* p_deviation.x, 100 * p_deviation.x) / 100.0f) * p_deviation.x;
			it->mPosition.y = p.y + ((float)uniform_rand(-100* p_deviation.y, 100 * p_deviation.y) / 100.0f) * p_deviation.y;
			it->mPosition.z = p.z + ((float)uniform_rand(-100* p_deviation.z, 100 * p_deviation.z) / 100.0f) * p_deviation.z;

			it->mVelocity.x = v.x + ((float)uniform_rand(-100* v_deviation.x, 100 * v_deviation.x) / 100.0f) * v_deviation.x;
			it->mVelocity.y = v.y + ((float)uniform_rand(-100* v_deviation.y, 100 * v_deviation.y) / 100.0f) * v_deviation.y;
			it->mVelocity.z = v.z + ((float)uniform_rand(-100* v_deviation.z, 100 * v_deviation.z) / 100.0f) * v_deviation.z;
			it->mAcceleration = a;
			it->mRed = r;
			it->mGreen = g;
			it->mBlue = b;
			it->mLife = 1;
			it->mFadeSpeed = (1 + (float)uniform_rand(-random_factor, random_factor) / 100.0f);
		}
	}

	void ParticleSystem::setPosition(Vec3 p)
	{
		mPosition = p;
	}

	void ParticleSystem::setVelocity(Vec3 v)
	{
		mVelocity = v;
	}

	void ParticleSystem::setAcceleration(Vec3 a)
	{
		mAcceleration = a;
	}

	void ParticleSystem::pause()
	{
		mPaused = true;
	}

	void ParticleSystem::resume()
	{
		mPaused = false;
	}

	const Texture *ParticleSystem::getTexture() const
	{
		return mTexture;
	}

	const std::vector<Particle> & ParticleSystem::getParticles() const
	{
		return mParticles;
	}

}


















