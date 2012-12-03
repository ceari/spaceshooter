/*
 * Light.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "Math/Color4.h"
#include "Math/Vec3.h"

namespace DFXEngine
{

	class Light
	{
	protected:
		unsigned int id;
		Color4 ambient;
		Color4 diffuse;
		Color4 specular;
		Vec3 position;

		bool active;
	public:
		Light();
		virtual ~Light();
		bool getActive() const
		{
			return active;
		}

		void setActive(bool active)
		{
			this->active = active;
		}

		Color4 getAmbient() const
		{
			return ambient;
		}

		void setAmbient(Color4 ambient)
		{
			this->ambient = ambient;
		}

		Color4 getDiffuse() const
		{
			return diffuse;
		}

		void setDiffuse(Color4 diffuse)
		{
			this->diffuse = diffuse;
		}

		Color4 getSpecular() const
		{
			return specular;
		}

		void setSpecular(Color4 specular)
		{
			this->specular = specular;
		}

		Vec3 getPosition() const
		{
			return position;
		}

		void setPosition(Vec3 position)
		{
			this->position = position;
		}

		unsigned int getId() const
		{
			return id;
		}

		void setId(unsigned int id)
		{
			this->id = id;
		}

	};

}

#endif /* LIGHT_H_ */
