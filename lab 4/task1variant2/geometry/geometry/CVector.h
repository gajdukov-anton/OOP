#pragma once
#include "�Point.h"

class CVector
{
public:
	CVector(�Point& startPoint, �Point& finishPoint);
	CVector();
	~CVector();
	double GetX() const;
	double GetY() const;

private:
	double m_x = 0;
	double m_y = 0;
};

