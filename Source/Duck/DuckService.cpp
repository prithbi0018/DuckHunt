#include "../../Header/Duck/DuckService.h"
#include "../../Header/Duck/DuckController.h"
#include "../../Header/Duck/Controllers/BlueDuckController.h"
#include "../../Header/Duck/Controllers/GreenDuckController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Duck {
	DuckController* DuckService::createDuck(DuckType duckType)
	{
		switch (duckType)
		{
		case Duck::DuckType::GreenDuck:
			return new Controllers::GreenDuckController(duckType);
			break;
		case Duck::DuckType::BlueDuck:
			return new Controllers::BlueDuckController(duckType);
			break;
		default:
			return new Controllers::GreenDuckController(duckType);
			break;
		}
	}
	DuckType DuckService::getRandomDuckType()
	{
		int randomDuckType = std::rand() % 2;
		return static_cast<DuckType>(randomDuckType);
	}
	void DuckService::destroy() {
	
		for (DuckController* duckController : duckList)
		{
			delete duckController;
			
		}
		duckList.clear();
	}

	
	void DuckService::initialize()
	{
	}
	void DuckService::update()
	{
		for (DuckController* duckController : duckList)
		{
			duckController->update();
		}
	}
	void DuckService::render()
	{
		for (DuckController* duckController : duckList)
		{
			duckController->render();
		}
	}
	void DuckService::reset()
	{
		destroy();
	}
	
	
	void DuckService::checkIsDuckColliding(sf::FloatRect bounds)
	{

		for (DuckController* duckController : duckList)
		{
			duckController->checkIfColliding(bounds);
		}
	}

	int DuckService::getNoOfDucksRemaning()
	{
		return duckList.size();
	}

	void DuckService::spawnDuck()
	{
		DuckController* duckController = createDuck(getRandomDuckType());
		duckController->initialize();
		duckList.push_back(duckController);
	}
	void DuckService::spawnNoOfDuck(int number)
	{
		for (int i = 0; i < number; i++) {
			spawnDuck();
		}
	}
	
	void DuckService::destroyDuck(DuckController* duckController)
	{
		duckList.erase(std::remove(duckList.begin(), duckList.end(), duckController), duckList.end());
		delete duckController;
		if (getNoOfDucksRemaning() <= 0 && Global::ServiceLocator::getInstance()->getPlayerService()->getHealth() > 0) {
			Global::ServiceLocator::getInstance()->getGameplayService()->increaseWave();
		}

	}
}