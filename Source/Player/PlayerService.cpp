#include "../../Header/Player/PlayerService.h"

namespace Player {
	void PlayerService::createController()
	{
		playerController = new PlayerController();
	}
	void PlayerService::initializeController()
	{
		playerController->initialize();
	}
	void PlayerService::destroy()
	{
		delete playerController;
	}
	PlayerService::PlayerService()
	{
		createController();
	}
	PlayerService::~PlayerService()
	{
		destroy();
	}
	void PlayerService::initialize()
	{
		initializeController();
	}
	void PlayerService::update()
	{
		playerController->update();
	}
	void PlayerService::render()
	{
		playerController->render();
	}
	void PlayerService::reset()
	{
		playerController->reset();
	}
	int PlayerService::getHealth()
	{
		return playerController->getHealth();
	}
	int PlayerService::getAmmoPerRound()
	{
		return playerController->getAmmoPerRound();
	}
	int PlayerService::getRadiusAmmoPerRound()
	{
		return playerController->getRadiusAmmoPerRound();
	}
	int PlayerService::getScore()
	{
		return playerController->getScore();;
	}
	void PlayerService::reduceHealth()
	{
		playerController->reduceHealth();
	}
	void PlayerService::increaseScore(int amount)
	{
		playerController->increaseScore(amount);
	}
	void PlayerService::increaseAmmo()
	{
		playerController->increaseAmmo();
	}
	void PlayerService::restAmmoPerRound()
	{
		playerController->restAmmoPerRound();
	
	}
}