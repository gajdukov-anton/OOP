#pragma once
#include <string>
#include <math.h>
#include <iostream>


class CFunction
{
public:
	CFunction(std::string name);
	std::string GetName() const;
	double GetResult() const;
	double PerformOperation(double argumentOne, double argumentTwo, char operation);
	~CFunction();
private:
	std::string nameOfFunction;
	double resultOfFunction;
};

