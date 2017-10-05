#pragma once

#ifndef __InputHandler__
#define __InputHandler__

#include "SDL.h"
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
	InputHandler();
	~InputHandler(){}

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;

	//a vector of pairs(one for each stick)
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;

	//a vector of vector(for each joystick and all of its buttons)
	std::vector<std::vector<bool>> m_buttonStates;

	//variable to account the sensitivity of the controller
	const int m_joystickDeadZone = 10000;

	bool m_bJoysticksInitialised;

	//vector for mouse buttons(0 = left, 1 = middle, 2 = right)
	std::vector<bool> m_mouseButtonStates;

	//vector for mouse position
	Vector2D m_mousePosition;

	//Pointer to the array returned by SDL_GetKeyboardState with "int* numkeys" arg
	const Uint8* m_keystates;

	//handle keyboard events
	void onKeyDown();
	void onKeyUp();

	//handle mouse events
	void onMouseMove(SDL_Event &event);
	void onMouseButtonDown(SDL_Event &event);
	void onMouseButtonUp(SDL_Event &event);

	//handle joystick events
	void onJoystickAxisMove(SDL_Event &event);
	void onJoystickButtonDown(SDL_Event &event);
	void onJoystickButtonUp(SDL_Event &event);

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

	//Function to check if a specific button was pressed on a specific joystick
	bool getButtonState(int joy, int buttonNumber);
	
	//joy = Joystick identifier, stick = 1(left) and 2(right)
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	//Function to check if a specific mouse button was pressed
	bool getMouseButtonState(int buttonNumber);

	//Function to return mouse position
	Vector2D getMousePosition();

	//Function to check if a key was pressed on the keyboard
	bool isKeyDown(SDL_Scancode key);

	void update();
	void clean();
};

typedef InputHandler TheInputHandler;

#endif //defined(__InputHandler__)