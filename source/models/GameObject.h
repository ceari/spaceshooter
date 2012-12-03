/*
 * GameObject.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "BaseModel.h"
#include "../graphics/Math/Vec3.h"
#include "../graphics/Renderer.h"

class GameObject: public BaseModel
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void render(DFXEngine::Renderer& renderer) = 0;
};

#endif /* GAMEOBJECT_H_ */
