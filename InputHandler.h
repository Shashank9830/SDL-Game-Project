#pragma once

#ifndef __InputHandler__
#define __InputHandler__

#include "SDL.h"

class InputHandler
{
	InputHandler();
	~InputHandler(){}

	static InputHandler* s_pInstance;
public:

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();
};

typedef InputHandler TheInputHandler;

#endif //defined(__InputHandler__)