#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../../Header/UI/UIElement/ButtonView.h"
#include "../../../Header/UI/UIElement/ImageView.h"
#include "../../../Header/UI/UIElement/TextView.h"

namespace UI
{
    namespace MainMenu //nested namespace since everything in MainMenu exists inside UI
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;
        using namespace Sound;
        using namespace UIElement;

        MainMenuUIController::MainMenuUIController() {
            createImage();
            createButton();
            createText();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            destroy();
        }

        void MainMenuUIController::initialize()
        {
            initializeBackgroundImage();
            initializeButtons();
            initializeText();
            registerButtonCallback();
        }

        void MainMenuUIController::update()
        {
            backgroundImage->update();
            playButton->update();
            quitButton->update();
            duckHuntTextView->update();

        }

        void MainMenuUIController::render()

        {
            backgroundImage->render();
            playButton->render();
            quitButton->render();
            duckHuntTextView->render();
        }

        void MainMenuUIController::show()
        {
            backgroundImage->show();
            playButton->show();
            quitButton->show();
            duckHuntTextView->show();

            ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
        }




        void MainMenuUIController::createImage()
        {
            backgroundImage = new ImageView();
        }

        void MainMenuUIController::createButton()
        {
            playButton = new ButtonView();
            quitButton = new ButtonView();
        }

        void MainMenuUIController::createText()
        {
            duckHuntTextView = new TextView();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            backgroundImage->initialize(Config::mainMenuBackgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
            backgroundImage->setColor(sf::Color(255,230,255));

        }

        void MainMenuUIController::initializeButtons()
        {
            playButton->initialize("Play Button", Config::playButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, playButtonYPosition));
            quitButton->initialize("Quit Button", Config::quitButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, quitButtonYPosition));

            playButton->setCentreAlinged(false);
            quitButton->setCentreAlinged(false);

        }

        void MainMenuUIController::initializeText()
        {
            duckHuntTextView->initialize("Duck Hunt", duckHuntTextPosition, UIElement::FontType::BUBBLE_BOBBLE, fontSize,color);
        }

        void MainMenuUIController::registerButtonCallback()
        {
            playButton->registerCallbackFuntion(std::bind(&MainMenuUIController::playButtonCallback, this));
             quitButton->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
        }

        void MainMenuUIController::playButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        void MainMenuUIController::destroy()
        {

            delete(playButton);
            delete(quitButton);
            delete(backgroundImage);
            delete(duckHuntTextView);
        }



    }
}