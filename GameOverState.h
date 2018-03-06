#pragma once

#ifndef __GameOverState__
#define __GameOverState__

#include "GameState.h"
#include <string>
#include <vector>

class GameObject;

class GameOverState : public GameState
{
	static void s_gameOverToMain();
	static void s_restartPlay();

	static const std::string s_gameOverID;

	std::vector<GameObject*> m_gameObjects;
public:
	GameOverState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; }
};

#endif //defined!(__GameOverState__)