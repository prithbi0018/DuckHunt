#pragma once
#include <SFML/Graphics.hpp>
#include "../Interface/IUIController.h"
#include "../UIElement/ButtonView.h"
#include "../UIElement/ImageView.h"
#include "../UIElement/TextView.h"
namespace UI {
	namespace MainMenu {
		class MainMenuUIController : public Interface::IUIController {
		private:

			const float buttonWidth = 400;
			const float buttonHeight = 150;

			const float playButtonYPosition = 600.f;
			const float quitButtonYPosition = 800.f;
			const float backgroundAlpha = 1.f;


			const float fontSize = 125.f;
			const sf::Vector2f duckHuntTextPosition = sf::Vector2f(725.f, 200.f);
			const sf::Color color = sf::Color::Red;

			UIElement::ImageView* backgroundImage;
			UIElement::ButtonView* playButton;
			UIElement::ButtonView* quitButton;
			UIElement::TextView* duckHuntTextView;


			void createImage();
			void createButton();
			void createText();
			void initializeBackgroundImage();

			void initializeButtons();
			void initializeText();
			void registerButtonCallback();

			void playButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}