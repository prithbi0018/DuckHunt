#include "../../Header/Graphic/GraphicService.h"

namespace Graphic {
	sf::RenderWindow* GraphicService::createGameWindow()
	{
		setVideoMode();
		return new sf::RenderWindow(*videoMode, "Dunk Hunt", sf::Style::Default);
	}
	void GraphicService::setVideoMode()
	{
		videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}
	void GraphicService::destroy()
	{
		delete(gameWindow);
		delete(videoMode);
	}
	GraphicService::GraphicService()
	{
		gameWindow = nullptr;
		videoMode = nullptr;
	}
	GraphicService::~GraphicService()
	{
		destroy();
	}
	void GraphicService::initialize()
	{
		gameWindow = createGameWindow();
		gameWindow->setFramerateLimit(frameRate);
	}
	void GraphicService::update()
	{
	}
	void GraphicService::render()
	{
		
	}
	bool GraphicService::isGameWindowOpen()
	{
		return gameWindow->isOpen();
	}
	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return gameWindow;
	}
	sf::Color GraphicService::getWindowColor()
	{
		return windowColor;
	}
}