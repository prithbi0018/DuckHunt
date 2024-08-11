#include "../Header/Main/GameService.h"

int main() {
	std::unique_ptr<Main::GameService> gameService (new Main::GameService());

	gameService->ignite();
	while (gameService->isRunning())
	{
		gameService->update();
		gameService->render();
	}
}