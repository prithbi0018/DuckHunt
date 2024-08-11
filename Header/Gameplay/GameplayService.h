#pragma once
#include "GameplayController.h"
namespace Gameplay {
	class GameplayService {
	private:
		GameplayController* gameplayController;
	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();
		void increaseWave();
		void resetWave();
		int getNoOfDucksToSpawn();
		void reset();


		GameplayModel*  getGameplayModel();

	};
}