#pragma once
#include<string>

class ÑVariable
{
public:
	ÑVariable(std::string name);
	std::string GetName() const;
	double GetValue() const;
	double EditValue(double value);
	~ÑVariable();
private:
	std::string nameOfVariable;
	double valueOfVariable;
};

