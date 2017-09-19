#pragma once

#ifndef __GameObject__
#define __GameObject__
#include <iostream>

class GameObject
{
protected:
	int m_x;
	int m_y;

public:
	void draw() { std::cout << "draw game object"; }
	void update() { std::cout << "update game object"; }
	void clean() { std::cout << "clean game object"; }
};

#endif //defined (__GameObject__)
