#pragma once
#include "GameplayModel.h"
#include "GameplayView.h"
namespace Gameplay {
	class GameplayController {
	private:
		GameplayModel* gameplayModel;
		GameplayView* gameplayView;
		
	public:
		GameplayController();
		~GameplayController();
		void initialize();
		void update();
		void render();

		void increaseWave();
		void resetWave();

		void reset();

		GameplayModel* getGameplayModel();
	};
}