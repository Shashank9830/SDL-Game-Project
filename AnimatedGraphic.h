#pragma once

#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
	int m_animSpeed;

public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);

	void update();
	void draw();
	void clean();
};

#endif //defined(__AnimatedGraphic__)
