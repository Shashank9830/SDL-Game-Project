#include "Enemy.h"
#include "SDL.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) { }

void Enemy::draw()
{
	SDLGameObject::draw(); //now we use SDLGameObject
}

//Update function for Enemy object
void Enemy::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	m_acceleration.setX(0);
	m_acceleration.setY(0);

	handleInput();	//handles the input from joystick [2nd controller]

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	SDLGameObject::update();
}

void Enemy::clean()
{
	//blank clean() function
}

//Enemy class uses the Second Joystick
void Enemy::handleInput()
{	
	//check if a second controller is available and use it for enemy object
	if ((TheInputHandler::Instance()->joysticksInitialised()) && (SDL_NumJoysticks() > 1))
	{	
		//for analog sticks of the second joystick
		if ((TheInputHandler::Instance()->xvalue(1, 1) > 0) || (TheInputHandler::Instance()->xvalue(1, 1) < 0))
		{	
			//if we are moving the player with analog stick while pressing Y
			//it will get an acceleration of 2 in that direction
			m_velocity.setX((float)1 * TheInputHandler::Instance()->xvalue(1, 1));
			if (TheInputHandler::Instance()->getButtonState(0, 3))	//Button 3(Yellow)
			{
				//give the player some acceleration
				m_acceleration.setX((float)2 * TheInputHandler::Instance()->xvalue(1, 1));
			}
		}

		if ((TheInputHandler::Instance()->yvalue(1, 1) > 0) || (TheInputHandler::Instance()->yvalue(1, 1) < 0))
		{
			m_velocity.setY((float)1 * TheInputHandler::Instance()->yvalue(1, 1));
			if (TheInputHandler::Instance()->getButtonState(1, 3))
			{
				m_acceleration.setY((float)2 * TheInputHandler::Instance()->yvalue(1, 1));
			}
		}

		if ((TheInputHandler::Instance()->xvalue(1, 2) > 0) || (TheInputHandler::Instance()->xvalue(1, 2) < 0))
		{
			m_velocity.setX((float)1 * TheInputHandler::Instance()->xvalue(1, 2));
			if (TheInputHandler::Instance()->getButtonState(1, 3))
			{
				m_acceleration.setX((float)2 * TheInputHandler::Instance()->xvalue(1, 1));
			}
		}

		if ((TheInputHandler::Instance()->yvalue(1, 2) > 0) || (TheInputHandler::Instance()->yvalue(1, 2) < 0))
		{
			m_velocity.setY((float)1 * TheInputHandler::Instance()->yvalue(1, 2));
			if (TheInputHandler::Instance()->getButtonState(1, 3))
			{
				m_acceleration.setY((float)2 * TheInputHandler::Instance()->yvalue(1, 1));
			}
		}
	}

	//no mouse control for enemy

	//keyboard A W S D for movement, Right Shift for acceleration
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_velocity.setX(2);
		//check if Right Ctrl is pressed, provide acc. if true
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT))
		{
			m_acceleration.setX(2.5);
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_velocity.setX(-2);
		//check if Right Ctrl is pressed, provide acc. if true
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT))
		{
			m_acceleration.setX(-2.5);
		}
	}
	//remember the cartesian plane is inverted along Y Axis
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		m_velocity.setY(-2);
		//check if Right Ctrl is pressed, provide acc. if true
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT))
		{
			m_acceleration.setY(-2.5);
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{
		m_velocity.setY(2);
		//check if Right Ctrl is pressed, provide acc. if true
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT))
		{
			m_acceleration.setY(2.5);
		}
	}
}