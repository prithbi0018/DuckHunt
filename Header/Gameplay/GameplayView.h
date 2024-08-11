#pragma once
#include "../UI/UIElement/ImageView.h"

namespace Gameplay {
	class GameplayView {
	private:
		UI::UIElement::ImageView* backgroundImage;

		void createUIElements();
		void initializeImage();
		void destroy();
	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();
	};
}
