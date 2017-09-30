#pragma once

#ifndef __Vector2D__
#define __Vector2D__

class Vector2D
{
	float m_x;
	float m_y;
public:
	Vector2D(float x, float y): m_x(x), m_y(y) { }

	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	//finding the length of the vector
	float length();

	//addition of two Vectors using + or +=
	Vector2D operator + (const Vector2D& v2) const;
	friend Vector2D& operator += (Vector2D& v1, const Vector2D& v2);
	
	//multiplication of a vector with a scalar number using * or *=
	Vector2D operator * (float scalar);
	Vector2D& operator *= (float scalar);

	//subtraction of two vector using - or -=
	Vector2D operator - (const Vector2D& v2) const;
	friend Vector2D& operator -= (Vector2D& v1, const Vector2D& v2);

	//division of a vector by a scalar number using / or /=
	Vector2D operator / (float scalar);
	Vector2D& operator /= (float scalar);

	//normalizing a vector
	void normalize();
};

#endif //(__Vector2D__)