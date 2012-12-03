/*
 * BackgroundObject.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef BACKGROUNDOBJECT_H_
#define BACKGROUNDOBJECT_H_

#include "BaseModel.h"
#include "../graphics/Renderer.h"

class BackgroundObject: public BaseModel
{
public:
	BackgroundObject();
	virtual ~BackgroundObject();

	virtual void render(DFXEngine::Renderer& renderer) = 0;
};

#endif /* BACKGROUNDOBJECT_H_ */
