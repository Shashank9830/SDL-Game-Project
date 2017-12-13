#include "AnimatedGraphic.h"
#include "SDL.h"

//constructor for AnimatedGraphic class
AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) : SDLGameObject(pParams), m_animSpeed(animSpeed) 
{

}

void AnimatedGraphic::draw()
{
	SDLGameObject::draw();
}

//update function of animated graphic class
void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 6));
}

void AnimatedGraphic::clean()
{
	SDLGameObject::clean();
}