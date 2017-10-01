#pragma once

#ifndef __InputHandler__
#define __InputHandler__

#include "SDL.h"
#include <vector>

class InputHandler
{
	InputHandler() {}
	~InputHandler(){}

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;

	bool m_bJoysticksInitialised;

public:

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void initialiseJoysticks();

	bool joysticksInitialised();

	void update();
	void clean();
};

typedef InputHandler TheInputHandler;

#endif //defined(__InputHandler__)