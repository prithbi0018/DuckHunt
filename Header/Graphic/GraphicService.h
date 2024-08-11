#pragma once
#include <SFML/Graphics.hpp>
namespace Graphic {
	class GraphicService {
	private:
		const int gameWindowWidth = 1920;
		const int gameWindowHeight = 1080;

		sf::Color windowColor = sf::Color::Black;

		sf::VideoMode* videoMode;
		sf::RenderWindow* gameWindow;

		sf::RenderWindow* createGameWindow();
		void setVideoMode();
		void destroy();
		const int frameRate = 60;

	public:
		GraphicService();
		~GraphicService();

		void initialize();
		void update();
		void render();

		bool isGameWindowOpen();

		sf::RenderWindow* getGameWindow();
		sf::Color getWindowColor();


	};
}