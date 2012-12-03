/*
 * TextureManager.h
 *
 * TextureManager interface class
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <map>
#include <string>
using std::string;

#include "Texture.h"

namespace DFXEngine
{

	class TextureManager
	{
	public:
		TextureManager();
		virtual ~TextureManager();

		virtual bool loadFromFile(string name, string filename) = 0;
		virtual bool remove(string name) = 0;
		virtual Texture* get(string name) = 0;
	};

}

#endif /* TEXTUREMANAGER_H_ */
