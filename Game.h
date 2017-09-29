#pragma once

#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game
{	
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;

	//GameObject array
	std::vector<GameObject*> m_gameObjects;
	
	int m_currentFrame;

	bool m_bRunning;

	//constructor is now private
	Game() { m_bRunning = false; }
	~Game() {}

	//s_pInstance member variable
	static Game* s_pInstance;

public:

	//instance function to make this class a singleton
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	//function to return SDL_Renderer object
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	
	bool init(const char *title, int xpos, int ypos, int height, int width, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running()	{ return m_bRunning; }
};

typedef Game TheGame;

#endif /* defined(__Game__)*/
