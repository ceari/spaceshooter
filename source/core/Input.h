/*
 * CInput.h
 *
 *  Created on: Mar 22, 2009
 *      Author: daniel
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <SDL/SDL.h>

namespace DFXEngine
{
	class Input
	{
	private:
		Uint8* m_piKeystates;
		Input();
		Input(Input const&) {};
		static Input* m_pInstance;

	public:
		static Input* Instance();

		bool isKeyDown(int keycode);

		void getMousePos(int* x, int* y);
		bool isMouseButtonDown(int button);

		void handleEvents();

	};
}

#endif /* INPUT_H_ */
