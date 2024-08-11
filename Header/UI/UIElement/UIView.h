#pragma once
#include <SFML/Graphics.hpp>

namespace UI {
	namespace UIElement {
		enum class UIState
		{
			VISIBLE,
			HIDDEN
		};

		class UIView {
		protected:
			sf::RenderWindow* gameWindow;
			UIState uiState = UIState::HIDDEN;

		public:
			UIView();
			virtual ~UIView();

			virtual void initialize();
			virtual void update();
			virtual void render();

			virtual void show();
			virtual void hide();
		};
	}
}