#pragma once
#include <string>
#include "IShape.h"
#include "�Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(�Point startPoint, �Point finishPoint, std::string outlineColor);
	CLineSegment(�Point startPoint, �Point finishPoint);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	�Point GetStartPoint() const;
	�Point GetFinishPoint() const;
	~CLineSegment();
private:
	�Point m_startPoint;
	�Point m_finishPoint;
	�Point m_line;
	double m_lengthOfLine;
	std::string m_outlineColor;
};

