#pragma once
#include "ISolidShape.h"
#include "�Point.h"
#include <math.h>

class CTriangle : public ISolidShape
{
public:
	CTriangle(�Point vertex1, �Point vertex2, �Point vertex3);
	CTriangle(�Point vertex1, �Point vertex2, �Point vertex3,
		std::string outlineColor, std::string fillColor);
	~CTriangle();
	double GetArea() const;
	double GetPerimeter() const;
	std::string ToString() const;
	std::string GetOutlineColor() const;
	std::string GetFillColor() const;
	�Point GetVertex1() const;
	�Point GetVertex2() const;
	�Point GetVertex3() const;
private:
	void FillLines();
	void FillLengthOfLines();
	�Point m_vertex1;
	�Point m_vertex2;
	�Point m_vertex3;
	std::string m_outlineColor;
	std::string m_fillColor;
	double m_semiperimeter;
	�Point m_line1;
	�Point m_line2;
	�Point m_line3;
	double m_lengthOfLine1;
	double m_lengthOfLine2;
	double m_lengthOfLine3;

};

