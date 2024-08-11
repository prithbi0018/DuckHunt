#include "../../Header/Duck/Controllers/GreenDuckController.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckView.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Duck {
	namespace Controllers {
		
		GreenDuckController::GreenDuckController(DuckType type) : DuckController(type) 
		{
			DuckController::score = score;
			DuckController::upDownMovementSpeed = upDownMovementSpeed;
			DuckController::leftRightMovementSpeed = leftRightMovementSpeed;
		}
		GreenDuckController::~GreenDuckController()
		{
		}
		void GreenDuckController::initialize()
		{
			DuckController::initialize();
			
			
		}
		
	}
}