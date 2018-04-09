#pragma once
#include "ISolidShape.h"
#include "ÑPoint.h"
#include <math.h>

class CTriangle : public ISolidShape
{
public:
	CTriangle(ÑPoint vertex1, ÑPoint vertex2, ÑPoint vertex3);
	CTriangle(ÑPoint vertex1, ÑPoint vertex2, ÑPoint vertex3,
		std::string outlineColor, std::string fillColor);
	~CTriangle();
	double GetArea() const;
	double GetPerimeter() const;
	std::string ToString() const;
	std::string GetOutlineColor() const;
	std::string GetFillColor() const;
	ÑPoint GetVertex1() const;
	ÑPoint GetVertex2() const;
	ÑPoint GetVertex3() const;
private:
	void FillLines();
	void FillLengthOfLines();
	ÑPoint m_vertex1;
	ÑPoint m_vertex2;
	ÑPoint m_vertex3;
	std::string m_outlineColor;
	std::string m_fillColor;
	double m_semiperimeter;
	ÑPoint m_line1;
	ÑPoint m_line2;
	ÑPoint m_line3;
	double m_lengthOfLine1;
	double m_lengthOfLine2;
	double m_lengthOfLine3;

};

