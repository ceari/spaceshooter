/*
 * CDebug.h
 *
 * simple logging class singleton
 * writes to a file
 *
 *  Created on: Mar 21, 2009
 *      Author: daniel
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <fstream>
#include <string>
using std::string;

namespace DFXEngine
{

	class Debug
	{
	public:
		static Debug* Instance();

		void openLogFile(string filename);
		void write(string text);
		void writeLn(string text);
		bool closeLogFile();

	private:
		Debug() {};
		Debug(Debug const&) {};
		static Debug* m_pInstance;

		std::ofstream m_File;
	};
}

#endif /* DEBUG_H_ */
