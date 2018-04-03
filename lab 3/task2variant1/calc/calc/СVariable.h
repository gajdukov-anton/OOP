#pragma once
#include<string>

class �Variable
{
public:
	�Variable(std::string name);
	std::string GetName() const;
	double GetValue() const;
	double EditValue(double value);
	~�Variable();
private:
	std::string nameOfVariable;
	double valueOfVariable;
};

