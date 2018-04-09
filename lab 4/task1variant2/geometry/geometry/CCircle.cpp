#include "stdafx.h"
#include "CCircle.h"


CCircle::CCircle()
{
	m_radius = 10.0;
	m_outlineColor = "black";
	m_fillColor = "black";
	m_lengthOfCircle = 2 * m_radius * P_NUMBER;
	m_areaOfCircle = P_NUMBER * m_radius * m_radius;

}

CCircle::CCircle(ÑPoint centre, double radius)
	: m_centre(centre), m_radius(radius)
{
	m_outlineColor = "black";
	m_fillColor = "black";
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


void CCircle::FillCircleParameters()
{
	m_radius = 10.0;
	m_lengthOfCircle = 2 * m_radius * P_NUMBER;
	m_areaOfCircle = P_NUMBER * m_radius * m_radius;
	if (m_outlineColor == "")
	{
		m_outlineColor = "black";
	}
	if (m_fillColor == "")
	{
		m_fillColor = "black";
	}
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
	return "Circle is round.";
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
