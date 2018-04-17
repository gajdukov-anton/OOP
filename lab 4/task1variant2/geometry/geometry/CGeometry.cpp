#include "stdafx.h"
#include "CGeometry.h"
#include "CommandForCreateShape.h"
#include <algorithm>



CGeometry::CGeometry(std::istream& input, std::ostream& output)
	:m_input(input), m_output(output)
{
}

bool CGeometry::HandleCommand()
{
	std::string shape;
	std::string str;
	getline(m_input, str);
	if (m_input.eof() && str.size() == 0)
	{
		return true;
	}
	std::istringstream stream(str);
	stream >> shape;
	if (shape == "Circle")
	{
		AddCircle(stream);
		return true;
	}
	if (shape == "LineSegment")
	{
		AddLineCegment(stream);
		return true;
	}
	if (shape == "Triangle")
	{
		AddTriangle(stream);
		return true;
	}
	if (shape == "Rectangle")
	{
		AddRectangle(stream);
		return true;
	}
	if (shape == "GetMinPerimetr")
	{
		GetMinPerimeter();
		return true;
	}
	if (shape == "GetMaxArea")
	{
		GetMaxArea();
		return true;
	}

	m_output << "Unknown command"  <<  endl;
	return false;
}

bool CGeometry::StringToDouble(std::string strWithNumber, double& number)
{
	std::string zeroStr = "0.0";
	number = strtod(strWithNumber.c_str(), nullptr);
	if (number == 0.0)
	{
		if (strWithNumber != zeroStr)
		{
			return false;
		}
	}
	return true;
}

bool CGeometry::isColor(std::string& color)
{
	std::regex regex(R"(^([A-Fa-f0-9]){6}?)");
	std::smatch result;
	if (!std::regex_match(color, result, regex) && color != "")
	{
		return false;
	}

	return true;
}

bool CGeometry::AddCircle(std::istream& input)
{
	std::string outlineColor = "";
	std::string fillColor = "";
	std::string strNumber;
	std::vector<double> vectorOfCoordinate(3);
	for (size_t i = 0; i < vectorOfCoordinate.size(); i++)
	{
		if (!(input >> strNumber))
		{
			m_output << "Not enough coordinates to create a shape" << endl;
			return false;
		}
		if (!StringToDouble(strNumber, vectorOfCoordinate[i]))
		{
			m_output << "Invalid type of coordinate" << endl;
			return false;
		}
	}
	ÑPoint center(vectorOfCoordinate[0], vectorOfCoordinate[1]);
	input >> outlineColor >> fillColor;

	if (!(isColor(outlineColor) && isColor(fillColor)))
	{
		m_output << "Undefine color" << endl;
		return false;
	}
	if (outlineColor == "" && fillColor == "")
	{
		m_geometryShape.push_back(new CCircle(center, vectorOfCoordinate[2]));
	}
	else
	{
		m_geometryShape.push_back(new CCircle(center, vectorOfCoordinate[2], outlineColor, fillColor));
	}
	return true;
}

bool CGeometry::AddRectangle(std::istream& input)
{
	std::string outlineColor = "";
	std::string fillColor = "";
	std::string strNumber;
	std::vector<double> vectorOfCoordinate(8);
	
	for (size_t i = 0; i < vectorOfCoordinate.size(); i++)
	{
		if (!(input >> strNumber))
		{
			m_output << "Òot enough coordinates to create a shape" << endl;
			return false;
		}
		if (!StringToDouble(strNumber, vectorOfCoordinate[i]))
		{
			m_output << "Invalid type of coordinate" << endl;
			return false;
		}
	}
	ÑPoint leftTop(vectorOfCoordinate[0], vectorOfCoordinate[1]);
	ÑPoint RightTop(vectorOfCoordinate[2], vectorOfCoordinate[3]);
	ÑPoint LeftBottom(vectorOfCoordinate[4], vectorOfCoordinate[5]);
	ÑPoint RightBottom(vectorOfCoordinate[6], vectorOfCoordinate[7]);
	input >> outlineColor >> fillColor;
	if (!(isColor(outlineColor) && isColor(fillColor)))
	{
		m_output << "Undefine color" << endl;
		return false;
	}
	if (outlineColor == "" && fillColor == "")
	{
		m_geometryShape.push_back(new CRectangle(leftTop, RightTop, LeftBottom, RightBottom));
	}
	else
	{
		m_geometryShape.push_back(new CRectangle(leftTop, RightTop, LeftBottom, RightBottom, outlineColor, fillColor));
	}
	return true;
}

bool CGeometry::AddLineCegment(std::istream& input)
{
	std::string outlineColor = "";
	std::string strNumber;
	std::vector<double> vectorOfCoordinate(4);

	for (size_t i = 0; i < vectorOfCoordinate.size(); i++)
	{
		if (!(input >> strNumber))
		{
			m_output << "Òot enough coordinates to create a shape" << endl;
			return false;
		}
		if (!StringToDouble(strNumber, vectorOfCoordinate[i]))
		{
			m_output << "Invalid type of coordinate" << endl;
			return false;
		}
	}
	input >> outlineColor;
	ÑPoint startPoint(vectorOfCoordinate[0], vectorOfCoordinate[1]);
	ÑPoint finishPoint(vectorOfCoordinate[2], vectorOfCoordinate[3]);

	if (!(isColor(outlineColor)))
	{
		m_output << "Undefine color" << endl;
		return false;
	}
	if (outlineColor == "")
	{
		m_geometryShape.push_back(new CLineSegment(startPoint, finishPoint));
	}
	else
	{
		m_geometryShape.push_back(new CLineSegment(startPoint, finishPoint, outlineColor));
	}
	return true;
}

bool CGeometry::AddTriangle(std::istream& input)
{
	std::string outlineColor = "";
	std::string fillColor = "";
	std::string strNumber;
	std::vector<double> vectorOfCoordinate(6);

	for (size_t i = 0; i < vectorOfCoordinate.size(); i++)
	{
		if (!(input >> strNumber))
		{
			m_output << "Òot enough coordinates to create a shape" << endl;
			return false;
		}
		if (!StringToDouble(strNumber, vectorOfCoordinate[i]))
		{
			m_output << "Invalid type of coordinate" << endl;
			return false;
		}
	}
	ÑPoint vertex1(vectorOfCoordinate[0], vectorOfCoordinate[1]);
	ÑPoint vertex2(vectorOfCoordinate[2], vectorOfCoordinate[3]);
	ÑPoint vertex3(vectorOfCoordinate[4], vectorOfCoordinate[5]);
	input >> outlineColor >> fillColor;

	if (!(isColor(outlineColor) && isColor(fillColor)))
	{
		m_output << "Undefine color" << endl;
		return false;
	}
	if (outlineColor == "" && fillColor == "")
	{
		m_geometryShape.push_back(new CTriangle(vertex1, vertex2, vertex3));
	}
	else
	{
		m_geometryShape.push_back(new CTriangle(vertex1, vertex2, vertex3, outlineColor, fillColor));

	}
	return true;
}

IShape* CGeometry::FindShapeMaxArea() const
{
	if (m_geometryShape.empty())
	{
		m_output << "There are not any shapes" << endl;
		return nullptr;
	}
	auto GetMaxShape = [](const IShape * a, const IShape * b)
	{
		return a->GetArea() > b->GetArea();
	};
	IShape* shape = *std::min_element(m_geometryShape.begin(), m_geometryShape.end(), GetMaxShape);
	return shape;
}

IShape* CGeometry::FindShapeMinPerimetr() const
{
	if (m_geometryShape.empty())
	{
		m_output << "There are not any shapes" << endl;
		return nullptr;
	}
	auto GetMinShape = [](const IShape * a, const IShape * b)
	{
		return a->GetPerimeter() < b->GetPerimeter();
	};
	IShape* shape = *std::min_element(m_geometryShape.begin(), m_geometryShape.end(), GetMinShape);
	return shape;
}

bool CGeometry::GetMaxArea() const
{
	IShape* shape = FindShapeMaxArea();
	if (shape != nullptr)
	{
		m_output << shape->GetArea() << endl;
		return true;
	}
	m_output << 0 << endl;
	return false;
}

bool CGeometry::GetMinPerimeter() const
{
	IShape* shape = FindShapeMinPerimetr();
	if (shape != nullptr)
	{
		m_output << shape->GetPerimeter() << endl;
		return true;
	}
	m_output << 0 << endl;
	return false;
}

bool CGeometry::GetMaxShape() const
{
	IShape* shape = FindShapeMaxArea();
	if (shape != nullptr)
	{
		m_output << shape->ToString();
		return true;
	}
	return false;
}

bool CGeometry::GetMinShape() const
{
	IShape* shape = FindShapeMinPerimetr();
	if (shape != nullptr)
	{
		m_output << shape->ToString();
		return true;
	}
	return false;
}

CGeometry::~CGeometry()
{
	for (size_t i = 0; i < m_geometryShape.size(); i++)
		delete[] m_geometryShape[i];
}

