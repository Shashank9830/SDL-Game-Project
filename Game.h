#pragma once

#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "SDL_image.h"

class Game
{	
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;

	SDL_Texture *m_pTexture;		//the new SDL_Texture variable
	SDL_Rect m_sourceRectangle;		//the first rectangle
	SDL_Rect m_destinationRectangle;	//another rectangle

	bool m_bRunning;

public:

	Game() { m_bRunning = false; }
	~Game(){}
	
	bool init(const char *title, int xpos, int ypos, int height, int width, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running()
	{
		return m_bRunning;
	}
};

#endif /* defined(__Game__)*/
