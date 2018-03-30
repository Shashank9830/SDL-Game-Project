#pragma once

#ifndef __Player__
#define __Player__
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Player : public SDLGameObject //inherit from SDLGameObject
{
	void handleInput();
	
	//variable to get mouse pointer position
	Vector2D* target;
public:
	Player();
	~Player();

	void load(const LoaderParams * pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};

#endif //defined(__Player__)