/*
 * BackgroundTextureController.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef BACKGROUNDTEXTURECONTROLLER_H_
#define BACKGROUNDTEXTURECONTROLLER_H_

#include "Controller.h"
#include "../Camera.h"
#include "../models/BackgroundTexture.h"

class BackgroundTextureController: public Controller
{
protected:
	BackgroundTexture* mBGTexture;
public:
	BackgroundTextureController(BackgroundTexture* bgtexture);
	virtual ~BackgroundTextureController();

	void update(double dt);
};

#endif /* BACKGROUNDTEXTURECONTROLLER_H_ */
