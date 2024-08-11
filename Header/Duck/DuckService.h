#pragma once
#include <vector>
#include "DuckConfig.h"
#include <SFML/Graphics.hpp>
namespace Duck {
	class DuckController;
	class DuckService {
	private:
		std::vector<DuckController*> duckList;

		DuckController* createDuck(DuckType duckType);
		DuckType getRandomDuckType();
		void destroy();
	public:
		void initialize();
		void update();
		void render();

		void reset();
	
		void checkIsDuckColliding(sf::FloatRect bounds);
		int getNoOfDucksRemaning();
		void spawnDuck();
		void spawnNoOfDuck(int number);
		void destroyDuck(DuckController* duckController);
	};
}