/*
 * main.cpp
 *
 *  Created on: Mar 26, 2009
 *      Author: daniel
 */

#include "GameEngine.h"

#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#ifdef DEBUG
#include "core/Debug.h"
#endif

int main(int argc, char* argv[])
{
#ifdef DEBUG
	DFXEngine::Debug::Instance()->openLogFile("debug.txt");
#endif

	GameEngine* game = GameEngine::Instance();

	game->initialize(1024, 768);
	game->initTestlevel();


	static GLint Frames = 0;
	static GLint T0     = 0;
	float fps = 0;

	while (game->isRunning())
	{
		game->runFrame();

	    Frames++;
	    {
	    	GLint t = SDL_GetTicks();
			if (t - T0 >= 2000)
			{
			    GLfloat seconds = (t - T0) / 1000.0;
			    fps = Frames / seconds;
			    printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
			    T0 = t;
			    Frames = 0;
			}
	    }
	}

	return 0;
}
