#include "stdafx.h"
#include "�Variable.h"


�Variable::�Variable(std::string name)
{
	nameOfVariable = name;
	valueOfVariable = NAN;
}

std::string �Variable::GetName() const
{
	return nameOfVariable;
}


double �Variable::GetValue() const
{
	return valueOfVariable;
}

double �Variable::EditValue(double value)
{
	valueOfVariable = value;
	return valueOfVariable;
}

�Variable::~�Variable()
{
}
