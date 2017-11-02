#pragma once

#ifndef __Player__
#define __Player__
#include "SDLGameObject.h"

class Player : public SDLGameObject //inherit from SDLGameObject
{
	void handleInput();
	
	//variable to get mouse pointer position
	Vector2D* target;
public:
	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};

#endif //defined(__Player__)