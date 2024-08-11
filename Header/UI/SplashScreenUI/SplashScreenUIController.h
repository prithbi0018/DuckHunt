#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/AnimatedImageView.h"
namespace UI {
	namespace SplashScreenUI {

		class SplashScreenUIController : public Interface::IUIController {
		private:
			const float logoAnimationDuration = 2.0f;
			const float logoWidth = 600.f;
			const float logoHeight = 600.f;

			UIElement::ImageView* backgroundImage;
			UIElement::AnimatedImageView* outscaleLogoView;

			void initializeBackgroundImage();

			void initializeOutscalLogo();
			void fadeInAnimationCallback();
			void fadeOutAnimationCallback();
			sf::Vector2f getLogoPosition();
		public:
			SplashScreenUIController();
			~SplashScreenUIController();
			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};

	}
}