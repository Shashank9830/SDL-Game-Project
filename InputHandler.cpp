#include "InputHandler.h"
#include <iostream>
#include "Game.h"

//definition for static instance variable
InputHandler* InputHandler::s_pInstance = 0;

//constructor initialises the mouse buttons to false
InputHandler::InputHandler()
{
	for (int i = 0; i < 3; ++i)
	{
		m_mouseButtonStates.push_back(false);
	}
	m_mousePosition = new Vector2D(0, 0);
}



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
				
				//add our pair of analog sticks for that joystick
				m_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

				//initialize all the buttons for this joystick to false state
				std::vector <bool> tempButtons;

				for (int j = 0; j < SDL_JoystickNumButtons(joy); ++j)
				{
					tempButtons.push_back(false);
				}

				//push this joystick in the outer container
				m_buttonStates.push_back(tempButtons);
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
			return (int)m_joystickValues[joy].first->getX();
		}
		else //right stick
		{
			return (int)m_joystickValues[joy].second->getX();
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
			return (int)m_joystickValues[joy].first->getY();
		}
		else //right stick
		{
			return (int)m_joystickValues[joy].second->getY();
		}
	}
	return 0;
}

bool InputHandler::getButtonState(int joy, int buttonNumber)
{
	return m_buttonStates[joy][buttonNumber];
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition()
{
	return m_mousePosition;
}

//Function to check if specific key was pressed by taking SDL_Scancode as param
//Refer to this link for SDL_Scancode
//https://wiki.libsdl.org/SDL_Scancode?highlight=%28%5CbCategoryEnum%5Cb%29%7C%28SDLEnumTemplate%29
//SDL_Scancode for entire all the keys
bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != NULL)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;

		case SDL_JOYAXISMOTION:
			onJoystickAxisMove(event);
			break;

		case SDL_JOYBUTTONDOWN:
			onJoystickButtonDown(event);
			break;

		case SDL_JOYBUTTONUP:
			onJoystickButtonUp(event);
			break;

		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;

		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;

		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;

		case SDL_KEYDOWN:
			onKeyDown();
			break;

		case SDL_KEYUP:
			onKeyUp();
			break;

		default:
			break;
		}
	}
}

//keyboard event functions
void InputHandler::onKeyDown()
{
	m_keystates = SDL_GetKeyboardState(NULL);
}

void InputHandler::onKeyUp()
{
	m_keystates = SDL_GetKeyboardState(NULL);
}

//mouse event functions
void InputHandler::onMouseMove(SDL_Event &event)
{
	m_mousePosition->setX(event.motion.x);
	m_mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}

	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}

	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}

//joystick event functions
void InputHandler::onJoystickAxisMove(SDL_Event &event)
{
	int whichOne = event.jaxis.which;

	// left stick move left or right
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

	// left stick move up or down
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

	// right stick move left or right
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

	// right stick move up or down
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

void InputHandler::onJoystickButtonDown(SDL_Event &event)
{
	int whichOne = event.jaxis.which;

	m_buttonStates[whichOne][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event &event)
{
	int whichOne = event.jaxis.which;

	m_buttonStates[whichOne][event.jbutton.button] = false;
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