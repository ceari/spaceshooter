/*
 * AnimatedSprite.h
 *
 *  Created on: Mar 25, 2009
 *      Author: daniel
 */

#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_

#include "Texture.h"
#include "Math/Rect.h"
#include "Renderer.h"

#include <SDL/SDL.h> 	// TODO: wrapper for SDL_GetTicks

#include <string>
#include <vector>

namespace DFXEngine
{

	class AnimatedSprite
	{
	private:
		Texture* m_texture;
		bool m_paused;
		int m_texture_rows;			// number of rows in the texture
		int m_texture_cols;			// number of columns in the texture
		int m_length;				// number of frames in the animation
		std::vector<int> m_delays;		// vector of ints specifying the time each frame stays active
		int m_frame;				// currently active frame
		int m_last_time;			// last time the animation was updated

		int m_frame_width;
		int m_frame_height;
		int m_iterations;
	public:
		AnimatedSprite(Texture* texture, int rows, int cols, int length, int default_delay, int iterations);
		virtual ~AnimatedSprite();

		void update();
		void draw(Renderer& renderer, float x, float y, float z, float angle);
		void pause();
		void resume();
		void changeTexture(Texture* texture, int rows, int cols, int length);
		void setDelay(int position, int delay);	// set delay of frame indexed by position (0 to length-1)
		void setFrame(int frame);
	};

}

#endif /* ANIMATEDSPRITE_H_ */
