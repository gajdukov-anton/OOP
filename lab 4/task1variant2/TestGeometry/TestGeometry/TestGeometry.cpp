// TestGeometry.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../geometry/geometry/CLineSegment.h"
#include "../../geometry/geometry/СPoint.h"
#include "../../geometry/geometry/CTriangle.h"
#include "../../geometry/geometry/CCircle.h"
#include "../../geometry/geometry/CRectangle.h"
#include <iostream>

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
	CCircle testCircle2;
	CHECK(testCircle2.GetRadius() == 10);
	CHECK(testCircle2.GetCentre() == zeroCentre);
	CHECK(testCircle2.GetFillColor() == "black");
	CHECK(testCircle2.GetOutlineColor() == "black");
	CHECK(testCircle2.ToString() == "Circle is round.");
	CHECK(testCircle2.GetArea() == 314.0);
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

