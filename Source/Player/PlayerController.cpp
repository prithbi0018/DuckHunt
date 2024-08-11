#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"

#include "../../Header/Global/ServiceLocator.h"
namespace Player {
	using namespace Global;
	void PlayerController::create()
	{
		playerModel = new PlayerModel();
		//playerView = new PlayerView();
	}
	void PlayerController::destroy()
	{
		delete playerModel;
		//delete playerView;
	}
	void PlayerController::processPlayerInput()
	{
		Event::EventService* eventService = Global::ServiceLocator::getInstance()->getEventService();
		if (eventService->pressedLeftMouseButton()) {
			checkIfDuckUnderCursor();
			reduceAmmo();
			if (playerModel->getCurrentAmmoPerRound() <= 0 && playerModel->getRadiusAmmoPerRound() <= 0
				&& Global::ServiceLocator::getInstance()->getDuckService()->getNoOfDucksRemaning() >0) {
				Global::ServiceLocator::getInstance()->getGameplayService()->resetWave();
				reduceHealth();
				restAmmoPerRound();
			}
		}

		if (eventService->pressedOneKey()) {
			if (playerModel->getCurrentAmmoPerRound() > 0) {
				setBulletType(BulletType::Point);
			}
		}
		else if (eventService->pressedTwoKey()) {
			if (playerModel->getRadiusAmmoPerRound() > 0) {
				setBulletType(BulletType::Area);
			}
		}
	}

	void PlayerController::reduceAmmo()
	{
		switch (bulletType)
		{
		case Player::BulletType::Point:
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BULLET_FIRE);
			playerModel->setCurrentAmmoPerRound(playerModel->getCurrentAmmoPerRound() - 1);
			if (playerModel->getCurrentAmmoPerRound() <= 0) {
				setBulletType(BulletType::Area);
			}
			break;
		case Player::BulletType::Area:
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::RADIUS_BUllET_FIRE);
			playerModel->setRadiusAmmoPerRound(playerModel->getRadiusAmmoPerRound() - 1);
			if (playerModel->getRadiusAmmoPerRound() <= 0) {
				setBulletType(BulletType::Point);
			}
			break;
		default:
			break;
		}
		
		
	}

	void PlayerController::checkIfDuckUnderCursor()
	{
		sf::RenderWindow* gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));
		switch (bulletType)
		{
		case Player::BulletType::Point:
			Global::ServiceLocator::getInstance()->getDuckService()->checkIsDuckColliding(sf::FloatRect(static_cast<sf::Vector2f>(gameWindow->mapPixelToCoords(static_cast<sf::Vector2i>(mousePosition))),sf::Vector2f(2.f,2.f)));
			break;
		case Player::BulletType::Area:
			Global::ServiceLocator::getInstance()->getDuckService()->checkIsDuckColliding(sf::FloatRect(static_cast<sf::Vector2f>(gameWindow->mapPixelToCoords(static_cast<sf::Vector2i>(mousePosition))), sf::Vector2f(300.f, 300.f)));
			break;
		default:
			break;
		}
	}

	void  PlayerController::reduceHealth() {
		playerModel->setHealth(playerModel->getHealth() - 1);
		if (playerModel->getHealth() <= 0) {
			Global::ServiceLocator::getInstance()->reset();
		}
	}
	void PlayerController::restAmmoPerRound()
	{
		setBulletType(BulletType::Point);
		playerModel->resetAmmoPerRound();
	}
	PlayerController::PlayerController()
	{
		create();
	}
	PlayerController::~PlayerController()
	{
		destroy();
	}
	void PlayerController::initialize()
	{
		playerModel->initialize();

	}
	void PlayerController::update()
	{
		processPlayerInput();
	}
	void PlayerController::render()
	{
	
	}
	void PlayerController::reset()
	{
		playerModel->reset();
	}
	int PlayerController::getHealth()
	{
		return playerModel->getHealth();
	}
	int PlayerController::getAmmoPerRound()
	{
		return playerModel->getCurrentAmmoPerRound();
	}
	int PlayerController::getRadiusAmmoPerRound()
	{
		return playerModel->getRadiusAmmoPerRound();
	}
	int PlayerController::getScore()
	{
		return playerModel->getScore();;
	}
	void PlayerController::increaseScore(int increaseAmount)
	{
		playerModel->setScore(getScore() + increaseAmount);
	}

	void PlayerController::increaseAmmo()
	{
		playerModel->setAmmoPerRound(Global::ServiceLocator::getInstance()->getGameplayService()->getNoOfDucksToSpawn());
	}

	BulletType PlayerController::getBulletType()
	{
		return bulletType;
	}

	void PlayerController::setBulletType(BulletType type)
	{
		bulletType = type;
	}
}