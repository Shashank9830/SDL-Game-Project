#include "InputHandler.h"
#include <iostream>
#include "Game.h"

//definition for static instance variable
InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::initialiseJoysticks()
{	
	//check if joystick was initialised(will return non zero)
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{	
		//initialise the joystick
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	//find the number of joysticks and push them in vector
	if (SDL_NumJoysticks() > 0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); ++i)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i); //opens a joystick for use
			
			//check if NULL was not returned and joystick opened successfully
			if (SDL_JoystickOpen(i) != NULL) //original was == 1
			{
				m_joysticks.push_back(joy);
			}
			else
			{
				//error opening joystick
				std::cout << SDL_GetError();
			}
		}

		//listen for joystick events
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;

		std::cout << "Initialised " << m_joysticks.size() << " joystick(s)";
	}
	else
	{
		m_bJoysticksInitialised = false;
	}
}

bool InputHandler::joysticksInitialised()
{
	return m_bJoysticksInitialised;
}

void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			TheGame::Instance()->quit();
		}
	}
}

void InputHandler::clean()
{
	if (m_bJoysticksInitialised)
	{
		for (unsigned int i = 0; i < m_joysticks.size(); ++i)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}