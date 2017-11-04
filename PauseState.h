#pragma once

#ifndef __PAUSESTATE__
#define __PAUSESTATE__

#include "GameState.h"
#include <vector>

class GameObject;

class PauseState : public GameState
{
	static void s_pauseToMain();
	static void s_resumePlay();

	static const std::string s_pauseID;

	std::vector <GameObject*> m_gameObjects;

public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; }
};

#endif //defined!(__PAUSESTATE__)