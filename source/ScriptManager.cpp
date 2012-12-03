/*
 * ScriptManager.cpp
 *
 *  Created on: Mar 29, 2009
 *      Author: daniel
 */

#include "ScriptManager.h"
/*
ScriptManager::ScriptManager(GameEngine* engine)
{
	luaState = lua_open();
	luaL_openlibs(luaState);

	// TODO: expose engine interface here

	//tolua_pushusertype(luaState, static_cast<void*>(&engine), "GameEngine");
	//lua_setglobal(luaState, "Game");
}

ScriptManager::~ScriptManager()
{
	lua_close(luaState);
}

void ScriptManager::execute(string name)
{
	luaL_dofile(luaState, scripts[name].c_str());
}

void ScriptManager::add(string name, string filename)
{
	if (scripts.find(name) != scripts.end())
	{
		scripts.insert(std::pair<string, string>(name, filename));
	}
}

*/


