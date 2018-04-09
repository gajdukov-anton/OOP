#pragma once
#include <string>
#include "IShape.h"
#include "ÑPoint.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(ÑPoint startPoint, ÑPoint finishPoint, std::string outlineColor);
	CLineSegment(ÑPoint startPoint, ÑPoint finishPoint);
	double GetArea() const;
	double GetPerimeter() const;
	std::string ToString() const;
	std::string GetOutlineColor() const;
	ÑPoint GetStartPoint() const;
	ÑPoint GetFinishPoint() const;
	~CLineSegment();
private:
	ÑPoint m_startPoint;
	ÑPoint m_finishPoint;
	std::string m_outlineColor;
};

