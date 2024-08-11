#include "../../Header/Gameplay/GameplayService.h"

namespace Gameplay {
    GameplayService::GameplayService()
    {
        gameplayController = new GameplayController();
    }
    GameplayService::~GameplayService()
    {
        delete gameplayController;
    }
    void GameplayService::initialize()
    {
        gameplayController->initialize();
    }
    void GameplayService::update()
    {
        gameplayController->update();
    }
    void GameplayService::render()
    {
        gameplayController->render();
    }
    void GameplayService::increaseWave()
    {
        gameplayController->increaseWave();
    }
    void GameplayService::resetWave()
    {
        gameplayController->resetWave();
    }
    int GameplayService::getNoOfDucksToSpawn()
    {
        return getGameplayModel()->getNoOfDucksToSpawn();
    }
    
    void GameplayService::reset()
    {
        gameplayController->reset();
    }
    GameplayModel* GameplayService::getGameplayModel()
    {
        return gameplayController->getGameplayModel();
    }
  
}