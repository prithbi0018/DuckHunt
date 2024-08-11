#include "../../Header/Player/PlayerModel.h"

namespace Player {
	PlayerModel::PlayerModel()
	{
	}
	PlayerModel::~PlayerModel()
	{
	}
	void PlayerModel::initialize()
	{
		reset();
	}
	void PlayerModel::reset()
	{
		currentHealth = health;
		currentAmmoPerRound = 3;
		ammoPerRound = 3;
		currentRadiusAmmoPerRound = 1;
		score = 0;
	}
	void PlayerModel::resetAmmoPerRound()
	{
		
		currentAmmoPerRound = ammoPerRound;
		currentRadiusAmmoPerRound = radiusAmmoRound;
	}
	int PlayerModel::getHealth()
	{
		return currentHealth;
	}
	void PlayerModel::setHealth(int newHealth)
	{
		currentHealth = newHealth;
	}
	int PlayerModel::getAmmoPerRound()
	{
		return ammoPerRound;
	}
	void PlayerModel::setAmmoPerRound(int newAmmo)
	{
		ammoPerRound = newAmmo;
	}
	int PlayerModel::getCurrentAmmoPerRound()
	{
		return currentAmmoPerRound;
	}
	void PlayerModel::setCurrentAmmoPerRound(int newAmmo)
	{
		currentAmmoPerRound = newAmmo;
	}
	int PlayerModel::getRadiusAmmoPerRound()
	{
		return currentRadiusAmmoPerRound;
	}
	void PlayerModel::setRadiusAmmoPerRound(int newAmmo)
	{
		currentRadiusAmmoPerRound = newAmmo;
	}
	int PlayerModel::getScore()
	{
		return score;
	}
	void PlayerModel::setScore(int newScore)
	{
		score = newScore;
	}
}