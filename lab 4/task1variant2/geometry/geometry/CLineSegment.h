#pragma once
#include <string>
#include "IShape.h"
#include "�Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(�Point startPoint, �Point finishPoint, std::string outlineColor);
	CLineSegment(�Point startPoint, �Point finishPoint);
	double GetArea() const;
	double GetPerimeter() const;
	std::string ToString() const;
	std::string GetOutlineColor() const;
	�Point GetStartPoint() const;
	�Point GetFinishPoint() const;
	~CLineSegment();
private:
	�Point m_startPoint;
	�Point m_finishPoint;
	std::string m_outlineColor;
};

