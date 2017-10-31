#pragma once

#ifndef __MenuButton__
#define __MenuButton__

#include "SDLGameObject.h"
#include "LoaderParams.h"

class MenuButton : public SDLGameObject
{
	enum button_state
	{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
	};

	//variable to handle clicking
	bool m_bReleased;

	void(*m_callback)();

public:

	MenuButton(const LoaderParams* pParams, void (*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();
};

#endif //defined!(__MenuButton__)