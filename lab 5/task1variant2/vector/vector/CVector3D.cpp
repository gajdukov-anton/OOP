#include "stdafx.h"
#include "CVector3D.h"

const double EPSILON = 0.001;

CVector3D::CVector3D()
{
	x = 0;
	y = 0;
	z = 0;
	m_lenght = 0;
}


CVector3D::CVector3D(double x0, double y0, double z0)
	:x(x0), y(y0), z(z0)
{
	m_lenght = sqrt(x * x + y * y + z * z);
}

double CVector3D::GetLength() const
{
	return m_lenght;
}

void CVector3D::Normalize()
{
	x *= 1.0 / m_lenght;
	y *= 1.0 / m_lenght;
	z *= 1.0 / m_lenght;
}

CVector3D const CVector3D::operator +(CVector3D const& otherVector) const
{
	return CVector3D(x + otherVector.x, y + otherVector.y, z + otherVector.z);
}

CVector3D const CVector3D::operator -(CVector3D const& otherVector) const
{
	return CVector3D(x - otherVector.x, y - otherVector.y, z - otherVector.z);
}

CVector3D const CVector3D::operator /(double scalar) const
{
	return CVector3D(x / scalar, y / scalar, z / scalar);
}

CVector3D const CVector3D::operator *(double scalar) const
{
	return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D const operator *(double scalar, CVector3D const& vector)
{
	return CVector3D(scalar * vector.x, scalar * vector.y, scalar * vector.z);
}

CVector3D const CVector3D::operator +=(CVector3D const& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;

	return *this;
}

CVector3D const CVector3D::operator -=(CVector3D const& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;

	return *this;
}

CVector3D const CVector3D::operator *=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;

	return *this;
}

CVector3D const CVector3D::operator /=(double scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;

	return *this;
}

CVector3D const CVector3D::operator -() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D const CVector3D::operator +() const
{
	return *this;
}

bool CVector3D::operator ==(CVector3D const& vector) const
{
	double differenceForX = x - vector.x;
	double differenceForY = y - vector.y;
	double differenceForC = z - vector.z;

	return (differenceForX < EPSILON) && (differenceForY < EPSILON) && (differenceForC < EPSILON);
}

bool CVector3D::operator !=(CVector3D const& vector) const
{
	return (x != vector.x) || (y != vector.y) || (z != vector.z);
}

std::ostream& operator <<(std::ostream& stream, CVector3D const& vector)
{
	stream << vector.x << ' ' << vector.y << ' ' << vector.z;
	return stream;
}

std::istream& operator >>(std::istream& stream, CVector3D& vector)
{
	double corX;
	double corY;
	double corZ;
	if (stream >> corX && stream >> corY && stream >> corZ)
	{
		vector = CVector3D(corX, corY, corZ);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}

CVector3D::~CVector3D()
{
}
