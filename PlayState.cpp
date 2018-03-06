#include "PlayState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "PauseState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{	
	//listen for ESC key to pause the game
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < (int)m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < (int)m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/helicopter2.png", "helicopter2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, 5, "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, 5, "helicopter2"));

	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{	
	for (int i = 0; i < (int)m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");

	std::cout << "exiting PlayState\n";
	return true;
}