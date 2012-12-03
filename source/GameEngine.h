/*
 * GameEngine.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_



#include "graphics/TextureManager.h"
#include "graphics/renderer/OpenGLTextureManager.h"
#include "graphics/renderer/SDLOpenGLRenderDevice.h"
#include "graphics/renderer/includes.h"	// for SDL constants
#include "graphics/RenderDevice.h"
#include "graphics/Renderer.h"
#include "graphics/Math/Vec3.h"
#include "graphics/ParticleSystem.h"

#include "core/Timer.h"
#include "core/Input.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

#ifdef DEBUG
#include "core/Debug.h"
#endif

#include "ScriptManager.h"
#include "Level.h"
#include "GameRenderer.h"
#include "GameKernel.h"
#include "Camera.h"
#include "models/BackgroundPlanet.h"
#include "models/BackgroundTexture.h"
#include "controllers/BackgroundPlanetController.h"
#include "controllers/BackgroundTextureController.h"
#include "controllers/PlayerSpaceshipController.h"
#include "controllers/AISpaceshipController.h"
#include "models/enum_types.h"
#include "models/Spaceship.h"
#include "models/Engine.h"
#include "utility/algos.h"


class GameEngine
{
private:
	static GameEngine* mInstance;
	GameEngine();
protected:
	DFXEngine::RenderDevice* mRenderDevice;
	//CEGUI::OpenGLRenderer* mGUIRenderer;
	//CEGUI::Window* mEditorGuiSheet;


	DFXEngine::TextureManager* mTextureManager;
	Level* mLevel;
    GameRenderer *mRenderer;
    GameKernel *mGameKernel;
    Camera *mCamera;
    DFXEngine::Timer *mTimer;
    DFXEngine::Input *mInput;
    //ScriptManager *mScriptManager;
    bool mRunning;
    Spaceship *PlayerShip;
    PlayerSpaceshipController *PlayerController;
public:
    static GameEngine* Instance();
    virtual ~GameEngine();
    double getGameTime()
    {
        return (double)(mTimer->currentTime()) / 1000.0f;
    }



    void initialize(int w, int h);
    void runFrame();
    bool isRunning()
    {
        return mRunning;
    }

    bool loadLevel(string filename);
    void initTestlevel();

    Spaceship *getPlayerShip() const
    {
        return PlayerShip;
    }

    void setPlayerShip(Spaceship *PlayerShip)
    {
        this->PlayerShip = PlayerShip;
    }

};


#endif /* GAMEENGINE_H_ */


