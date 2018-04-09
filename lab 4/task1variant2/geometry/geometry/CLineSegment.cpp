#include "stdafx.h"
#include "CLineSegment.h"
#include <iostream>
#include <sstream>


CLineSegment::CLineSegment(�Point startPoint, �Point finishPoint, std::string outlineColor)
	: m_startPoint(startPoint), m_finishPoint(finishPoint), m_outlineColor(outlineColor)
{
}

CLineSegment::CLineSegment(�Point startPoint, �Point finishPoint)
	: m_startPoint(startPoint), m_finishPoint(finishPoint)
{
	m_outlineColor = "black";
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

	return "The shape of CLineSergment type can't have perimeter and area.\n";
}

CLineSegment::~CLineSegment()
{
}
