/*
 * Camera.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "graphics/Math/Vec3.h"

class Camera
{
private:
	static Camera* mInstance;
	Camera();
	virtual ~Camera();

protected:
	Vec3 position;
	Vec3 lookAt;
public:
	static Camera* Instance();

	Vec3 getPosition() { return position; };
	void setPosition(Vec3 position) { this->position = position; };

	void setCameraNormalDistance(int screen_h)
	{
		const double magicnumber = -1.2071068f;
		lookAt.z = 0;
		lookAt.x = position.x;
		lookAt.y = position.y;
		position.z = magicnumber * screen_h;
	}

	Vec3 getLookAt() { return lookAt; };
	void setLookAt(Vec3 lookAt) { this->lookAt = lookAt; };

	void moveCameraRelative(Vec3 delta_move) { position += delta_move; lookAt += delta_move; };
	void moveCamera(Vec3 moveTo) { position.x = lookAt.x = moveTo.x; position.y = lookAt.y = moveTo.y; };
};

#endif /* CAMERA_H_ */
