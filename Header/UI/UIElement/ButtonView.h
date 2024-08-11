#pragma once
#include "../../../Header/UI/UIElement/ImageView.h"
#include <functional>

namespace UI {
	namespace UIElement {
		class ButtonView : public ImageView {
		private:
			using CallbackFunction = std::function<void()>;
			CallbackFunction callbackFunction = nullptr;

			void printButtonClicked();

		protected:
			sf::String buttonTitle;
			virtual void handleButtonInteraction();
			virtual bool clickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition);

		public:
			ButtonView();
			~ButtonView();

			void initialize(sf::String title, sf::String texturePath, float buttonWidth, float buttonHeight, sf::Vector2f position);
			void update();
			void render();

			void registerCallbackFuntion(CallbackFunction buttonCallback);

		};


	}
}