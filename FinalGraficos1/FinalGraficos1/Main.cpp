#include "Game.h"
int main()
{
	Game * game = new Game();
	game->Start();
	game->Update();
	game->Stop();
	return 0;
}