#pragma once
#include "ISolidShape.h"
#include "�Point.h"
#include <sstream>

class CRectangle : public ISolidShape
{
public:
	CRectangle(�Point leftTop, �Point rightBottom);
	CRectangle(�Point leftTop, �Point rightBottom, std::string outlineColor, std::string fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	�Point GetLeftTop() const;
	�Point GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
	~CRectangle();
private:
	�Point m_leftTop;
	�Point m_rightBottom;
	double m_width = 0;
	double m_height = 0;
	double m_area = 0;
	double m_perimeter = 0;
	std::string m_outlineColor;
	std::string m_fillColor;
};

