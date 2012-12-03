/*
 * Controller.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>
using std::string;

class Controller
{
protected:
	bool active;

	bool runScriptOnUpdate;
	string script_name;
public:
	Controller();
	virtual ~Controller();

	virtual void update(double dt) = 0;

    bool getActive() const
    {
        return active;
    }

    void setActive(bool active)
    {
        this->active = active;
    }

    bool getRunScriptOnUpdate() const
    {
        return runScriptOnUpdate;
    }

    void setRunScriptOnUpdate(bool runScriptOnUpdate)
    {
        this->runScriptOnUpdate = runScriptOnUpdate;
    }

    string getScript_name() const
    {
        return script_name;
    }

    void setScript_name(string script_name)
    {
        this->script_name = script_name;
    }

    bool isActive() const { return active; };
	void kill() { this->active = false; };

};

#endif /* CONTROLLER_H_ */
