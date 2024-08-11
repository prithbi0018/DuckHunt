#include "../../Header/Duck/DuckController.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Duck {
	void DuckController::move()
	{
		switch (duckModel->getMovementDirection())
		{
		case MovementDirection::LeftUp:
			moveUp();
			moveLeft();
			break;
		case MovementDirection::LeftDown:
			moveDown();
			moveLeft();
			break;
		case MovementDirection::RightUp:
			moveRight();
			moveUp();
			break;
		case MovementDirection::RigthDown:
			moveRight();
			moveDown();
			break;
		default:
			break;
		}
	}
	void DuckController::moveDown()
	{
		sf::Vector2f currentPosition = duckModel->getDuckPosition();
		currentPosition.y += upDownMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (currentPosition.y >= duckModel->bottomMostPosition) {
			if (duckModel->getMovementDirection() == MovementDirection::LeftDown) {
				duckView->setRotation(-25);
				duckView->setScale(-1);
				duckModel->setMovementDirection(MovementDirection::LeftUp);
			}
			else {
				duckView->setRotation(25);
				duckView->setScale(1);
				duckModel->setMovementDirection(MovementDirection::RightUp);
			}
		}
		else {
			duckModel->setDuckPosition(currentPosition);
		}

	}
	void DuckController::moveUp()
	{
		sf::Vector2f currentPosition = duckModel->getDuckPosition();
		currentPosition.y -= upDownMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (currentPosition.y <= duckModel->topMostPosition) {
			if (duckModel->getMovementDirection() == MovementDirection::LeftUp) {
				duckView->setRotation(-50);
				duckView->setScale(-1);
				duckModel->setMovementDirection(MovementDirection::LeftDown);
			}
			else {
				duckView->setRotation(50);
				duckView->setScale(1);
				duckModel->setMovementDirection(MovementDirection::RigthDown);
			}

		}
		else {
			duckModel->setDuckPosition(currentPosition);
		}
	}
	void DuckController::moveLeft()
	{
		sf::Vector2f currentPosition = duckModel->getDuckPosition();
		currentPosition.x -= leftRightMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (currentPosition.x <= duckModel->leftMostPosition) {
			if (duckModel->getMovementDirection() == MovementDirection::LeftDown) {
				duckView->setRotation(50);
				duckView->setScale(1);
				duckModel->setMovementDirection(MovementDirection::RigthDown);
			}
			else {
				duckView->setRotation(25);
				duckView->setScale(1);
				duckModel->setMovementDirection(MovementDirection::RightUp);
			}

		}
		else {
			duckModel->setDuckPosition(currentPosition);
		}
	}
	void DuckController::moveRight()
	{
		sf::Vector2f currentPosition = duckModel->getDuckPosition();
		currentPosition.x += leftRightMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (currentPosition.x >= duckModel->rightMostPosition) {
			if (duckModel->getMovementDirection() == MovementDirection::RigthDown) {
				duckView->setRotation(-50);
				duckView->setScale(-1);
				duckModel->setMovementDirection(MovementDirection::LeftDown);
			}
			else {
				duckView->setRotation(-25);
				duckView->setScale(-1);
				duckModel->setMovementDirection(MovementDirection::LeftUp);
			}

		}
		else {
			duckModel->setDuckPosition(currentPosition);
		}
	}
	void DuckController::deadMove()
	{

		sf::Vector2f currentPosition = duckModel->getDuckPosition();
		currentPosition.y += deadMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		
		duckModel->setDuckPosition(currentPosition);
	}
	sf::Vector2f DuckController::getRandomPosition()
	{
		float xPosition = duckModel->leftMostPosition + (std::rand() % static_cast<int>(duckModel->leftMostPosition - duckModel->rightMostPosition));
		float yPosition = duckModel->bottomMostPosition - (std::rand() % 50);
		return sf::Vector2f(xPosition, yPosition);
	}
	void DuckController::playDuckSound()
	{
		duckSoundElapsedTime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (duckSoundElapsedTime >= duckSoundTime) {
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DUCK_QUACK);
			duckSoundElapsedTime = 0.f;
		}
	}
	void DuckController::handleOutOfBounds()
	{
		sf::Vector2f duckPosition = getDuckPosition();
		sf::Vector2u windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (duckPosition.x < 0 || duckPosition.x > windowSize.x ||
			duckPosition.y < 0 || duckPosition.y > windowSize.y)
		{
			Global::ServiceLocator::getInstance()->getDuckService()->destroyDuck(this);
		}
	}
	void DuckController::destroy()
	{
		delete duckModel;
		delete duckView;
	}
	DuckController::DuckController(DuckType type)
	{
		duckModel = new DuckModel(type);
		duckView = new DuckView();
	}
	DuckController::~DuckController()
	{
		destroy();
	}
	void DuckController::initialize()
	{
		duckModel->setReferencePosition(getRandomPosition());
		duckModel->initialize();
		duckView->initialize(this);
	}
	void DuckController::update()
	{
		duckView->update();
		switch (duckModel->getDuckState())
		{
		case DuckState::Alive:
			move();
			playDuckSound();
			break;
		case DuckState::Dead:
			deadMove();
			handleOutOfBounds();
			break;
		default:
			break;
		}
		
		
	}
	void DuckController::render()
	{
		duckView->render();
	}
	sf::Vector2f DuckController::getDuckPosition()
	{
		return duckModel->getDuckPosition();
	}
	DuckType DuckController::getDuckType()
	{
		return duckModel->getDuckType();
	}
	MovementDirection DuckController::getMovementDirection()
	{
		return duckModel->getMovementDirection();
	}
	DuckState DuckController::getDuckState()
	{
		return duckModel->getDuckState();
	}
	bool DuckController::checkIfColliding(sf::FloatRect bounds)
	{
		if (duckModel->getDuckState() == DuckState::Alive){
			if (getDuckSprite().getGlobalBounds().intersects(bounds)) {
				duckModel->setDuckState(DuckState::Dead);
				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DuckDied);
				Global::ServiceLocator::getInstance()->getPlayerService()->increaseScore(score);;
				return true;
			}
		}
		return false;
	}
	const sf::Sprite& DuckController::getDuckSprite()
	{
		if (duckModel->getDuckState() == DuckState::Alive) {
			return duckView->getDuckSprite();
		}
		else {
			return sf::Sprite();
		}
		
	}
}