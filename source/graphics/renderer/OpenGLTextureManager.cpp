/*
 * OpenGLTextureManager.cpp
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#include "OpenGLTextureManager.h"

namespace DFXEngine
{

	OpenGLTextureManager::OpenGLTextureManager()
	{
		// TODO Auto-generated constructor stub

	}

	OpenGLTextureManager::~OpenGLTextureManager()
	{
		std::map<string, OpenGLTexture*>::iterator it;
		for (it = mTextures.begin(); it != mTextures.end(); it++)
		{
			delete it->second;
		}
		mTextures.clear();
	}

	bool OpenGLTextureManager::loadFromFile(string name, string filename)
	{
		std::map<string, OpenGLTexture*>::iterator it = mTextures.find(name);
		if (it != mTextures.end())
		{
		#ifdef DEBUG
				Debug::Instance()->writeLn("OpenGLTextureManager::loadFromFile failed loading " + filename + " with id " + name + " - already exists");
		#endif
			return false;
		}

		OpenGLTexture* texture = new OpenGLTexture();
		if (!texture->loadFromFile(filename))
		{
		#ifdef DEBUG
				Debug::Instance()->writeLn("OpenGLTextureManager::loadFromFile failed loading '" + filename + "' with id '" + name + "' - texture loadFromFile call failed");
		#endif
			delete texture;
			return false;
		}

		mTextures.insert(std::pair<string, OpenGLTexture*>(name, texture));
		#ifdef DEBUG
				Debug::Instance()->writeLn("OpenGLTextureManager::loadFromFile loaded '" + filename + "' with id '" + name + "' successfully");
		#endif
		return true;
	}

	bool OpenGLTextureManager::add(string name, OpenGLTexture *texture)
	{
		std::map<string, OpenGLTexture*>::iterator it = mTextures.find(name);
		if (it != mTextures.end())
		{
		#ifdef DEBUG
				Debug::Instance()->writeLn("OpenGLTextureManager::add failed, id '" + name + "' already exists");
		#endif
			return false;
		}

		mTextures.insert(std::pair<string, OpenGLTexture*>(name, texture));
		#ifdef DEBUG
				Debug::Instance()->writeLn("OpenGLTextureManager::add succeeded, id '" + name + "'");
		#endif
		return true;
	}

	bool OpenGLTextureManager::remove(string name)
	{
		std::map<string, OpenGLTexture*>::iterator it = mTextures.find(name);
		if (it == mTextures.end()) return false;	// Texture with this name doesn't exist

		delete it->second;
		mTextures.erase(name);
		return true;
	}

	Texture *OpenGLTextureManager::get(string name)
	{
		std::map<string, OpenGLTexture*>::iterator it = mTextures.find(name);
		if (it == mTextures.end())
			return NULL;
		else return it->second;
	}
}





