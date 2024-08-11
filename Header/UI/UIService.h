#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/SplashScreenUI/SplashScreenUIController.h"
#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/UI/Gameplay/GameplayUIController.h"
namespace UI {
	
	class UIService {
	private:
		SplashScreenUI::SplashScreenUIController* splashScreenUIController;
		MainMenu::MainMenuUIController* mainMenuUIController;
		GameplayUI::GameplayUIController* gameplayUIController;
		void createUIControllers();
		void initializeControllers();
		void destroy();
		Interface::IUIController* getCurrentUIController();
	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showUI();
		
	};
}