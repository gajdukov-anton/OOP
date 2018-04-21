#pragma once
#include <string>
#include "IShape.h"
#include "ÑPoint.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(ÑPoint startPoint, ÑPoint finishPoint, std::string outlineColor);
	CLineSegment(ÑPoint startPoint, ÑPoint finishPoint);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	ÑPoint GetStartPoint() const;
	ÑPoint GetFinishPoint() const;
	~CLineSegment();
private:
	ÑPoint m_startPoint;
	ÑPoint m_finishPoint;
	ÑPoint m_line;
	double m_lengthOfLine;
	std::string m_outlineColor;
};

