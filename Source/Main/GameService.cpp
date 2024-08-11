#include "../../Header/Main/GameService.h"

namespace Main {
	using namespace Global;
	GameState GameService::currentState = GameState::BOOT;
	void GameService::initialize()
	{
		serviceLocator->initialize();
		gameWindow = serviceLocator->getGraphicService()->getGameWindow();
		showSplashScreen();
	}
	void GameService::showSplashScreen()
	{
		setGameState(GameState::SPLASH_SCREEN);
		Global::ServiceLocator::getInstance()->getUIService()->showUI();
	}
	void GameService::destroy()
	{
		
	}
	GameService::GameService()
	{
		serviceLocator = nullptr;
		gameWindow = nullptr;
	}
	GameService::~GameService()
	{
	}
	void GameService::ignite()
	{
		serviceLocator = Global::ServiceLocator::getInstance();
		initialize();
	}
	void GameService::update()
	{
		serviceLocator->update();
	}
	void GameService::render()
	{
		gameWindow->clear(serviceLocator->getGraphicService()->getWindowColor());
		serviceLocator->render();
		gameWindow->display();
	}
	bool GameService::isRunning()
	{
		return serviceLocator->getGraphicService()->isGameWindowOpen();
	}
	void GameService::setGameState(GameState newState)
	{
		currentState = newState;
	}
	GameState GameService::getGameState()
	{
		return currentState;
	}
}