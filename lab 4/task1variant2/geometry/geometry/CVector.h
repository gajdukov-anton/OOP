#pragma once
#include "ÑPoint.h"

class CVector
{
public:
	CVector(ÑPoint& startPoint, ÑPoint& finishPoint);
	CVector();
	~CVector();
	double GetX() const;
	double GetY() const;

private:
	double m_x = 0;
	double m_y = 0;
};

