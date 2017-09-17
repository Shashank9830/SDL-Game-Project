//Game is now divided into modules

#include "Game.h"
#include <Windows.h>
#include <iostream>

//our Game Object
Game *g_game = 0;

int main(int argc, char* argv[])
{	
	//my fix for the tip in chapter 1 to use freopen()
	FILE *stream;
	AllocConsole();
	freopen_s(&stream,"CON", "w", stdout);

	g_game = new Game();

	g_game->init("Chapter 1", 100, 100, 640, 580, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();

	//free space
	delete g_game;

	return 0;
}