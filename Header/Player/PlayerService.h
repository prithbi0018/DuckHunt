#pragma once
#include "PlayerController.h"
namespace Player {
	class PlayerService {
	private:
		PlayerController* playerController;

		void createController();
		void initializeController();
		void destroy();
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();
		void reset();

		int getHealth();
		int getAmmoPerRound();
		int getRadiusAmmoPerRound();
		int getScore();

		void reduceHealth();
		void increaseScore(int amount);
		void increaseAmmo();
		void restAmmoPerRound();

	};
}