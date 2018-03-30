#include "MenuButton.h"
#include "InputHandler.h"

//constructor for MenuButton, calls SDLGameObject constructor first with LoaderParams
MenuButton::MenuButton() : SDLGameObject()
{
	m_currentFrame = MOUSE_OUT;	//start at frame 0
}

void MenuButton::draw()
{
	SDLGameObject::draw();	//use the base class drawing
}

void MenuButton::update()
{	
	//get the coordinates of the mouse pointer and save them in pMousePos
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	//check if the mouse pointer is over the button
	if (pMousePos->getX() < (m_position.getX() + m_width) 
		&& pMousePos->getX() > m_position.getX() 
		&& pMousePos->getY() < (m_position.getY() + m_height) 
		&& pMousePos->getY() > m_position.getY())
	{	
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{	
			//confirms that the button was clicked
			m_currentFrame = CLICKED;

			m_callback();	//call out callback function

			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;

			//Mouse is over the button
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{	
		//Mouse is not over the button
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}

void MenuButton::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_currentFrame = MOUSE_OUT;
}