#pragma once

#ifndef __GameObject__
#define __GameObject__

#include "LoaderParams.h"

class GameObject
{
protected:
	GameObject() {}
	virtual ~GameObject(){}

public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	//new load function
	virtual void load(const LoaderParams* pParams) = 0;
};

#endif //defined (__GameObject__)