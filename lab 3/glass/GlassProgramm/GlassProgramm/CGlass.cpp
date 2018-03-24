#include "stdafx.h"
#include "CGlass.h"


CGlass::CGlass(int capacity)
:m_capacity((capacity >= 0) ? capacity : 0)
,m_waterAmount(0)
{
}


CGlass::~CGlass()
{
}

int CGlass::GetCapacity() const
{
	return m_capacity;
}

int CGlass::GetWaterAmount() const
{
	return m_waterAmount;
}

int CGlass::AddWater(int amount)
{
	if (amount < 0)
	{
		amount = 0;
	}
	else if ((m_waterAmount + amount < m_waterAmount) || (m_waterAmount + amount > m_capacity))
	{
		amount = m_capacity - m_waterAmount;
	}

	m_waterAmount += amount;
	return amount;
}

int CGlass::PourWater(int amount)
{
	amount = (amount < 0) ? 0 : (m_waterAmount >= amount) ? amount : m_waterAmount;

	m_waterAmount -= amount;
	return amount;
}