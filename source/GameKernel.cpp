/*
 * GameKernel.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "GameKernel.h"

GameKernel* GameKernel::mInstance = 0;

GameKernel* GameKernel::Instance()
{
	if (!mInstance)
		mInstance = new GameKernel();
	return mInstance;
}

GameKernel::GameKernel()
{

}

GameKernel::~GameKernel()
{
	for (std::vector<Controller*>::iterator it = controllers.begin(); it != controllers.end(); it++)
	{
		delete *it;
		*it = 0;
	}
}

void GameKernel::addController(Controller *controller)
{
	controllers.push_back(controller);
}

void GameKernel::update(double game_time)
{
	double dt = game_time - last_update;

	std::vector<Controller*>::iterator it = controllers.begin();

	while (it != controllers.end())
	{
		if ((*it)->isActive())				// check if this controller is still alive
		{
			(*it)->update(dt);
			it++;
		}
		else								// if the controller's associated model dies the controller can set its status to dead and will be removed here
		{
			delete *it;
			*it = NULL;
			it = controllers.erase(it);		// move to next controller (or controllers.end())
		}
	}

	last_update = game_time;
}
