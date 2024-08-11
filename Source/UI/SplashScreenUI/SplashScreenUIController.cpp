#include "../../Header/UI/SplashScreenUI/SplashScreenUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace UI {
	namespace SplashScreenUI {
		void SplashScreenUIController::initializeBackgroundImage()
		{
			sf::RenderWindow* gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		}
		void SplashScreenUIController::initializeOutscalLogo()
		{
			outscaleLogoView->initialize(Global::Config::duckHuntLogoTexturePath, logoWidth, logoHeight, getLogoPosition());
		}
		void SplashScreenUIController::fadeInAnimationCallback()
		{
			outscaleLogoView->playAnimation(UI::UIElement::AnimationType::FADE_OUT, logoAnimationDuration, std::bind(&SplashScreenUIController::fadeOutAnimationCallback, this));
		}
		void SplashScreenUIController::fadeOutAnimationCallback()
		{
			Global::ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
			Main::GameService::setGameState(Main::GameState::MAIN_MENU);
		}


		sf::Vector2f SplashScreenUIController::getLogoPosition()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			float xPosition = (game_window->getSize().x - logoWidth) / 2.0f;
			float yPosition = (game_window->getSize().y - logoHeight) / 2.0f;

			return sf::Vector2f(xPosition, yPosition);
		}
		SplashScreenUIController::SplashScreenUIController()
		{
			outscaleLogoView = new UIElement::AnimatedImageView();
		}
		SplashScreenUIController::~SplashScreenUIController()
		{
			delete(outscaleLogoView);
		}
		void SplashScreenUIController::initialize()
		{
			initializeBackgroundImage();
			initializeOutscalLogo();
		}
		void SplashScreenUIController::update()
		{
			outscaleLogoView->update();
		}
		void SplashScreenUIController::render()
		{
			outscaleLogoView->render();
		}
		void SplashScreenUIController::show()
		{
			outscaleLogoView->playAnimation(UI::UIElement::AnimationType::FADE_IN, logoAnimationDuration, std::bind(&SplashScreenUIController::fadeInAnimationCallback, this));
		}
	}
}