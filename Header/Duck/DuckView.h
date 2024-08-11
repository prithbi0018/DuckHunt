#pragma once
#include "../UI/UIElement/ImageView.h"
#include "../Duck/DuckAnimationConfig.h"
namespace Duck {
	class DuckController;
	class DuckView {
	private:
		const float duckWidth =  100.f;
		const float duckHeight = 100.f;
		int currentFrame = 0;
		float elapsedTime;
		UI::UIElement::ImageView* duckImage;
		int flip = 1;

		DuckController* duckController;
		bool deadAniamtionFinished = false;
		void createUIElemetns();
		void initializeImage();
		sf::String getDuckTexturePath();
		void destroy();

	public:
		DuckView();
		~DuckView();

		void initialize(DuckController* controller);
		void update();
		void render();

		void updateAnimation(DuckAnimationConfig animationConfig);
		void showDeadAnimation(DuckAnimationConfig animationConfig);
		const sf::Sprite& getDuckSprite();
		void setRotation(float angle);
		void setScale(int flip);

	};
}