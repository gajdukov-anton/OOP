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
	std::istringstream stream(str);
	stream >> shape;

	shape = CheckStrForShape(shape);
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
		GetShapeMinPerimeter();
		return true;
	}
	if (shape == "GetMaxArea")
	{
		GetShapeMaxArea();
		return true;
	}
	cout << "Unknown command" << endl;
	return false;
}

bool CGeometry::AddCircle(std::istream& input)
{
	std::string outlineColor = "";
	std::string fillColor = "";
	double x;
	double y;
	double radius;

	input >> x >> y >> radius >> outlineColor >> fillColor;
	ÑPoint center(x, y);

	m_geometryShape.push_back(new CCircle(center, radius, outlineColor, fillColor));
	return true;
}

bool CGeometry::AddRectangle(std::istream& input)
{
	std::string outlineColor = "";
	std::string fillColor = "";
	double x;
	double y;
	input >> x >> y;
	ÑPoint leftTop(x, y);
	input >> x >> y;
	ÑPoint RightTop(x, y);
	input >> x >> y;
	ÑPoint LeftBottom(x, y);
	input >> x >> y >> outlineColor >> fillColor;
	ÑPoint RightBottom(x, y);

	m_geometryShape.push_back(new CRectangle(leftTop, RightTop, LeftBottom, RightBottom, outlineColor, fillColor));
	return true;
}

bool CGeometry::AddLineCegment(std::istream& input)
{
	std::string outlineColor = "";
	double x;
	double y;

	input >> x >> y;
	ÑPoint startPoint(x, y);
	input >> x >> y >> outlineColor;
	ÑPoint finishPoint(x, y);

	m_geometryShape.push_back(new CLineSegment(startPoint, finishPoint, outlineColor));
	return true;
}

bool CGeometry::AddTriangle(std::istream& input)
{
	std::string outlineColor = "";
	std::string fillColor = "";
	double x;
	double y;

	input >> x >> y;
	ÑPoint vertex1(x, y);
	input >> x >> y;
	ÑPoint vertex2(x, y);
	input >> x >> y >> outlineColor >> fillColor;
	ÑPoint vertex3(x, y);
	
	m_geometryShape.push_back(new CTriangle(vertex1, vertex2, vertex3, outlineColor, fillColor));
	return true;
}

bool CGeometry::GetShapeMaxArea() const
{
	if (m_geometryShape.empty())
	{
		cout << "There are not any shapes" << endl;
		return false;
	}
	auto GetMaxShape = [](const IShape * a, const IShape * b)
	{
		return a->GetArea() > b->GetArea();
	};
	auto shape = *std::min_element(m_geometryShape.begin(), m_geometryShape.end(), GetMaxShape);
	cout << "Shape with max area:" << shape->ToString() << ' ' << shape->GetArea() << endl;
	return true;
}

bool CGeometry::GetShapeMinPerimeter() const
{
	if (m_geometryShape.empty())
	{
		cout << "There are not any shapes" << endl;
		return false;
	}
	auto GetMinShape = [](const IShape * a, const IShape * b)
	{
		return a->GetPerimeter() < b->GetPerimeter();
	};
	auto shape = *std::min_element(m_geometryShape.begin(), m_geometryShape.end(), GetMinShape);
	cout << "Shape with max area:" << shape->ToString() << ' ' << shape->GetPerimeter() << endl;
	return true;
}

bool CGeometry::GetMaxShape() const
{
	if (m_geometryShape.empty())
	{
		cout << "There are not any shapes" << endl;
		return false;
	}
	auto GetMaxShape = [](const IShape * a, const IShape * b)
	{
		return a->GetArea() > b->GetArea();
	};
	auto shape = *std::min_element(m_geometryShape.begin(), m_geometryShape.end(), GetMaxShape);
	m_output << "Area: " << shape->GetArea() << endl;
	m_output << "OutlineColor: " << shape->GetOutlineColor() << endl;
	m_output << "Perimetr: " << shape->GetPerimeter() << endl;
	m_output << "Specificity: " << shape->ToString() << endl;
	return true;
}

bool CGeometry::GetMinShape() const
{
	if (m_geometryShape.empty())
	{
		cout << "There are not any shapes" << endl;
		return false;
	}
	auto GetMaxShape = [](const IShape * a, const IShape * b)
	{
		return a->GetPerimeter() < b->GetPerimeter();
	};
	auto shape = *std::min_element(m_geometryShape.begin(), m_geometryShape.end(), GetMaxShape);
	m_output << "Area: " << shape->GetArea() << endl;
	m_output << "OutlineColor: " << shape->GetOutlineColor() << endl;
	m_output << "Perimetr: " << shape->GetPerimeter() << endl;
	m_output << "Specificity: " << shape->ToString() << endl;
	return true;
}

CGeometry::~CGeometry()
{
	for (size_t i = 0; i < m_geometryShape.size(); i++)
		delete[] m_geometryShape[i];
}

