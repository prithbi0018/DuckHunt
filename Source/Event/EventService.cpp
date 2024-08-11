#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Event {
	bool EventService::pressedEscapeKey()
	{
		return gameEvent.key.code == sf::Keyboard::Escape;
	}
	bool EventService::pressedLeftMouseButton()
	{
		return LeftMouseButtonState == ButtonState::PRESSED;
	}
	bool EventService::pressedOneKey()
	{
		
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1);
		//return (isKeyboardEvent() && (gameEvent.key.code == sf::Keyboard::Num1 || gameEvent.key.code == sf::Keyboard::Numpad1));
	}
	bool EventService::pressedTwoKey()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2);;
	}
	bool EventService::isGameWindowOpen()
	{
		return gameWindow != nullptr;
	}
	bool EventService::gameWindowClosed()
	{
		return gameEvent.type == sf::Event::Closed;
	}
	bool EventService::hasQuitGame()
	{
		return (isKeyboardEvent() && pressedEscapeKey());
	}
	void EventService::processEvents()
	{
		if (isGameWindowOpen()){
			while (gameWindow->pollEvent(gameEvent)) {
				if (gameWindowClosed() || hasQuitGame()) {
					gameWindow->close();
				}
			}
		}
	}
	void EventService::updateMouseButtonState(ButtonState& currentButtonState, sf::Mouse::Button button)
	{
		if (sf::Mouse::isButtonPressed(button)) {
			switch (currentButtonState)
			{
			case Event::ButtonState::PRESSED:
				currentButtonState = ButtonState::HELD;
				break;
			case Event::ButtonState::HELD:
				break;
			case Event::ButtonState::RELEASED:
				currentButtonState = ButtonState::PRESSED;
				break;
			default:
				break;
			}
		}
		else {
			currentButtonState = ButtonState::RELEASED;
		}
	}
	EventService::EventService()
	{
		gameWindow = nullptr;
	}
	EventService::~EventService()
	{
	}
	void EventService::initialize()
	{
		gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	}
	void EventService::update()
	{
		processEvents();
		updateMouseButtonState(LeftMouseButtonState,sf::Mouse::Left);
	}
	bool EventService::isKeyboardEvent()
	{
		return gameEvent.type == sf::Event::KeyPressed;
	}
}