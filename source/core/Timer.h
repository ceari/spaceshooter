/*
 * CTimer.h
 *
 * timer to measure game loops and time steps etc.
 *
 *  Created on: Mar 21, 2009
 *      Author: daniel
 */

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <SDL/SDL.h>

namespace DFXEngine
{
	class Timer
	{
	private:
		unsigned int last_update;
		unsigned int start;
		unsigned int end;

	public:
		void startLoop();
		void endLoop();
		void update();
		unsigned int dt();

		unsigned int currentTime();

		void limitFPS(int fps);
	};
}

#endif // TIMER_H_INCLUDED
