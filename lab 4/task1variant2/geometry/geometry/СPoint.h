#pragma once
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
	double m_x;
	double m_y;
};

