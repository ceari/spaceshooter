/*
 * CDebug.cpp
 *
 *  Created on: Mar 21, 2009
 *      Author: daniel
 */

#include "Debug.h"

namespace DFXEngine
{

	Debug* Debug::m_pInstance = 0;


	Debug *Debug::Instance()
	{
		if (!m_pInstance)
			m_pInstance = new Debug;
		return m_pInstance;

	}

	void Debug::openLogFile(std::string filename)
	{
		m_File.open(filename.c_str(), std::ios::out);
	}

	void Debug::write(std::string text)
	{
		if (m_File.is_open())
			m_File << text;
	}

	void Debug::writeLn(std::string text)
	{
		if (m_File.is_open())
			m_File << text << std::endl;
	}


	bool Debug::closeLogFile()
	{
		if (m_File.is_open())
			m_File.close();
	}

}



