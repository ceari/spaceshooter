/*
 * Camera.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "Camera.h"

Camera* Camera::mInstance = 0;

Camera* Camera::Instance()
{
	if (!mInstance)
		mInstance = new Camera();
	return mInstance;
}

Camera::Camera()
{
	// TODO Auto-generated constructor stub

}

Camera::~Camera()
{
	// TODO Auto-generated destructor stub
}
