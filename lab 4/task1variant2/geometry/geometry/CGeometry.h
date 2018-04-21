#pragma once

#include "ISolidShape.h"
#include "IShape.h"
#include "ÑPoint.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <sstream>


class CGeometry
{
public:
	CGeometry(std::istream& input, std::ostream& output);
	bool HandleCommand();
	bool GetMaxShape() const;
	bool GetMinShape() const;
	bool StringToDouble(std::string strWithNumber, double& number);
	~CGeometry();
private:
	std::istream& m_input;
	std::ostream& m_output;
	std::vector <IShape *> m_geometryShape;
	bool IsColor(std::string& color);
	bool AddCircle(std::istream& input);
	bool AddRectangle(std::istream& input);
	bool AddTriangle(std::istream& input);
	bool AddLineCegment(std::istream& input);
	bool ReadVectorOfNumbers(std::istream& input, std::vector<double>& vectorOfNumbers);
	bool GetMaxArea() const;
	bool GetMinPerimeter() const;
	IShape* FindShapeMaxArea() const;
	IShape* FindShapeMinPerimetr() const;
};

