/*
 * OpenGLTextureManager.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef OPENGLTEXTUREMANAGER_H_
#define OPENGLTEXTUREMANAGER_H_

#include <map>
#include <string>
using std::string;

#include "../Texture.h"
#include "../TextureManager.h"
#include "OpenGLTexture.h"

namespace DFXEngine
{
	class OpenGLTextureManager : public TextureManager
	{
	protected:
		std::map<string, OpenGLTexture*> mTextures;
	public:
		OpenGLTextureManager();
		virtual ~OpenGLTextureManager();

		bool loadFromFile(string name, string filename);
		bool add(string name, OpenGLTexture* texture);
		bool remove(string name);
		Texture* get(string name);
	};
}

#endif /* OPENGLTEXTUREMANAGER_H_ */
