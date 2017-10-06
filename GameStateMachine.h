#pragma once

#ifndef __GameStateMachine__
#define __GameStateMachine_

#include "GameState.h"
#include <vector>

class GameStateMachine
{
	std::vector <GameState*> m_gameStates;
public:

	//add a state without removing previous state
	void pushState(GameState* pState);

	//add a state after removing previous state
	void changeState(GameState* pState);

	//remove present state without adding another state
	void popState();
};

#endif //defined!(__GameStateMachine__)