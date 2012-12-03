/*
 * BaseModel.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "BaseModel.h"

unsigned int BaseModel::next_id = 0;

BaseModel::BaseModel()
{
	this->id = next_id++;
}

BaseModel::~BaseModel()
{
	// TODO Auto-generated destructor stub
}
