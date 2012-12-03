/*
 * Level.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "Level.h"

Level* Level::mInstance = 0;

Level* Level::Instance()
{
	if (!mInstance)
		mInstance = new Level();
	return mInstance;
}

class BackgroundObjectZCompare
{
public:
	bool operator() (const BackgroundObject* lhs, const BackgroundObject* rhs)
	{
		return lhs->getPosition().z > rhs->getPosition().z;
	}
};

class GameObjectZCompare
{
public:
	bool operator() (const GameObject* lhs, const GameObject* rhs)
	{
		return lhs->getPosition().z > rhs->getPosition().z;
	}
};

Level::Level()
{

}

Level::~Level()
{
	for (std::vector<BackgroundObject*>::iterator it = background_objects.begin(); it != background_objects.end(); it++)
	{
		delete *it;
		*it = 0;
	}
	for (std::vector<GameObject*>::iterator it = game_objects.begin(); it != game_objects.end(); it++)
	{
		delete *it;
		*it = 0;
	}
}

std::vector<BackgroundObject*> & Level::getBackgroundObjects()
{
	return background_objects;
}

void Level::addBackgroundObject(BackgroundObject *obj)
{
	background_objects.push_back(obj);
	algorithms::insertion_sort(background_objects, BackgroundObjectZCompare());
	//stable_sort(background_objects.begin(), background_objects.end(), BackgroundObjectZCompare()); // sort by z value for alpha blending to work correctly
}

std::vector<GameObject*> & Level::getGameObjects()
{
	return game_objects;
}

void Level::addGameObject(GameObject *obj)
{
	game_objects.push_back(obj);
	algorithms::insertion_sort(game_objects, GameObjectZCompare());
	//stable_sort(game_objects.begin(), game_objects.end(), GameObjectZCompare());
}






