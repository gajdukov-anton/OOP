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

class CGeometry
{
public:
	CGeometry();

	bool AddGeometryShape() const;
	IShape* GetShapeMaxArea() const;
	IShape* GetShapeMinPerimeter() const;
	~CGeometry();
private:
	std::vector <IShape *> geometryShape;

};

