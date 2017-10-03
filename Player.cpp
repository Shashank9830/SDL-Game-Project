#include "Player.h"
#include "SDL.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) { }

void Player::draw()
{
	SDLGameObject::draw();	//we now use SDLGameObject
}

void Player::update()
{	
	m_velocity.setX(0);
	m_velocity.setY(0);

	m_acceleration.setX(0);
	m_acceleration.setY(0);

	handleInput();	//adding our function

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	SDLGameObject::update();
}

void Player::clean()
{
	//blank clean() function
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->joysticksInitialised())
	{	
		//for analog sticks of the first joystick
		if ((TheInputHandler::Instance()->xvalue(0, 1) > 0) || (TheInputHandler::Instance()->xvalue(0, 1) < 0))
		{
			m_velocity.setX((float)1 * TheInputHandler::Instance()->xvalue(0, 1));
			if (TheInputHandler::Instance()->getButtonState(0, 3))	//Button 3(Yellow)
			{
				//give the player some acceleration
				m_acceleration.setX(2 * TheInputHandler::Instance()->xvalue(0, 1));
			}
		}

		if ((TheInputHandler::Instance()->yvalue(0, 1) > 0) || (TheInputHandler::Instance()->yvalue(0, 1) < 0))
		{
			m_velocity.setY((float)1 * TheInputHandler::Instance()->yvalue(0, 1));

			//if we are moving the player with analog stick while pressing Y
			//it will get an acceleration of 2 in that direction
			if (TheInputHandler::Instance()->getButtonState(0, 3))	//Button 3(Yellow)
			{
				//give the player some acceleration
				m_acceleration.setY(2 * TheInputHandler::Instance()->yvalue(0,1));
			}
		}

		if ((TheInputHandler::Instance()->xvalue(0, 2) > 0) || (TheInputHandler::Instance()->xvalue(0, 2) < 0))
		{
			m_velocity.setX((float)1 * TheInputHandler::Instance()->xvalue(0, 2));
			if (TheInputHandler::Instance()->getButtonState(0, 3))	//Button 3(Yellow)
			{
				//give the player some acceleration
				m_acceleration.setX(2 * TheInputHandler::Instance()->xvalue(0, 1));
			}
		}

		if ((TheInputHandler::Instance()->yvalue(0, 2) > 0) || (TheInputHandler::Instance()->yvalue(0, 2) < 0))
		{
			m_velocity.setY((float)1 * TheInputHandler::Instance()->yvalue(0, 2));
			if (TheInputHandler::Instance()->getButtonState(0, 3))	//Button 3(Yellow)
			{
				//give the player some acceleration
				m_acceleration.setY(2 * TheInputHandler::Instance()->yvalue(0, 1));
			}
		}
		/*	Code as in the book
		//for buttons of the first joystick
		if (TheInputHandler::Instance()->getButtonState(0, 3))	//Button 3(Yellow)
		{
			//give the player some acceleration
			m_acceleration.setX(1);
		}
		*/
	}
}