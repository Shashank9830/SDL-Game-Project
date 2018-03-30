#pragma once

#ifndef __MainMenuState__
#define __MainMenuState__

#include "MenuState.h"
#include <vector>
#include "GameObject.h"

class MainMenuState :public MenuState
{
	static const std::string s_menuID;

	//vector to store menu items
	std::vector<GameObject*> m_gameObjects;

	//call back functions for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();

	virtual void setCallbacks(const std::vector<Callback> &Callbacks);
	
public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }
};

#endif //defined(__MenuState__)