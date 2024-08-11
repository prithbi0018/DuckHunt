#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI {
	using namespace Main;
	using namespace Interface;
	void UIService::createUIControllers()
	{
		splashScreenUIController = new SplashScreenUI::SplashScreenUIController();
		mainMenuUIController = new MainMenu::MainMenuUIController();
		gameplayUIController = new GameplayUI::GameplayUIController();
	}
	void UIService::initializeControllers()
	{
		splashScreenUIController->initialize();
		mainMenuUIController->initialize();
		gameplayUIController->initialize();
	}
	void UIService::destroy()
	{
		delete(splashScreenUIController);
		delete(mainMenuUIController);
		delete(gameplayUIController);
	}
	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState()) {
		case GameState::SPLASH_SCREEN:
			return splashScreenUIController;
		case GameState::MAIN_MENU:
			return mainMenuUIController;
		case GameState::GAMEPLAY:
			return gameplayUIController;
		}
	}
	UIService::UIService()
	{
		createUIControllers();
	}
	UIService::~UIService()
	{
		destroy();
	}
	void UIService::initialize()
	{
		UIElement::TextView::initializeTextView();
		initializeControllers();
	}
	void UIService::update()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->update();
	}
	void UIService::render()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->render();
	}
	void UIService::showUI()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->show();
	}
}