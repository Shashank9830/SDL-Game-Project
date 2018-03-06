#pragma once

#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"
#include <string>
#include <vector>

class GameObject;

class PlayState : public GameState
{
	static const std::string s_playID;

	std::vector< GameObject* > m_gameObjects;

public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

	//function to check collisions
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
};

#endif //defined!(__PlayState__)