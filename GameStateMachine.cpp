#include "GameStateMachine.h"

//add a game state without removing previous state
void GameStateMachine::pushState(GameState* pState)
{	
	//push the state in the vector
	m_gameStates.push_back(pState);
	//call its onEnter function
	m_gameStates.back()->onEnter();
}

//remove a game state without adding another
void GameStateMachine::popState()
{	
	//check if a state is present
	if (!m_gameStates.empty())
	{	
		//call its onExit function
		if (m_gameStates.back()->onExit())
		{	
			//remove it
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

//add a state after removing previous state
void GameStateMachine::changeState(GameState* pState)
{	
	//check if a state is present
	if (!m_gameStates.empty())
	{	
		//if it already exits don't do anything
		if (m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return;	//do nothing
		}

		//otherwise remove the previous state
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}

	//push back our new state
	m_gameStates.push_back(pState);

	//initialise it by calling its onEnter function
	m_gameStates.back()->onEnter();
}

//function to update the current state
void GameStateMachine::update()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
}

//function to render the state
void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}