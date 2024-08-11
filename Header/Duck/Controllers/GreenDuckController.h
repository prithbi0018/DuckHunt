#pragma once
#include "../DuckController.h"
namespace Duck {
	namespace Controllers {
		class GreenDuckController : public DuckController {
			
		protected:
			int score = 10;
			float upDownMovementSpeed = 400.f;
			float leftRightMovementSpeed = 700.f;
		public:
			GreenDuckController(DuckType type);
			virtual ~GreenDuckController();

			void initialize();
			

		};
	}
}