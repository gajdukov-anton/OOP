#include "stdafx.h"
#include "CTriangle.h"



CTriangle::CTriangle(ÑPoint vertex1, ÑPoint vertex2, ÑPoint vertex3)
	: m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3)
{
	m_outlineColor = "ffffff";
	m_fillColor = "ffffff";
	CulcalatePerimetrAndArea(m_vertex1, m_vertex2, m_vertex3);
}

CTriangle::CTriangle(ÑPoint vertex1, ÑPoint vertex2, ÑPoint vertex3,
	std::string outlineColor, std::string fillColor)
	: m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
	CulcalatePerimetrAndArea(m_vertex1, m_vertex2, m_vertex3);
}

void CTriangle::CulcalatePerimetrAndArea(ÑPoint& vertex1, ÑPoint& vertex2, ÑPoint& vertex3)
{
	CVector line1(vertex1, vertex2);
	CVector line2(vertex2, vertex3);
	CVector line3(vertex3, vertex1);
	double lengthOfLine1 = sqrt(line1.GetX() * line1.GetX() + line1.GetY() * line1.GetY());
	double lengthOfLine2 = sqrt(line2.GetX() * line2.GetX() + line2.GetY() * line2.GetY());
	double lengthOfLine3 = sqrt(line3.GetX() * line3.GetX() + line3.GetY() * line3.GetY());
	m_perimetr = lengthOfLine1 + lengthOfLine2 + lengthOfLine3;
	double semiperimeter = (m_perimetr) / 2;
	m_area = sqrt(semiperimeter * (semiperimeter - lengthOfLine1) * (semiperimeter - lengthOfLine2) * (semiperimeter - lengthOfLine3));
}

double CTriangle::GetArea() const
{
	return m_area;
}

double CTriangle::GetPerimeter() const
{
	return m_perimetr;
}

ÑPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

ÑPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

ÑPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

std::string  CTriangle::GetFillColor() const
{
	return m_fillColor;
}

std::string  CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CTriangle::ToString() const
{
	std::string str;
	std::ostringstream  stream;
	stream << "Area: " << GetArea() << std::endl;
	stream << "OutlineColor: " << GetOutlineColor() << std::endl;
	stream << "FillColor: " << GetFillColor() << std::endl;
	stream << "Perimetr: " << GetPerimeter() << std::endl;
	stream << "Specificity: " << "Triangle has only three vertex." << std::endl;
	return stream.str();
}



CTriangle::~CTriangle()
{
}
