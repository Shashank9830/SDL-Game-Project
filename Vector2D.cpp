#include "Vector2D.h"
#include <math.h>

//function to calculate the length of a vector
float Vector2D::length()
{
	return (float)sqrt((m_x * m_x) + (m_y * m_y));
}

//addition of two vectors using + operator
Vector2D Vector2D::operator + (const Vector2D& v2) const
{
	return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

//addition of two vectors using += operator
Vector2D& operator += (Vector2D& v1, const Vector2D& v2)
{
	v1.m_x += v2.m_x;
	v1.m_y += v2.m_y;

	return v1;
}

//multiplication of a vector with a scalar number using * operator
Vector2D Vector2D::operator * (float scalar)
{
	return Vector2D(m_x * scalar, m_y * scalar);
}

//multiplication of a vector with a scalar number using *= operator
Vector2D& Vector2D::operator *= (float scalar)
{
	m_x *= scalar;
	m_y *= scalar;

	return *this;
}

//subtraction of two vectors using - operator
Vector2D Vector2D::operator - (const Vector2D& v2) const
{
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

//subtraction of two vectors using -= operator
Vector2D& operator -= (Vector2D& v1, const Vector2D& v2)
{
	v1.m_x -= v2.m_x;
	v1.m_y -= v2.m_y;

	return v1;
}

//division of a vector by a scalar number using / operator
Vector2D Vector2D::operator / (float scalar)
{
	return Vector2D(m_x / scalar, m_y / scalar);
}

//division of a vector by a scalar number using /= operator
Vector2D& Vector2D::operator /= (float scalar)
{
	m_x /= scalar;
	m_y /= scalar;

	return *this;
}

//function to normalize a vector
void Vector2D::normalize()
{
	float l = length();
	if (l > 0)	//we never want to attempt  to divide by 0
	{
		(*this) *= 1 / l;
	}
}