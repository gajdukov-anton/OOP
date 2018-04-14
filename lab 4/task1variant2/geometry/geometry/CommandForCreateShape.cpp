#include "stdafx.h"
#include "CommandForCreateShape.h"


using namespace std;

const string SHAPE_RECTANGLE = "Rectangle";
const string SHAPE_TRIANGLE = "Triangle";
const string SHAPE_CIRCLE = "Circle";
const string SHAPE_LINE_SEGMENT = "LineSegment";
const string GET_MAX_ARE = "GetMaxArea";
const string GET_MIN_PERIMETR = "GetMinPerimetr";

string CheckStrForShape(string strForCheck)
{
	if (strForCheck == SHAPE_RECTANGLE)
	{
		return "Rectangle";
	}
	if (strForCheck == SHAPE_CIRCLE)
	{
		return "Circle";
	}
	if (strForCheck == SHAPE_TRIANGLE)
	{
		return "Triangle";
	}
	if (strForCheck == SHAPE_LINE_SEGMENT)
	{
		return "LineSegment";
	}
	if (strForCheck == GET_MAX_ARE)
	{
		return "GetMaxArea";
	}
	if (strForCheck == GET_MIN_PERIMETR)
	{
		return "GetMinPerimetr";
	}
	return "";
}

bool FillVertex(istream& input, vector<double>& vectorOfVertex, size_t amountOfVertex)
{
	double vertex;
	size_t i = 0;
	while (i < amountOfVertex)
	{
		if (input >> vertex)
		{
			vectorOfVertex.push_back(vertex);
		}
		else
		{
			break;
		}
		i++;
	}
	cout << i << endl;
	if (i != amountOfVertex)
	{
		cout << "There aren't enough vertex to create a shape." << endl;
		return false;
	}
	return true;
}

void FillColors(istream& input, string& outlineColor, string& fillColor)
{
	outlineColor = "";
	fillColor = "";
	if (!input.eof())
	{
		input >> outlineColor;
	}
	if (!input.eof())
	{
		input >> fillColor;
	}
}
