#include "stdafx.h"
#include "CCircle.h"

CCircle::CCircle(ÑPoint centre, double radius)
	: m_centre(centre), m_radius(radius)
{
	m_lengthOfCircle = 2 * m_radius * P_NUMBER;
	m_areaOfCircle = P_NUMBER * m_radius * m_radius;
}

CCircle::CCircle(ÑPoint centre, double radius,
	std::string outlineColor, std::string fillColor)
	: m_centre(centre), m_radius(radius), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
	m_lengthOfCircle = 2 * m_radius * P_NUMBER;
	m_areaOfCircle = P_NUMBER * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return m_lengthOfCircle;
}

double CCircle::GetArea() const
{
	return m_areaOfCircle;
}

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
}

std::string CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CCircle::ToString() const
{
	std::string str;
	std::ostringstream  stream;
	stream << "Area: " << GetArea() << std::endl;
	stream << "OutlineColor: " << GetOutlineColor() << std::endl;
	stream << "FillColor: " << GetFillColor() << std::endl;
	stream << "Perimetr: " << GetPerimeter() << std::endl;
	stream << "Specificity: " << "Circle is round." << std::endl;

	return stream.str();
}

ÑPoint CCircle::GetCentre() const
{
	return m_centre;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

CCircle::~CCircle()
{
}
