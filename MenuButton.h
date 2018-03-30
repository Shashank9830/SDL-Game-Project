#pragma once

#ifndef __MenuButton__
#define __MenuButton__

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

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

	MenuButton();

	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual void load(const LoaderParams* pParams);

	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
};

class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};

#endif //defined!(__MenuButton__)