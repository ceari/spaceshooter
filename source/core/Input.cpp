/*
 * CInput.cpp
 *
 *  Created on: Mar 22, 2009
 *      Author: daniel
 */

#include "Input.h"

namespace DFXEngine
{

	Input* Input::m_pInstance = 0;

	Input::Input()
	{
		m_piKeystates = SDL_GetKeyState(NULL);
	}

	Input* Input::Instance()
	{
		if (!m_pInstance)
			m_pInstance = new Input;
		return m_pInstance;
	}


	bool Input::isKeyDown(int keycode)
	{
		return m_piKeystates[keycode];
	}

	void Input::getMousePos(int *x, int *y)
	{
		SDL_GetMouseState(x, y);
	}

	bool Input::isMouseButtonDown(int button)
	{
		Uint8 state = SDL_GetMouseState(NULL, NULL);
		return state & SDL_BUTTON(button);
	}

	void Input::handleEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				SDL_Quit();
			}
		}
	}

}
