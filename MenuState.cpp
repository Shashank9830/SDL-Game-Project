#include "MenuState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"

const std::string MenuState::s_menuID = "MENU";

//function to be called when PLAY button is pressed
void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";
}

//function to be called when EXIT button is pressed
void MenuState::s_exitFromMenu()
{
	//exit the game
	TheGame::Instance()->quit();
}

//update each game object
void MenuState::update()
{
	for (int i = 0; i < (int)m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->update();
	}
}

//draw the game objects
void MenuState::render()
{
	for (int i = 0; i < (int)m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{	
	//load the play button image
	if (!TheTextureManager::Instance()->load("assets/button.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	//load the exit button image
	if (!TheTextureManager::Instance()->load("assets/exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	//assign the new textures to game objects named button1 and button2
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu);

	//push them in the vector
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{	
	//iterate through all the objects and clean 
	for (int i = 0; i < (int)m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	//remove the button textures
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");


	std::cout << "exiting MenuState\n";
	return true;
}