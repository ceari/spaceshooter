/*
 * BaseModel.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef BASEMODEL_H_
#define BASEMODEL_H_

#include "../graphics/Math/Vec3.h"
#include "../graphics/Renderer.h"
#include "../controllers/Controller.h"

class BaseModel
{
private:
	static unsigned int next_id;		// used to assign every object that gets created an unique ID

protected:
	unsigned int id;
	unsigned int type_id;

	Controller* mController;
    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
    Vec3 orientation;
    Vec3 angular_velocity;
    Vec3 angular_acceleration;
public:
    BaseModel();
    virtual ~BaseModel();
    virtual void render(DFXEngine::Renderer & renderer) =0;
    unsigned int getId() const
    {
        return id;
    }

    Controller *getController() const
    {
        return mController;
    }

    void setController(Controller *mController)
    {
        this->mController = mController;
    }

    Vec3 getVelocity() const
    {
        return velocity;
    }

    void setVelocity(Vec3 velocity)
    {
        this->velocity = velocity;
    }

    Vec3 getAcceleration() const
    {
        return acceleration;
    }

    void setAcceleration(Vec3 acceleration)
    {
        this->acceleration = acceleration;
    }

    Vec3 getAngular_velocity() const
    {
        return angular_velocity;
    }

    void setAngular_velocity(Vec3 angular_velocity)
    {
        this->angular_velocity = angular_velocity;
    }

    Vec3 getAngular_acceleration() const
    {
        return angular_acceleration;
    }

    void setAngular_acceleration(Vec3 angular_acceleration)
    {
        this->angular_acceleration = angular_acceleration;
    }

    Vec3 getPosition() const
    {
        return position;
    }

    void setPosition(Vec3 position)
    {
        this->position = position;
    }

    Vec3 getOrientation() const
    {
        return orientation;
    }

    void setOrientation(Vec3 orientation)
    {
        this->orientation = orientation;
    }

};

#endif /* BASEMODEL_H_ */
