#include "stdafx.h"
#include "CLineSegment.h"
#include <iostream>
#include <sstream>


CLineSegment::CLineSegment(ÑPoint startPoint, ÑPoint finishPoint, std::string outlineColor)
	: m_startPoint(startPoint), m_finishPoint(finishPoint), m_outlineColor(outlineColor)
{
	m_line = m_finishPoint - m_startPoint;
	m_lengthOfLine = sqrt(m_line.GetX() * m_line.GetX() + m_line.GetY() * m_line.GetY());
}

CLineSegment::CLineSegment(ÑPoint startPoint, ÑPoint finishPoint)
	: m_startPoint(startPoint), m_finishPoint(finishPoint)
{
	m_line = m_finishPoint - m_startPoint;
	m_lengthOfLine = sqrt(m_line.GetX() * m_line.GetX() + m_line.GetY() * m_line.GetY());
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return m_lengthOfLine;
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

ÑPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

ÑPoint CLineSegment::GetFinishPoint() const
{
	return m_finishPoint;
}

std::string CLineSegment::ToString() const
{
	std::string str;
	std::ostringstream  stream;
	stream << "Area: " << GetArea() << std::endl;
	stream << "OutlineColor: " << GetOutlineColor() << std::endl;
	stream << "Perimetr: " << GetPerimeter() << std::endl;
	stream << "Specificity: " << "The shape of CLineSergment type can't have perimeter and area." << std::endl;

	return stream.str();
}

CLineSegment::~CLineSegment()
{
}
