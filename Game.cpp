#include <iostream>
#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{	
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{	
		std::cout << "SDL init success\n";
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0)	//window init success
		{
			std::cout << "Window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) //renderer init success
			{
				std::cout << "renderer init success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init failed\n";
				return false;	//renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false;	//window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;	//SDL init fail
	}
	std::cout << "init success\n";

	//Loading BMP image on the screen
	SDL_Surface *pTempSurface = SDL_LoadBMP("assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	//Getting the dimensions of the texture
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	//adding new dimensions to the source rectangle
	m_sourceRectangle.w = 50;
	m_sourceRectangle.h = 50;

	//Source and Destination rectangle have same dimensions
	m_destinatinRectangle.w = m_sourceRectangle.w;
	m_destinatinRectangle.h = m_sourceRectangle.h;
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;
	
	//Modifying the x and y co-ordinates of destination rectangle
	m_destinatinRectangle.x = 100;
	m_destinatinRectangle.y = 100;

	m_bRunning = true;	//everything inited successfully, start the main loop
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear the renderer to the draw color

	//Code to draw the Texture
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinatinRectangle);
	
	SDL_RenderPresent(m_pRenderer);	//draw to the screen
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default: break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}