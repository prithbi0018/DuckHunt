#pragma once
#include <SFML\Graphics.hpp>
namespace Event {
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};
	class EventService {
	private:
		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;
		ButtonState LeftMouseButtonState = ButtonState::RELEASED;
		bool isGameWindowOpen();
		bool gameWindowClosed();
		bool hasQuitGame();
		void processEvents();
		void updateMouseButtonState(ButtonState& currentButtonState, sf::Mouse::Button button);
	public:
		EventService();
		~EventService();
		void initialize();
		void update();
		
		bool isKeyboardEvent();
		bool pressedEscapeKey();
		bool pressedLeftMouseButton();
		bool pressedOneKey();
		bool pressedTwoKey();

	};
}