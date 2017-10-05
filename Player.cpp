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
			//if we are moving the player with analog stick while pressing Y
			//it will get an acceleration of 2 in that direction
			m_velocity.setX((float)1 * TheInputHandler::Instance()->xvalue(0, 1));
			if (TheInputHandler::Instance()->getButtonState(0, 3))	//Button 3(Yellow)
			{
				//give the player some acceleration
				m_acceleration.setX((float)2 * TheInputHandler::Instance()->xvalue(0, 1));
			}
		}

		if ((TheInputHandler::Instance()->yvalue(0, 1) > 0) || (TheInputHandler::Instance()->yvalue(0, 1) < 0))
		{
			m_velocity.setY((float)1 * TheInputHandler::Instance()->yvalue(0, 1));
			if (TheInputHandler::Instance()->getButtonState(0, 3))
			{
				m_acceleration.setY((float)2 * TheInputHandler::Instance()->yvalue(0,1));
			}
		}

		if ((TheInputHandler::Instance()->xvalue(0, 2) > 0) || (TheInputHandler::Instance()->xvalue(0, 2) < 0))
		{
			m_velocity.setX((float)1 * TheInputHandler::Instance()->xvalue(0, 2));
			if (TheInputHandler::Instance()->getButtonState(0, 3))
			{
				m_acceleration.setX((float)2 * TheInputHandler::Instance()->xvalue(0, 1));
			}
		}

		if ((TheInputHandler::Instance()->yvalue(0, 2) > 0) || (TheInputHandler::Instance()->yvalue(0, 2) < 0))
		{
			m_velocity.setY((float)1 * TheInputHandler::Instance()->yvalue(0, 2));
			if (TheInputHandler::Instance()->getButtonState(0, 3))
			{
				m_acceleration.setY((float)2 * TheInputHandler::Instance()->yvalue(0, 1));
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

	//check for mouse button input
	if (InputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_acceleration.setX(-3);
	}
	if (InputHandler::Instance()->getMouseButtonState(RIGHT))
	{
		m_acceleration.setX(3);
	}

	//check for mouse motion input
	//commenting this feature as I don't want player to follow mouse
	//uncomment the following code to enable the featurezx
	/*

	Vector2D* vec;
	vec = new Vector2D(0, 0);

	vec = TheInputHandler::Instance()->getMousePosition();

	m_velocity = (*vec - m_position) / 100;
	
	*/

	//Adding keyboard controls 
	//UP DOWN RIGHT LEFT for movement
	//Right Ctrl for Acceleration
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
		//check if Right Ctrl is pressed, provide acc. if true
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
		{
			m_acceleration.setX(2.5);
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
		//check if Right Ctrl is pressed, provide acc. if true
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
		{
			m_acceleration.setX(-2.5);
		}
	}
	//remember the cartesian plane is inverted along Y Axis
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
		//check if Right Ctrl is pressed, provide acc. if true
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
		{
			m_acceleration.setY(-2.5);
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
		//check if Right Ctrl is pressed, provide acc. if true
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
		{
			m_acceleration.setY(2.5);
		}
	}
}