#include "stdafx.h"
#include "ÑPoint.h"


ÑPoint::ÑPoint(double x, double y)
	: m_x(x), m_y(y)
{
}

ÑPoint::ÑPoint()
{
	m_x = 0.0;
	m_y = 0.0;
}

double ÑPoint::GetX() const
{
	return m_x;
}

double ÑPoint::GetY() const
{
	return m_y;
}

bool ÑPoint::operator==(ÑPoint const& otherPoint) const
{
	return (m_x == otherPoint.m_x) && (m_y == otherPoint.m_y);
}

ÑPoint const ÑPoint::operator -(ÑPoint const& otherPoint) const
{
	return ÑPoint(m_x - otherPoint.m_x, m_y - otherPoint.m_y);
}


ÑPoint::~ÑPoint()
{
}
