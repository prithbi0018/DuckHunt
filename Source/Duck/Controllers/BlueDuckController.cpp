#include "../../Header/Duck/Controllers/BlueDuckController.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckView.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Duck {
	namespace Controllers {
		
		BlueDuckController::BlueDuckController(DuckType type) : DuckController(type)
		{
			DuckController::score = score;
			DuckController::upDownMovementSpeed = upDownMovementSpeed;
			DuckController::leftRightMovementSpeed = leftRightMovementSpeed;
		}
		BlueDuckController::~BlueDuckController()
		{

		}
		void BlueDuckController::initialize()
		{
			DuckController::initialize();
			
		}

		bool BlueDuckController::checkIfColliding(sf::FloatRect bounds)
		{
			if (DuckController::checkIfColliding(bounds)) {
				Global::ServiceLocator::getInstance()->getDuckService()->checkIsDuckColliding(sf::FloatRect(duckModel->getDuckPosition(), sf::Vector2f(150.f, 150.f)));
				return true;
			}
			return false;
		}
	}
}