#include "stdafx.h"
#include "CFunction.h"

const char operationAdd = '+';
const char operationSub = '-';
const char operationMul = '*';
const char operationDiv = '/';

CFunction::CFunction(std::string name)
{
	nameOfFunction = name;
	resultOfFunction = NAN;
}


std::string CFunction::GetName() const
{
	return nameOfFunction;
}

double CFunction::GetResult() const
{
	return resultOfFunction;

}

double CFunction::PerformOperation(double argumentOne, double argumentTwo, char operation)
{
	if (operation == operationAdd)
		resultOfFunction = argumentOne + argumentTwo;
	if (operation == operationMul)
		resultOfFunction = argumentOne * argumentTwo;
	if (operation == operationSub)
		resultOfFunction = argumentOne - argumentTwo;
	if (operation == operationDiv)
	{
		if (argumentTwo != 0)
			resultOfFunction = argumentOne / argumentTwo;
		else
		{
			std::cout << "Division by zero." << std::endl;
			return 0;
		}
	}
	return resultOfFunction;
}

CFunction::~CFunction()
{
}
