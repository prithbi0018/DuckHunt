#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Gameplay {
	GameplayController::GameplayController()
	{
		gameplayModel = new GameplayModel();
		gameplayView = new GameplayView();
	}
	GameplayController::~GameplayController()
	{
		delete gameplayModel;
		delete gameplayView;
	}
	void GameplayController::initialize()
	{
		gameplayModel->initialize();
		gameplayView->initialize();
		
	}
	void GameplayController::update()
	{
		gameplayModel->update();
		gameplayView->update();

		
	}
	void GameplayController::render()
	{
		gameplayView->render();
	}
	void GameplayController::increaseWave()
	{
		gameplayModel->setGameplayState(GameplayState::WAVE_STARTING);
		gameplayModel->increaseWave();
		Global::ServiceLocator::getInstance()->getDuckService()->reset();
		Global::ServiceLocator::getInstance()->getPlayerService()->increaseAmmo();
		Global::ServiceLocator::getInstance()->getPlayerService()->restAmmoPerRound();
	}
	void GameplayController::resetWave()
	{
		gameplayModel->setGameplayState(GameplayState::WAVE_STARTING);
		gameplayModel->resetWave();
		Global::ServiceLocator::getInstance()->getDuckService()->reset();
	}
	void GameplayController::reset()
	{
		gameplayModel->reset();
		resetWave();
	}
	GameplayModel* GameplayController::getGameplayModel()
	{
		return gameplayModel;
	}
	
}