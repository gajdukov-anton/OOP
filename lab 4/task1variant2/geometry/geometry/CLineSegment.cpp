#include "stdafx.h"
#include "CLineSegment.h"
#include <iostream>
#include <sstream>


CLineSegment::CLineSegment(�Point startPoint, �Point finishPoint, std::string outlineColor)
	: m_startPoint(startPoint), m_finishPoint(finishPoint), m_outlineColor(outlineColor)
{
	m_line = m_finishPoint - m_startPoint;
	m_lengthOfLine = sqrt(m_line.GetX() * m_line.GetX() + m_line.GetY() * m_line.GetY());
}

CLineSegment::CLineSegment(�Point startPoint, �Point finishPoint)
	: m_startPoint(startPoint), m_finishPoint(finishPoint)
{
	m_outlineColor = "black";
	m_line = m_finishPoint - m_startPoint;
	m_lengthOfLine = sqrt(m_line.GetX() * m_line.GetX() + m_line.GetY() * m_line.GetY());
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return 0;
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

�Point CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

�Point CLineSegment::GetFinishPoint() const
{
	return m_finishPoint;
}

std::string CLineSegment::ToString() const
{

	return "The shape of CLineSergment type can't have perimeter and area.";
}

CLineSegment::~CLineSegment()
{
}
