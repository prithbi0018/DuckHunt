#pragma once
#include "../../Header/Event/EventService.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Gameplay/GameplayService.h"	
#include "../../Header/Time/TimeService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Duck/DuckService.h"
namespace Global {
	using namespace Graphic;
	using namespace Event;
	using namespace Player;
	using namespace Gameplay;
	using namespace Duck;
	using namespace Time;
	using namespace Sound;
	using namespace UI;
	class ServiceLocator {
	private:
		GraphicService* graphicServie;
		EventService* eventService;
		GameplayService* gameplayService;
		DuckService* duckService;
		PlayerService* playerService;
		TimeService* timeService;
		SoundService* soundService;
		UIService* uiService;
		
		ServiceLocator();
		~ServiceLocator();

		void createServices();
		void clearServices();
	public:
		
		static ServiceLocator* getInstance();

		void initialize();
		void update();
		void render();

		void reset();

		GraphicService* getGraphicService();
		EventService* getEventService();
		GameplayService* getGameplayService();
		DuckService* getDuckService();
		PlayerService* getPlayerService();
		TimeService* getTimeService();
		SoundService* getSoundService();
		UIService* getUIService();
	};
}