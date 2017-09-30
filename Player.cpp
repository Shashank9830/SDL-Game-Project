#include "Player.h"
#include "SDL.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) { }

void Player::draw()
{
	SDLGameObject::draw();	//we now use SDLGameObject
}

void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	m_accelaration.setX(1);

	SDLGameObject::update();
}

void Player::clean()
{
	//blank clean() function
}