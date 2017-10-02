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
				
				//add our pair
				m_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));
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

int InputHandler::xvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)	//left stick
		{
			return m_joystickValues[joy].first->getX();
		}
		else //right stick
		{
			return m_joystickValues[joy].second->getX();
		}
	}
	return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)	//left stick
		{
			return m_joystickValues[joy].first->getY();
		}
		else //right stick
		{
			return m_joystickValues[joy].second->getY();
		}
	}
	return 0;
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
		
		/*	Joystick Axis motion events
		
			Axis 0, 1 = left analog stick  (0 = x axis, 1 = y axis)
			Axis 3, 4 = right analog stick (3 = x axis, 4 = y axis)
		
		*/
		if (event.type == SDL_JOYAXISMOTION)
		{
			int whichOne = event.jaxis.which;

			//left stick move left or right
			if (event.jaxis.axis == 0)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(-1);
				}
				else
				{
					m_joystickValues[whichOne].first->setX(0);
				}
			}

			//left stick move up or down
			if (event.jaxis.axis == 1)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setY(-1);
				}
				else
				{
					m_joystickValues[whichOne].first->setY(0);
				}
			}

			//right stick move left or right
			if (event.jaxis.axis == 3)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setX(-1);
				}
				else
				{
					m_joystickValues[whichOne].second->setX(0);
				}
			}

			//right stick move up or down
			if (event.jaxis.axis == 4)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(-1);
				}
				else
				{
					m_joystickValues[whichOne].second->setY(0);
				}
			}
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