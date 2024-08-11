#include "../../../Header/UI/UIElement/ButtonView.h"
#include "../../../Header/Event/EventService.h"
#include "../../../Header/Global/ServiceLocator.h"

namespace UI {
	namespace UIElement {
		using namespace Event;
		void ButtonView::printButtonClicked()
		{
			printf("Clicked%s\n", buttonTitle.toAnsiString().c_str());
		}
		void ButtonView::handleButtonInteraction()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*UIView::gameWindow));
			if (clickedButton(&sprite, mousePosition)) {
				if (callbackFunction) callbackFunction();
			}

		}
		bool ButtonView::clickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition)
		{
			EventService* eventService = Global::ServiceLocator::getInstance()->getEventService();
			return eventService->pressedLeftMouseButton() && sprite.getGlobalBounds().contains(UIView::gameWindow->mapPixelToCoords(static_cast<sf::Vector2i> (mousePosition)));

		}
		ButtonView::ButtonView()
		{
		}
		ButtonView::~ButtonView()
		{
		}
		void ButtonView::initialize(sf::String title, sf::String texturePath, float buttonWidth, float buttonHeight, sf::Vector2f position)
		{
			ImageView::initialize(texturePath, buttonWidth, buttonHeight, position);
			buttonTitle = title;
		}
		void ButtonView::update()
		{
			ImageView::update();
			if (uiState == UIState::VISIBLE) {
				handleButtonInteraction();
			}
		}
		void ButtonView::render()
		{
			ImageView::render();
		}
		void ButtonView::registerCallbackFuntion(CallbackFunction buttonCallback)
		{
			callbackFunction = buttonCallback;
		}
	}
}