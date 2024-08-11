#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Gameplay {
	void GameplayView::createUIElements()
	{
		backgroundImage = new UI::UIElement::ImageView();
	}
	void GameplayView::initializeImage()
	{
		sf::RenderWindow* gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		backgroundImage->initialize(Global::Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
	}
	void GameplayView::destroy()
	{
		delete(backgroundImage);
	}
	GameplayView::GameplayView()
	{
		createUIElements();
	}
	GameplayView::~GameplayView()
	{
		destroy();
	}
	void GameplayView::initialize()
	{
		initializeImage();
	}
	void GameplayView::update()
	{
	}
	void GameplayView::render()
	{
		backgroundImage->render();
	}
}