#pragma once

#ifndef __Enemy__
#define __Enemy__
#include "SDLGameObject.h"

class Enemy: public SDLGameObject
{
	void handleInput();
public:

	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};

#endif //defined(__Enemy__)