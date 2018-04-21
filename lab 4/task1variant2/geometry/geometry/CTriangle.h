#pragma once
#include "ISolidShape.h"
#include "ÑPoint.h"
#include "CVector.h"
#include <sstream>
#include <math.h>

class CTriangle : public ISolidShape
{
public:
	CTriangle(ÑPoint vertex1, ÑPoint vertex2, ÑPoint vertex3);
	CTriangle(ÑPoint vertex1, ÑPoint vertex2, ÑPoint vertex3,
		std::string outlineColor, std::string fillColor);
	~CTriangle();
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	ÑPoint GetVertex1() const;
	ÑPoint GetVertex2() const;
	ÑPoint GetVertex3() const;
private:
	ÑPoint m_vertex1;
	ÑPoint m_vertex2;
	ÑPoint m_vertex3;
	std::string m_outlineColor;
	std::string m_fillColor;
	void CulcalatePerimetrAndArea(ÑPoint& vertex1, ÑPoint& vertex2, ÑPoint& vertex3);
	double m_area;
	double m_perimetr;
};

