#include "stdafx.h"
#include "CRectangle.h"


CRectangle::CRectangle(ÑPoint leftTop, ÑPoint rightTop, ÑPoint rightBottom, ÑPoint leftBottom)
	: m_leftTop(leftTop), m_leftBottom(leftBottom), m_rightTop(rightTop), m_rightBottom(rightBottom)
{
	m_outlineColor = "black";
	m_fillColor = "black";
	m_vectorWidth = leftTop - rightTop;
	m_vectroHeight = leftTop - leftBottom;
	m_height = sqrt(m_vectroHeight.GetX() * m_vectroHeight.GetX() + m_vectroHeight.GetY() * m_vectroHeight.GetY());
	m_width = sqrt(m_vectorWidth.GetX() * m_vectorWidth.GetX() + m_vectorWidth.GetY() * m_vectorWidth.GetY());
	m_area = m_height * m_width;
	m_perimeter = 2 * (m_height + m_width);
}

CRectangle::CRectangle(ÑPoint leftTop, ÑPoint rightTop, ÑPoint rightBottom,
	ÑPoint leftBottom, std::string outlineColor, std::string fillColor)
	: m_leftTop(leftTop), m_leftBottom(leftBottom), m_rightTop(rightTop), m_rightBottom(rightBottom),
	m_fillColor(fillColor), m_outlineColor(outlineColor)
{
	m_vectorWidth = leftTop - rightTop;
	m_vectroHeight = leftTop - leftBottom;
	m_height = sqrt(m_vectroHeight.GetX() * m_vectroHeight.GetX() + m_vectroHeight.GetY() * m_vectroHeight.GetY());
	m_width = sqrt(m_vectorWidth.GetX() * m_vectorWidth.GetX() + m_vectorWidth.GetY() * m_vectorWidth.GetY());
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
	return "Rectangle has same lines";
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
