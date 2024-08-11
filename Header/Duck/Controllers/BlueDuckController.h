#pragma once
#include "../DuckController.h"
namespace Duck {
	namespace Controllers {
		class BlueDuckController : public DuckController {
		protected:
			int score = 20;
			float upDownMovementSpeed = 550.f;
			float leftRightMovementSpeed = 850.f;
		public:
			BlueDuckController(DuckType type);
			virtual ~BlueDuckController();

			void initialize();
			virtual bool checkIfColliding(sf::FloatRect bounds) override;

		};
	}
}