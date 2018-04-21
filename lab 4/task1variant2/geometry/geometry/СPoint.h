#pragma once
#include <string>
#include <iostream>

class �Point
{
public:
	�Point(double x, double y);
	�Point();
	~�Point();
	double GetX() const;
	double GetY() const;
	bool operator ==(�Point const& otherPoint) const;
	�Point const operator -(�Point const& otherPoint) const;
private:
	double m_x = 0;
	double m_y = 0;
};

