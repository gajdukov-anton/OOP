#pragma once
#include "ISolidShape.h"
#include "�Point.h"
#include <math.h>
#include <sstream>


class CCircle : public ISolidShape
{
public:
	CCircle(�Point centre, double radius);
	CCircle(�Point centre, double radius,
		std::string outlineColor, std::string fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	�Point GetCentre() const ;
	double GetRadius() const;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	~CCircle();
private:
	double m_radius;
	�Point m_centre;
	double m_areaOfCircle;
	double m_lengthOfCircle;
	const double P_NUMBER = 3.14;
	std::string m_outlineColor = "black";
	std::string m_fillColor = "black";
};

