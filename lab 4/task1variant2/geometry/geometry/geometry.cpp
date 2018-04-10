// geometry.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ISolidShape.h"
#include "CRectangle.h"
#include <vector>
#include <iostream>
#include "СPoint.h"
#include "CCircle.h"

using namespace std;

int main()
{
	vector <ISolidShape *> geometryShape;
	СPoint x(0, 0);
	СPoint y(10, 0);
	СPoint z(0, 10);
	СPoint u(10, 10);
	CRectangle rectangle;
	geometryShape.push_back(new CRectangle());
	geometryShape.push_back(new CRectangle(x, y, z, u));
	geometryShape.push_back(new CCircle(x, 10));
	cout << geometryShape[0]->GetArea() << geometryShape[1]->GetArea() << geometryShape[2]->GetFillColor() ;
    return 0;
}

