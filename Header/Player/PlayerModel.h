#pragma once
namespace Player {
	class PlayerModel {
	private:
		const int health = 3;
		int ammoPerRound = 3;
		const int radiusAmmoRound = 1;

		int currentHealth;
		int currentAmmoPerRound;
		int currentRadiusAmmoPerRound;
		int score =0;
	public:
		PlayerModel();
		~PlayerModel();

		void initialize();
		void reset();
		void resetAmmoPerRound();

		int getHealth();
		void setHealth(int newHealth);

		int getAmmoPerRound();
		void setAmmoPerRound(int newAmmo);

		int getCurrentAmmoPerRound();
		void setCurrentAmmoPerRound(int newAmmo);

		int getRadiusAmmoPerRound();
		void setRadiusAmmoPerRound(int newAmmo);

		int getScore();
		void setScore(int newScore);


	};
}