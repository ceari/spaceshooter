#include "Timer.h"

namespace DFXEngine
{

	void Timer::update()
	{
		last_update = SDL_GetTicks();

	}

	unsigned int Timer::dt()
	{
		return SDL_GetTicks() - last_update;

	}

	void Timer::startLoop()
	{
		start = SDL_GetTicks();
	}

	void Timer::endLoop()
	{
		end = SDL_GetTicks();
	}

	void Timer::limitFPS(int fps)
	{
		if ((SDL_GetTicks() - start) < 1000.0 / fps)
		{
			SDL_Delay( ( 1000.0 / fps ) - (SDL_GetTicks() - start) );
		}

	}

	unsigned int Timer::currentTime()
	{
		return SDL_GetTicks();
	}

}
