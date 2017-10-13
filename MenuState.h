#pragma once

#ifndef __MenuState__
#define __MenuState__

#include "GameState.h"
#include <vector>
#include "GameObject.h"

class MenuState :public GameState
{
	static const std::string s_menuID;

	//vector to store menu items
	std::vector<GameObject*> m_gameObjects;
	
public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }
};

#endif //defined(__MenuState__)