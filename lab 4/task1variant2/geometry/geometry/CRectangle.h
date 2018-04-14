#pragma once
#include "ISolidShape.h"
#include "ÑPoint.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(ÑPoint leftTop, ÑPoint rightTop, ÑPoint rightBottom, ÑPoint leftBottom);
	CRectangle(ÑPoint leftTop, ÑPoint rightTop, ÑPoint rightBottom, 
		ÑPoint leftBottom, std::string outlineColor, std::string fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	ÑPoint GetLeftTop() const;
	ÑPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
	~CRectangle();
private:
	ÑPoint m_leftTop;
	ÑPoint m_rightTop;
	ÑPoint m_leftBottom;
	ÑPoint m_rightBottom;
	double m_width = 0;
	double m_height = 0;
	double m_area = 0;
	double m_perimeter = 0;
	std::string m_outlineColor = "";
	std::string m_fillColor = "";
	ÑPoint m_vectorWidth;
	ÑPoint m_vectroHeight;
};

