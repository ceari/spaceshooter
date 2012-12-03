/*
 * GameKernel.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef GAMEKERNEL_H_
#define GAMEKERNEL_H_

#ifdef DEBUG
#include "core/Debug.h"
#endif

#include "controllers/Controller.h"

#include <vector>


class GameKernel
{
private:
	static GameKernel* mInstance;
	GameKernel();
	virtual ~GameKernel();
protected:
	double last_update;
	std::vector<Controller*> controllers;
public:
	static GameKernel* Instance();

	void addController(Controller* controller);
	void update(double game_time);
};

#endif /* GAMEKERNEL_H_ */
