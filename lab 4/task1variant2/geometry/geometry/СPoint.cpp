#include "stdafx.h"
#include "�Point.h"


�Point::�Point(double x, double y)
	: m_x(x), m_y(y)
{
}

�Point::�Point()
{
	m_x = 0.0;
	m_y = 0.0;
}

double �Point::GetX() const
{
	return m_x;
}

double �Point::GetY() const
{
	return m_y;
}

bool �Point::operator==(�Point const& otherPoint) const
{
	return (m_x == otherPoint.m_x) && (m_y == otherPoint.m_y);
}

�Point const �Point::operator -(�Point const& otherPoint) const
{
	return �Point(m_x - otherPoint.m_x, m_y - otherPoint.m_y);
}


�Point::~�Point()
{
}
