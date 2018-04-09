#pragma once
#include "ISolidShape.h"
#include "ÑPoint.h"
#include <math.h>

class CCircle : public ISolidShape
{
public:
	CCircle(ÑPoint centre, double radius);
	CCircle(ÑPoint centre, double radius,
		std::string outlineColor, std::string fillColor);
	CCircle();
	double GetArea() const;
	double GetPerimeter() const;
	ÑPoint GetCentre() const;
	double GetRadius() const;
	std::string ToString() const;
	std::string GetOutlineColor() const;
	std::string GetFillColor() const;
	~CCircle();
private:
	void FillCircleParameters();
	double m_radius;
	ÑPoint m_centre;
	double m_areaOfCircle;
	double m_lengthOfCircle;
	const double P_NUMBER = 3.14;
	std::string m_outlineColor = "";
	std::string m_fillColor = "";
};

