#pragma once

#ifndef __Game__
#define __Game__

#include "SDL.h"

class Game
{	
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;
	bool m_bRunning;

public:

	Game() { m_bRunning = false; }
	~Game(){}
	
	bool init(const char *title, int xpos, int ypos, int height, int width, bool fullscreen);

	void render();
	//void update();
	void handleEvents();
	void clean();

	bool running()
	{
		return m_bRunning;
	}
};

#endif /* defined(__Game__)*/
