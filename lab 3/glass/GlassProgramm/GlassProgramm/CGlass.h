#pragma once
class CGlass
{
public:
	CGlass(int capacity);

	~CGlass();

	int GetCapacity() const;

	int GetWaterAmount() const;

	int AddWater(int amount);

	int PourWater(int amount);

private:
	int m_capacity;
	int m_waterAmount;
};

