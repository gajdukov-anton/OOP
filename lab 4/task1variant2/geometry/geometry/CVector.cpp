#include "stdafx.h"
#include "CVector.h"


CVector::CVector()
{
	m_x = 0.0;
	m_y = 0.0;
}

CVector::CVector(ÑPoint& startPoint, ÑPoint& finishPoint)
{
	m_x = finishPoint.GetX() - startPoint.GetX();
	m_y = finishPoint.GetY() - startPoint.GetY();
}

double CVector::GetX() const
{
	return m_x;
}

double CVector::GetY() const
{ 
	return m_y;
}


CVector::~CVector()
{
}
