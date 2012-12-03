/*
 * GameEngine.cpp
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#include "GameEngine.h"

GameEngine* GameEngine::mInstance = 0;

GameEngine* GameEngine::Instance()
{
	if (!mInstance)
		mInstance = new GameEngine();
	return mInstance;
}

GameEngine::GameEngine()
{
	// TODO Auto-generated constructor stub

}

GameEngine::~GameEngine()
{
	delete mRenderDevice;
	delete mLevel;
	delete mRenderer;
	//delete mGUIRenderer;
	//delete mScriptManager;
}

/**
 * Initializes the engine
 * @param w screen resolution width
 * @param h screen resolution height
 */
void GameEngine::initialize(int w, int h)
{
	srand(time(NULL));

	//mScriptManager = new ScriptManager(this);

	mRenderDevice = new DFXEngine::SDLOpenGLRenderDevice();
	mRenderDevice->initialize(w, h);

	mRenderer = GameRenderer::Instance();
	mRenderer->setRenderDevice(mRenderDevice);

	mTextureManager = &(mRenderDevice->getTextureManager());

	mGameKernel = GameKernel::Instance();
	mCamera = Camera::Instance();
	mInput = DFXEngine::Input::Instance();
	mTimer = new DFXEngine::Timer();
	mLevel = Level::Instance();
	mRunning = true;


	/*
	mGUIRenderer = new CEGUI::OpenGLRenderer(0, w, h);
	new CEGUI::System(mGUIRenderer);
	SDL_ShowCursor(SDL_DISABLE);
	SDL_EnableUNICODE(1);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);


	CEGUI::SchemeManager::getSingleton().loadScheme( "TaharezLook.scheme" );
	CEGUI::System::getSingleton().setDefaultFont( "Commonwealth-10" );


	CEGUI::System::getSingleton().setDefaultMouseCursor( "TaharezLook", "MouseArrow" );

	mEditorGuiSheet= CEGUI::WindowManager::getSingleton().createWindow((CEGUI::utf8*)"DefaultWindow", (CEGUI::utf8*)"Sheet");

	CEGUI::System::getSingleton().setGUISheet(mEditorGuiSheet);


	CEGUI::PushButton* quitButton = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/Button", (CEGUI::utf8*)"Quit");
	mEditorGuiSheet->addChildWindow(quitButton);
	//quitButton->setXPosition(CEGUI::UDim(1,1));
	//quitButton->setYPosition(CEGUI::UDim(1,1));
	//quitButton->setSize(CEGUI::UVector2(CEGUI::UDim(1,10), CEGUI::UDim(1,10)));
	//quitButton->setPosition(CEGUI::UVector2(cegui_reldim(0.15f), cegui_reldim( 0.15f)) );
	quitButton->setSize(CEGUI::UVector2(cegui_reldim(0.15f), cegui_reldim( 0.05f)) );


	quitButton->setText("Quit");
	*/

}

void GameEngine::initTestlevel()
{
	// load resources
	mTextureManager->loadFromFile("planets/jupiter", "data/jupiter.png");
	mTextureManager->loadFromFile("backgrounds/default", "data/background.png");
	mTextureManager->loadFromFile("ships/playership", "data/ship.png");
	mTextureManager->loadFromFile("asteroid", "data/asteroid.png");
	mTextureManager->loadFromFile("particle", "data/particle.png");

	// add background objects
	BackgroundPlanet* planet = new BackgroundPlanet();
	BackgroundPlanetController* bgplanetcon = new BackgroundPlanetController(planet);
	planet->setTexture(mTextureManager->get("planets/jupiter"));
	planet->setPosition(Vec3(10000, 0, 60000));
	planet->setOrientation(Vec3(-90, 0, 0));
	planet->setAngular_velocity(Vec3(0, 0, 1)); // deg per second
	planet->setRadius(15000);
	planet->setSphere_slices(100);
	planet->setController(bgplanetcon);
	GameKernel::Instance()->addController(bgplanetcon);
	Level::Instance()->addBackgroundObject(planet);

	BackgroundTexture* texture = new BackgroundTexture();
	BackgroundTextureController* cont = new BackgroundTextureController(texture);
	texture->setController(cont);
	texture->setFixed_to_camera(true);
	texture->setPosition(Vec3(0, 0, 120000));
	texture->setTexture(mTextureManager->get("backgrounds/default"));
	texture->setTexture_scale(65);
	GameKernel::Instance()->addController(cont);
	Level::Instance()->addBackgroundObject(texture);

	PlayerShip = new Spaceship();
	PlayerController = new PlayerSpaceshipController();
	PlayerController->setSpaceship(PlayerShip);
	PlayerShip->setTexture(mTextureManager->get("ships/playership"));
	PlayerShip->setController(PlayerController);
	PlayerShip->setMax_acceleration(500);
	PlayerShip->setMax_velocity(400);
	PlayerShip->setMax_angular_velocity(360); // max 180 deg per second
	PlayerShip->setMax_angular_acceleration(300);
	GameKernel::Instance()->addController(PlayerController);
	Level::Instance()->addGameObject(PlayerShip);

	Engine* engine;
	DFXEngine::ParticleSystem* ps;

	engine = new Engine(Vec3(0, 15, 0), 0);
	engine->setAngle(0);
	ps = new DFXEngine::ParticleSystem();
	ps->initialize(mTextureManager->get("particle"), 30, engine->getPosition(), Vec3(0, -0.2, 0), Vec3(0,0,0), 0.8, 0.8, 0.8,  4, 20, Vec3(0,0,0), Vec3(2, 2,0));
	ps->resume();
	engine->addParticleSystem(ps);

	ps = new DFXEngine::ParticleSystem();
	ps->initialize(mTextureManager->get("particle"), 30, engine->getPosition(), Vec3(0, -0.2, 0), Vec3(0,0,0), 0, 0.5, 1,     4, 20, Vec3(0,0,0), Vec3(2, 2,0));
	ps->resume();
	engine->addParticleSystem(ps);

	ps = new DFXEngine::ParticleSystem();
	ps->initialize(mTextureManager->get("particle"), 30, engine->getPosition(), Vec3(0, -0.2, 0), Vec3(0,0,0), 0, 0, 1,       4, 20, Vec3(0,0,0), Vec3(2, 2,0));
	ps->resume();
	engine->addParticleSystem(ps);

	PlayerShip->addEngine(engine);



	for (int i = 0; i < 3 ; i++)
	{
		Spaceship* enemy = new Spaceship();
		SpaceshipController* enemy_controller = new AISpaceshipController();
		enemy_controller->setSpaceship(enemy);
		enemy->setTexture(mTextureManager->get("ships/playership"));
		enemy->setMax_acceleration(algorithms::uniform_rand(650, 700));
		enemy->setMax_velocity(algorithms::uniform_rand(500, 600));
		enemy->setController(enemy_controller);
		enemy->setPosition(Vec3(algorithms::uniform_rand(-100, 100), algorithms::uniform_rand(-100, 100), 0));
		enemy->setMax_angular_velocity(580);
		GameKernel::Instance()->addController(enemy_controller);
		Level::Instance()->addGameObject(enemy);


		engine = new Engine(Vec3(0, 15, 0), 0);
		ps = new DFXEngine::ParticleSystem();
		ps->initialize(mTextureManager->get("particle"), 30, engine->getPosition(), Vec3(0, -0.2, 0), Vec3(0,0,0), 0.2, 0.2, 0.2,  4, 20, Vec3(0,0,0), Vec3(2, 2,0));
		ps->resume();
		engine->addParticleSystem(ps);

		ps = new DFXEngine::ParticleSystem();
		ps->initialize(mTextureManager->get("particle"), 30, engine->getPosition(), Vec3(0, -0.2, 0), Vec3(0,0,0), 1, 0.2, 0,     4, 20, Vec3(0,0,0), Vec3(2, 2,0));
		ps->resume();
		engine->addParticleSystem(ps);

		ps = new DFXEngine::ParticleSystem();
		ps->initialize(mTextureManager->get("particle"), 30, engine->getPosition(), Vec3(0, -0.2, 0), Vec3(0,0,0), 1, 0, 0,       4, 20, Vec3(0,0,0), Vec3(2, 2,0));
		ps->resume();
		engine->addParticleSystem(ps);

		enemy->addEngine(engine);
	}

	for (int i = 0; i < 1000; i++)
	{
		BackgroundTexture* texture = new BackgroundTexture();
		BackgroundTextureController* contr = new BackgroundTextureController(texture);
		texture->setController(contr);
		texture->setFixed_to_camera(false);
		texture->setPosition(Vec3(algorithms::uniform_rand(-5000, 5000), algorithms::uniform_rand(-5000, 5000), algorithms::uniform_rand(100, 500)));
		texture->setTexture(mTextureManager->get("asteroid"));
		texture->setVelocity(Vec3(algorithms::uniform_rand(-20, 20), algorithms::uniform_rand(-20, 20), 0));
		texture->setAngular_velocity(Vec3(0,0,algorithms::uniform_rand(-20, 20)));
		texture->setTexture_scale(1);
		GameKernel::Instance()->addController(contr);
		Level::Instance()->addBackgroundObject(texture);
	}

	Camera::Instance()->setCameraNormalDistance(768);
}



void GameEngine::runFrame()
{
	mTimer->startLoop();

	// Handle input
	DFXEngine::Input::Instance()->handleEvents();

	if (DFXEngine::Input::Instance()->isKeyDown(SDLK_ESCAPE))
	{
		mRunning = false;
		return;
	}

	// Update
	double game_time = getGameTime();
	mGameKernel->update(game_time);

	// Render
	Camera::Instance()->moveCamera(PlayerShip->getPosition());
	mRenderer->beginRender();
	mRenderer->renderLevel(*mLevel);
	// render UI etc
	//CEGUI::System::getSingleton().renderGUI();


	mRenderer->finishRender();

	//mTimer->limitFPS(10);
	mTimer->endLoop();
}




