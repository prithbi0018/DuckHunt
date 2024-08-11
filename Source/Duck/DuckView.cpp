#include "../../Header/Duck/DuckView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Duck/DuckController.h"
#include "../../Header/Duck/DuckAnimationConfigData.h"
#include "../../Header/Global/Config.h"

namespace Duck {
	using namespace Global;
	void DuckView::createUIElemetns()
	{
		duckImage = new UI::UIElement::ImageView();
	}
	void DuckView::initializeImage()
	{
		duckImage->initialize(getDuckTexturePath(), 0, 0, duckController->getDuckPosition());
		duckImage->setTextureRect(sf::IntRect(0,0, duckAnimationConfig.tileWidth, duckAnimationConfig.tileHeight));
		switch (duckController->getMovementDirection())
		{
		case MovementDirection::LeftUp:
			duckImage->setRotation(-25);
			setScale(-1);
			break;
		case MovementDirection::RightUp:
			duckImage->setRotation(25);
			setScale(1);
			break;
		default:
			duckImage->setRotation(-25);
			setScale(-1);
			break;
		}
		
	}
	sf::String DuckView::getDuckTexturePath()
	{
		switch (duckController->getDuckType()) {
		case DuckType::GreenDuck:
			return Config::greenDuckTexturePath;
			break;
		case DuckType::BlueDuck:
			return Config::blueDuckTexturePath;
			break;
		default:
			return Config::greenDuckTexturePath;
			break;
		}
	}
	void DuckView::destroy()
	{
		delete duckImage;
	}
	DuckView::DuckView()
	{
		createUIElemetns();
	}
	DuckView::~DuckView()
	{
		destroy();
	}
	void DuckView::initialize(DuckController* controller)
	{
		duckController = controller;
		currentFrame = 0;
		initializeImage();
	}
	void DuckView::update()
	{
		elapsedTime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		duckImage->setPosition(duckController->getDuckPosition());
		if (duckController->getDuckState() == DuckState::Alive) {
			
			updateAnimation(duckAnimationConfig);
		}
		else {

			duckImage->setRotation(0);
			if (!deadAniamtionFinished) {
				showDeadAnimation(duckdeadAnimationConfig);
			}
			else {
				updateAnimation(duckRotatingAnimationConfig);
			}

		}
		
		
	}
	void DuckView::render()
	{
		duckImage->render();
	}
	void DuckView::updateAnimation(DuckAnimationConfig animationConfig)
	{
		if (elapsedTime >= animationConfig.frameDuration) {
			if (currentFrame + 1 >= animationConfig.numberOfAnimationFrame) {
				currentFrame = 0;
			}
			else {
				currentFrame = (currentFrame + 1) % animationConfig.numberOfAnimationFrame;
			}
			duckImage->setTextureRect(sf::IntRect(
				animationConfig.tileStart + (currentFrame * animationConfig.tileWidth),
				0,
				animationConfig.tileWidth,
				animationConfig.tileHeight
			));
			elapsedTime = 0.f;
			duckImage->update();
		}
	}
	void DuckView::showDeadAnimation(DuckAnimationConfig animationConfig)
	{
		duckImage->setTextureRect(sf::IntRect(
			animationConfig.tileStart ,
			0,
			animationConfig.tileWidth,
			animationConfig.tileHeight
		));
		
		if (elapsedTime >= animationConfig.frameDuration) {
		
			currentFrame = 0;
			elapsedTime = 0.f;
			deadAniamtionFinished = true;
		}
		duckImage->update();
	}
	const sf::Sprite& DuckView::getDuckSprite()
	{
		return duckImage->getSprite();
	}
	void DuckView::setRotation(float angle)
	{
		duckImage->setRotation(angle);
	}
	void DuckView::setScale(int flip)
	{
		duckImage->setScale(duckWidth, duckHeight, flip * duckAnimationConfig.tileWidth, duckAnimationConfig.tileHeight);
	}
}