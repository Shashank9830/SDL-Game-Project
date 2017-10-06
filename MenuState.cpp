#include "MenuState.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	//nothing for now
}

void MenuState::render()
{
	//nothing for now
}

bool MenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}