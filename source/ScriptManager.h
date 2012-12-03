/*
 * ScriptManager.h
 *
 *  Created on: Mar 29, 2009
 *      Author: daniel
 */

#ifndef SCRIPTMANAGER_H_
#define SCRIPTMANAGER_H_

class GameEngine;

/*extern "C"
{
	#include <lua.h>
	#include <lauxlib.h>
	#include <lualib.h>
}

//#include "tolua++.h"

#include <string>
#include <map>
using std::string;


class ScriptManager
{
protected:
	std::map<string, string> scripts;

	lua_State* luaState;
public:
	ScriptManager(GameEngine* engine);
	virtual ~ScriptManager();

	void add(string name, string filename);

	void execute(string name);
};*/

#endif /* SCRIPTMANAGER_H_ */
