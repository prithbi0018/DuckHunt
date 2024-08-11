#include "../../Header/UI/UIElement/TextView.h"
#include "../../Header/Global/Config.h"

namespace UI {
	namespace UIElement {
		using namespace Global;

		sf::Font TextView::fontBubbleBobble;
		sf::Font TextView::fontDS_DIGIB;

		void TextView::loadFont()
		{
			fontBubbleBobble.loadFromFile(Config::bubbleBobbleFontPath);
			fontDS_DIGIB.loadFromFile(Config::DS_DIGIBFontPath);
		}
		void TextView::setFont(FontType fontType)
		{
			switch (fontType)
			{
			case UI::UIElement::FontType::BUBBLE_BOBBLE:
				text.setFont(fontBubbleBobble);
				break;
			case UI::UIElement::FontType::DS_DIGIB:
				text.setFont(fontDS_DIGIB);
				break;
			default:
				break;
			}
		}
		void TextView::setFontSize(int fontSize)
		{
			text.setCharacterSize(fontSize);
		}
		void TextView::setTextPosition(sf::Vector2f position)
		{
			text.setPosition(position);
		}
		void TextView::setTextColor(sf::Color color)
		{
			text.setFillColor(color);
		}
		TextView::TextView()
		{
		}
		TextView::~TextView()
		{
		}
		void TextView::initializeTextView()
		{
			loadFont();
		}
		void TextView::initialize(sf::String textValue, sf::Vector2f position, FontType fontType, int fontSize, sf::Color color)
		{
			UIView::initialize();

			setText(textValue);
			setTextPosition(position);
			setFont(fontType);
			setFontSize(fontSize);
			setTextColor(color);
		}
		void TextView::update()
		{
			UIView::update();
		}
		void TextView::render()
		{
			UIView::render();
			if (uiState == UIState::VISIBLE) {
				gameWindow->draw(text);
			}
		}
		void TextView::setText(sf::String textValue)
		{
			text.setString(textValue);
		}
		void TextView::setTextCentreAligned()
		{
			float xPosition = (gameWindow->getSize().x - text.getLocalBounds().width) / 2;
			float yPosition = text.getGlobalBounds().getPosition().y;

			text.setPosition(sf::Vector2f(xPosition, yPosition));
		}
	}
}