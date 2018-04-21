#pragma once
#include <string>
#include <iostream>

class ÑPoint
{
public:
	ÑPoint(double x, double y);
	ÑPoint();
	~ÑPoint();
	double GetX() const;
	double GetY() const;
	bool operator ==(ÑPoint const& otherPoint) const;
	ÑPoint const operator -(ÑPoint const& otherPoint) const;
private:
	double m_x = 0;
	double m_y = 0;
};

