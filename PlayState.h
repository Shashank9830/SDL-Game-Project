#pragma once

#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"
#include <string>

class PlayState : public GameState
{
	static const std::string s_playID;

public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }
};

#endif //defined!(__PlayState__)