#include "stdafx.h"
#include "CRectangle.h"


CRectangle::CRectangle(ÑPoint leftTop, ÑPoint rightBottom)
	: m_leftTop(leftTop), m_rightBottom(rightBottom)
{
	m_outlineColor = "ffffff";
	m_fillColor = "ffffff";
	m_height = leftTop.GetY() - rightBottom.GetY();
	m_width = leftTop.GetX() - rightBottom.GetX();
	if (m_height < 0)
		m_height *= -1;
	if (m_width < 0)
		m_width *= -1;	
	m_area = m_height * m_width;
	m_perimeter = 2 * (m_height + m_width);
}

CRectangle::CRectangle(ÑPoint leftTop, ÑPoint rightBottom,
	std::string outlineColor, std::string fillColor)
	: m_leftTop(leftTop), m_rightBottom(rightBottom), m_fillColor(fillColor), m_outlineColor(outlineColor)
{
	m_height = leftTop.GetY() - rightBottom.GetY();
	m_width = leftTop.GetX() - rightBottom.GetX();
	if (m_height < 0)
		m_area *= -1;
	if (m_width < 0)
		m_width *= -1;
	m_area = m_height * m_width;
	m_perimeter = 2 * (m_height + m_width);

}

double CRectangle::GetArea() const
{
	return m_area;
}

double CRectangle::GetPerimeter() const
{
	return m_perimeter;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

std::string CRectangle::ToString() const
{
	std::string str;
	std::ostringstream  stream;
	stream << "Area: " << GetArea() << std::endl;
	stream << "OutlineColor: " << GetOutlineColor() << std::endl;
	stream << "FillColor: " << GetFillColor() << std::endl;
	stream << "Perimetr: " << GetPerimeter() << std::endl;
	stream << "Specificity: " << "Rectangle has same lines" << std::endl;

	return stream.str();
}

ÑPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

ÑPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

CRectangle::~CRectangle()
{
}
