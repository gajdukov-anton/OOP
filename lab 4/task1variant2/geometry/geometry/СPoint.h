#pragma once
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
	double m_x;
	double m_y;
};

