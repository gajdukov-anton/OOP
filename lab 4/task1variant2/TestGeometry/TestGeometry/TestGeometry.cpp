// TestGeometry.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../geometry/geometry/CLineSegment.h"
#include "../../geometry/geometry/СPoint.h"
#include "../../geometry/geometry/CTriangle.h"
#include "../../geometry/geometry/CCircle.h"
#include "../../geometry/geometry/CRectangle.h"
#include "../../geometry/geometry/CommandForCreateShape.h"
#include "../../geometry/geometry/CGeometry.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool CompaireFiles(ifstream& file1, ifstream& file2);

TEST_CASE("CPoint test")
{
	СPoint x(12, 22);
	СPoint y(34, 2.5);
	СPoint z(22, 19.5);	
	z = y - x;
	CHECK(z.GetX() == 22.0);
	CHECK(z.GetY() == -19.5);
}

TEST_CASE("CLineSegment test")
{
	СPoint x(12, 22);
	СPoint y(34, 2.5);
	СPoint z(22, 19.5);
	CLineSegment blackLine(x, y);
	CHECK(blackLine.GetArea() == 0);
	CHECK(blackLine.GetPerimeter() == 0);
	CHECK(blackLine.GetFinishPoint() == y);
	CHECK(blackLine.GetStartPoint() == x);
	CHECK(blackLine.GetOutlineColor() == "black");
	CLineSegment redLine(x, y, "red");
	CHECK(redLine.GetOutlineColor() == "red");
}

TEST_CASE("CTriangle test")
{
	СPoint x(0, 0);
	СPoint y(10, 0);
	СPoint z(0, 10);
	CTriangle testTriangle(x, y, z);
	CHECK(testTriangle.GetArea() == 50.0);
	CHECK(testTriangle.GetFillColor() == "black");
	CHECK(testTriangle.GetOutlineColor() == "black");
	CHECK(testTriangle.GetVertex1() == x);
	CHECK(testTriangle.GetVertex2() == y);
	CHECK(testTriangle.GetVertex3() == z);
	CHECK(testTriangle.ToString() == "Triangle has only three vertex.");
	CTriangle testTriangle2(x, y, z, "red", "green");
	CHECK(testTriangle2.GetArea() == 50.0);
	CHECK(testTriangle2.GetFillColor() == "green");
	CHECK(testTriangle2.GetOutlineColor() == "red");
	CHECK(testTriangle2.GetVertex1() == x);
	CHECK(testTriangle2.GetVertex2() == y);
	CHECK(testTriangle2.GetVertex3() == z);
	CHECK(testTriangle2.ToString() == "Triangle has only three vertex.");
}

TEST_CASE("CCircle test")
{
	СPoint centre1(12, 32);
	СPoint zeroCentre(0, 0);
	CCircle testCircle(centre1, 4.0, "red", "blue");
	CHECK(testCircle.GetRadius() == 4.0);
	CHECK(testCircle.GetCentre() == centre1);
	CHECK(testCircle.GetArea() == 50.24);
	CHECK(testCircle.GetPerimeter() == 25.12);
	CHECK(testCircle.GetFillColor() == "blue");
	CHECK(testCircle.GetOutlineColor() == "red");
}

TEST_CASE("CRectangle test")
{
	СPoint leftTop(0, 10);
	СPoint rightTop(10, 10);
	СPoint leftBottom(0, 0);
	СPoint rightBottom(10, 0);
	CRectangle testRectangle(leftTop, rightTop, rightBottom, leftBottom);
	CHECK(testRectangle.GetFillColor() == "black");
	CHECK(testRectangle.GetOutlineColor() == "black");
	CHECK(testRectangle.GetHeight() == 10.0);
	CHECK(testRectangle.GetLeftTop() == leftTop);
	CHECK(testRectangle.GetRightBottom() == rightBottom);
	CHECK(testRectangle.GetWidth() == 10.0);
	CHECK(testRectangle.GetArea() == 100.0);
	CHECK(testRectangle.GetPerimeter() == 40.0);
}

TEST_CASE("FillVertex test")
{
	ifstream inputFile("test.txt");
	vector<double> vectorOfVertex;
	vector<double> result(4);
	vector<double> result1(2);
	vector<double> result2(1);
	result1[0] = 12.0;
	result1[1] = 23.0;
	result2[0] = 34.0;
	string color1, color2;
	result[0] = 1.0;
	result[1] = 2.0;
	result[2] = 3.0;
	result[3] = 4.0;
	CHECK(FillVertex(inputFile, vectorOfVertex, 2) == true);
	FillColors(inputFile, color1, color2);
	CHECK(color1 == "blue");
	CHECK(color2 == "black");
	CHECK(vectorOfVertex == result1);
	vectorOfVertex.clear();
	CHECK(FillVertex(inputFile, vectorOfVertex, 1) == true);
	FillColors(inputFile, color1, color2);
	CHECK(color1 == "green");
	CHECK(color2 == "black");
	CHECK(vectorOfVertex == result2);
	vectorOfVertex.clear();
	CHECK(FillVertex(inputFile, vectorOfVertex, 4) == true);
	FillColors(inputFile, color1, color2);
	CHECK(color1 == "black");
	CHECK(color2 == "yellow");
	CHECK(vectorOfVertex == result);
	vectorOfVertex.clear();
	CHECK(FillVertex(inputFile, vectorOfVertex, 4) == true);
	FillColors(inputFile, color1, color2);
	CHECK(color1 == "black");
	CHECK(color2 == "green");
	CHECK(vectorOfVertex == result);
	vectorOfVertex.clear();
	CHECK(FillVertex(inputFile, vectorOfVertex, 4) == true);
	FillColors(inputFile, color1, color2);
	CHECK(color1 == "black");
	CHECK(color2 == "blue");
	CHECK(vectorOfVertex == result);
	vectorOfVertex.clear();
	CHECK(FillVertex(inputFile, vectorOfVertex, 4) == true);
	FillColors(inputFile, color1, color2);
	CHECK(color1 == "");
	CHECK(color2 == "");
	vectorOfVertex.clear();
}

TEST_CASE("CGeometry test")
{
	ifstream inputFile("test2.txt");
	ofstream outputFile("output.txt");
	CGeometry testGeometry(inputFile, outputFile);
	testGeometry.HandleCommand();
	testGeometry.HandleCommand();
	testGeometry.HandleCommand();
	testGeometry.HandleCommand();
	testGeometry.GetMaxShape();
	testGeometry.GetMinShape();
	outputFile.close();
	ifstream result("result2.txt");
	ifstream outFile("output.txt");
	CHECK(CompaireFiles(outFile, result) == true);
}

bool CompaireFiles(ifstream& file1, ifstream& file2)
{
	char symbolFromFile1;
	char symbolFromFile2;
	cout << "lol";
	while (!file1.eof() || !file2.eof())
	{
		file1.get(symbolFromFile1);
		file2.get(symbolFromFile2);
		if (symbolFromFile1 != symbolFromFile2)
		{
			return false;
		}
	}
	return true;
}