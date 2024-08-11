#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
namespace Global {
	using namespace Main;
	using namespace Event;
	using namespace Graphic;
	
	ServiceLocator::ServiceLocator()
	{
		createServices();
	}
	ServiceLocator::~ServiceLocator()
	{
		clearServices();
	}
	void ServiceLocator::createServices()
	{
		graphicServie = new GraphicService();
		eventService = new EventService();
		duckService = new DuckService();
		gameplayService = new GameplayService();
		playerService = new PlayerService();
		timeService = new TimeService();
		soundService = new SoundService();
		uiService = new UIService();
	}
	void ServiceLocator::clearServices()
	{
		delete graphicServie;
		delete eventService;
		delete gameplayService;
		delete duckService;
		delete playerService;
		delete timeService;
		delete soundService;
		delete uiService;
	}
	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator serviceLocator;
		return &serviceLocator;
	}
	void ServiceLocator::initialize()
	{
		
		graphicServie->initialize();
		eventService->initialize();
		duckService->initialize();
		gameplayService->initialize();
		playerService->initialize();
		timeService->initialize();
		soundService->initialize();
		uiService->initialize();
		
	}
	void ServiceLocator::update()
	{
		
		graphicServie->update();
		eventService->update();
		switch (GameService::getGameState())
		{
		case GameState::GAMEPLAY:
			gameplayService->update();
			duckService->update();
			playerService->update();
		default:
			break;
		}
		timeService->update();
		uiService->update();
	}
	void ServiceLocator::render()
	{
		graphicServie->render();
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			break;
		case GameState::MAIN_MENU:

		case GameState::GAMEPLAY:
			gameplayService->render();
			duckService->render();
		default:
			break;
		}
		uiService->render();
	}
	void ServiceLocator::reset()
	{
		duckService->reset();
		playerService->reset();
		gameplayService->reset();
		
		
	}
	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphicServie;
	}
	EventService* ServiceLocator::getEventService()
	{
		return eventService;
	}
	GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplayService;
	}
	DuckService* ServiceLocator::getDuckService()
	{
		return duckService;
	}
	PlayerService* ServiceLocator::getPlayerService()
	{
		return playerService;
	}
	TimeService* ServiceLocator::getTimeService()
	{
		return timeService;
	}
	SoundService* ServiceLocator::getSoundService()
	{
		return soundService;
	}
	UIService* ServiceLocator::getUIService()
	{
		return uiService;
	}
}