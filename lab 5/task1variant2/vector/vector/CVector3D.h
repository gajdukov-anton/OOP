#pragma once
#include <math.h>

class CVector3D
{
public:

	CVector3D();
	CVector3D(double x0, double y0, double z0);
	double GetLength() const;
	void Normalize();
	double x, y, z;
	CVector3D const operator +(CVector3D const& otherVector) const;
	CVector3D const operator -(CVector3D const& otherVector) const;
	CVector3D const operator /(double scalar) const;
	CVector3D const operator *(double scalar) const;
	CVector3D const operator +=(CVector3D const& vector);
	CVector3D const operator -=(CVector3D const& vector);
	CVector3D const operator *=(double scalar);
	CVector3D const operator /=(double scalar);
	CVector3D const operator -() const;
	CVector3D const operator +() const;
	bool operator ==(CVector3D const& vector) const;
	bool operator !=(CVector3D const& vector) const;


	~CVector3D();
private:
	double m_lenght;
	bool CompareDoubles(double A, double B);
};

CVector3D const operator *(double scalar, CVector3D const& vector);