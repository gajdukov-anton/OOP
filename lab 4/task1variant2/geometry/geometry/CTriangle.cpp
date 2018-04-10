#include "stdafx.h"
#include "CTriangle.h"



CTriangle::CTriangle(ÑPoint vertex1, ÑPoint vertex2, ÑPoint vertex3)
	: m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3)
{
	FillLines();
	FillLengthOfLines();
	m_fillColor = "black";
	m_outlineColor = "black";
	m_perimetr = m_lengthOfLine1 + m_lengthOfLine2 + m_lengthOfLine3;
	m_semiperimeter = (m_perimetr) / 2;
	m_area = sqrt(m_semiperimeter * (m_semiperimeter - m_lengthOfLine1) * (m_semiperimeter - m_lengthOfLine2) * (m_semiperimeter - m_lengthOfLine3));
}

CTriangle::CTriangle(ÑPoint vertex1, ÑPoint vertex2, ÑPoint vertex3,
	std::string outlineColor, std::string fillColor)
	: m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
	FillLines();
	FillLengthOfLines();
	m_perimetr = m_lengthOfLine1 + m_lengthOfLine2 + m_lengthOfLine3;
	m_semiperimeter = (m_perimetr) / 2;
	m_area = sqrt(m_semiperimeter * (m_semiperimeter - m_lengthOfLine1) * (m_semiperimeter - m_lengthOfLine2) * (m_semiperimeter - m_lengthOfLine3));
}

void CTriangle::FillLines()
{
	m_line1 = m_vertex2 - m_vertex1;
	m_line2 = m_vertex3 - m_vertex2;
	m_line3 = m_vertex1 - m_vertex3;
}

void CTriangle::FillLengthOfLines()
{
	m_lengthOfLine1 = sqrt(m_line1.GetX() * m_line1.GetX() + m_line1.GetY() * m_line1.GetY());
	m_lengthOfLine2 = sqrt(m_line2.GetX() * m_line2.GetX() + m_line2.GetY() * m_line2.GetY());
	m_lengthOfLine3 = sqrt(m_line3.GetX() * m_line3.GetX() + m_line3.GetY() * m_line3.GetY());
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
	return "Triangle has only three vertex.";
}



CTriangle::~CTriangle()
{
}
