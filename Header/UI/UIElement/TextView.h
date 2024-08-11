#pragma once
#include "../../Header/UI/UIElement/UIView.h"

namespace UI {
	namespace UIElement {
		enum class FontType
		{
			BUBBLE_BOBBLE,
			DS_DIGIB,
		};
		class TextView : public UIView
		{
		private:

			static const int defaultFontSize = 55;
			static sf::Font fontBubbleBobble;
			static sf::Font fontDS_DIGIB;

			sf::Text text;

			static void loadFont();

			void setFont(FontType fontType);
			void setFontSize(int fontSize);
			void setTextPosition(sf::Vector2f position);
			void setTextColor(sf::Color color);
		public:
			TextView();
			virtual ~TextView();

			static void initializeTextView();

			virtual void initialize(sf::String textValue, sf::Vector2f position, FontType fontType = FontType::BUBBLE_BOBBLE, int fontSize = defaultFontSize, sf::Color color = sf::Color::White);
			virtual void update() override;
			virtual void render() override;

			void setText(sf::String textValue);
			void setTextCentreAligned();

		};
	}
}