#include "stdafx.h"
#include "ÑVariable.h"


ÑVariable::ÑVariable(std::string name)
{
	nameOfVariable = name;
	valueOfVariable = NAN;
}

std::string ÑVariable::GetName() const
{
	return nameOfVariable;
}


double ÑVariable::GetValue() const
{
	return valueOfVariable;
}

double ÑVariable::EditValue(double value)
{
	valueOfVariable = value;
	return valueOfVariable;
}

ÑVariable::~ÑVariable()
{
}
