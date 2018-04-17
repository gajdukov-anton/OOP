#pragma once
#include "ISolidShape.h"
#include "�Point.h"
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
	void FillLines();
	void FillLengthOfLines();
	�Point m_vertex1;
	�Point m_vertex2;
	�Point m_vertex3;
	std::string m_outlineColor = "black";
	std::string m_fillColor = "black";
	double m_semiperimeter;
	�Point m_line1;
	�Point m_line2;
	�Point m_line3;
	double m_lengthOfLine1;
	double m_lengthOfLine2;
	double m_lengthOfLine3;
	double m_area;
	double m_perimetr;
};

