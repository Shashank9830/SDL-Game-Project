#pragma once

#ifndef __GameObject__
#define __GameObject__
#include <iostream>
#include "SDL.h"

class GameObject
{
protected:
	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;

	int m_x;
	int m_y;

	int m_width;
	int m_height;

public:
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer *pRenderer);
	void update();
	//void clean();
};

#endif //defined (__GameObject__)
