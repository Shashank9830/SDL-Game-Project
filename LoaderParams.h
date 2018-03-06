#pragma once

#ifndef __LoaderParams__
#define __LoaderParams__

#include <iostream>

class LoaderParams
{
	int m_x;
	int m_y;

	int m_width;
	int m_height;
	int m_numFrames;

	std::string m_textureID;

public:
	LoaderParams(int x, int y, int width, int height, int numFrames, std::string textureID) : m_x(x), m_y(y), m_width(width), m_height(height), m_numFrames(numFrames), m_textureID(textureID) { }

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getnFrames() const { return m_numFrames; }
	
	std::string getTextureID() const { return m_textureID; }
};

#endif //defined(__LoaderParams__)