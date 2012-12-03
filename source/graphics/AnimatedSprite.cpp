/*
 * AnimatedSprite.cpp
 *
 *  Created on: Mar 25, 2009
 *      Author: daniel
 */

#include "AnimatedSprite.h"

namespace DFXEngine
{

	AnimatedSprite::AnimatedSprite(Texture* texture, int rows, int cols, int length, int default_delay, int iterations)
	{
		m_texture = texture;
		m_texture_rows = rows;
		m_texture_cols = cols;
		m_length = length;

		m_paused = false;

		m_frame_width = texture->getWidth() / cols;
		m_frame_height = texture->getHeight() / rows;

		m_last_time = SDL_GetTicks();
		m_frame = 0;

		m_iterations = iterations;

		m_delays.resize(length, default_delay);
	}

	AnimatedSprite::~AnimatedSprite()
	{

	}

	void AnimatedSprite::update()
	{
		if (m_paused) return;

		if (SDL_GetTicks() >= m_last_time + m_delays[m_frame])
		{
			m_last_time = SDL_GetTicks();

			if (m_frame >= m_length - 1)
			{
				m_iterations -= 1;
				if (m_iterations <= 0)
				{
					m_paused = true;
					return;
				}
				else
				{
					m_frame = 0;
				}
			}
			else
			{
				m_frame++;
			}
		}

	}

	void AnimatedSprite::draw(Renderer& renderer, float x, float y, float z, float angle)
	{
		if (m_paused && m_frame == m_length - 1) return;

		Rect tex_coords;
		int u = m_frame % m_texture_cols;
		int v = m_frame / m_texture_rows;

		tex_coords.x = (1 / (float)m_texture_cols) * (float)u;
		tex_coords.y = (1 / (float)m_texture_rows) * (float)v;
		tex_coords.w = (1/(float)m_texture_cols);
		tex_coords.h = (1/(float)m_texture_rows);

		renderer.renderTexturedQuad(Vec3(x,y,z),Vec3(0,0,angle), m_texture, tex_coords, m_frame_height, m_frame_width);
	}

	void AnimatedSprite::pause()
	{
		m_paused = true;
	}

	void AnimatedSprite::resume()
	{
		m_paused = false;
		m_last_time = SDL_GetTicks();
	}

	void AnimatedSprite::changeTexture(Texture *texture, int rows, int cols, int length)
	{
		m_texture = texture;
		m_texture_rows = rows;
		m_texture_cols = cols;
		m_length = 0;
		m_frame = 0;

		m_frame_width = texture->getWidth() / cols;
		m_frame_height = texture->getHeight() / rows;
		m_last_time = SDL_GetTicks();
		m_delays.resize(length);
	}

	void AnimatedSprite::setDelay(int position, int delay)
	{
		if (position < m_length)
			m_delays[position] = delay;
	}

	void AnimatedSprite::setFrame(int frame)
	{
		if (frame < m_length)
			m_frame = frame;
	}

}
