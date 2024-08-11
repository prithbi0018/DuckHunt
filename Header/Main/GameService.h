#pragma once
#include "SFML/Graphics.hpp"
#include "../Global/ServiceLocator.h"
namespace Main {
	enum class GameState {
		BOOT,
		SPLASH_SCREEN,
		MAIN_MENU,
		GAMEPLAY
	};
	class GameService {
	private:
		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;
		void initialize();
		void showSplashScreen();
		void destroy();
		static GameState currentState;
	public:
		GameService();

		~GameService();
		void ignite();
		void update();
		void render();
		bool isRunning();

		static void setGameState(GameState newState);

		static GameState getGameState();
	};
}