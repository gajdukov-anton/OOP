#pragma once
#include "ISolidShape.h"
#include "�Point.h"
#include "CVector.h"
#include <sstream>
#include <math.h>

class CTriangle : public ISolidShape
{
public:
	CTriangle(�Point vertex1, �Point vertex2, �Point vertex3);
	CTriangle(�Point vertex1, �Point vertex2, �Point vertex3,
		std::string outlineColor, std::string fillColor);
	~CTriangle();
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	�Point GetVertex1() const;
	�Point GetVertex2() const;
	�Point GetVertex3() const;
private:
	�Point m_vertex1;
	�Point m_vertex2;
	�Point m_vertex3;
	std::string m_outlineColor;
	std::string m_fillColor;
	void CulcalatePerimetrAndArea(�Point& vertex1, �Point& vertex2, �Point& vertex3);
	double m_area;
	double m_perimetr;
};

