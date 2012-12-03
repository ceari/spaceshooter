/*
 * Level.h
 *
 * holds model databases
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "models/BaseModel.h"
#include "models/GameObject.h"
#include "models/BackgroundObject.h"
#include "models/BackgroundPlanet.h"
#include "models/BackgroundTexture.h"
#include "models/GameObject.h"
#include "utility/algos.h"

#include <vector>
#include <algorithm>


class Level
{
private:
	static Level* mInstance;
	Level();
protected:
	std::vector<GameObject*> game_objects;
	std::vector<BackgroundObject*> background_objects;
public:
	static Level* Instance();
	virtual ~Level();

	std::vector<BackgroundObject*>& getBackgroundObjects();
	void addBackgroundObject(BackgroundObject* obj);

	std::vector<GameObject*>& getGameObjects();
	void addGameObject(GameObject* obj);

	GameObject* getGameObject(unsigned int id);
	BackgroundObject* getBackgroundObject(unsigned int id);

};

#endif /* LEVEL_H_ */
