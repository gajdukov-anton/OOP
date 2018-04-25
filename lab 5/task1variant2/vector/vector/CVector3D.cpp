#include "stdafx.h"
#include "CVector3D.h"

const double EPSILON = 0.001;

CVector3D::CVector3D()
{
	x = 0;
	y = 0;
	z = 0;
	m_length = 0;
}


CVector3D::CVector3D(double x0, double y0, double z0)
	:x(x0), y(y0), z(z0)
{
	m_length = sqrt(x * x + y * y + z * z);
}

double CVector3D::GetLength() const
{
	return m_length;
}

void CVector3D::Normalize()
{
	x *= 1.0 / m_length;
	y *= 1.0 / m_length;
	z *= 1.0 / m_length;
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
	if (scalar == 0)
	{
		throw std::invalid_argument("the scalar must be >= 0");
	}
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
	if (scalar == 0)
	{
		throw std::invalid_argument("the scalar must be >= 0");
	}
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
	double differenceForX = x - vector.x;
	double differenceForY = y - vector.y;
	double differenceForC = z - vector.z;

	return (differenceForX > EPSILON) || (differenceForY > EPSILON) || (differenceForC > EPSILON);
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

CVector3D Normalize(CVector3D const& vector)
{
	double length = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z + vector.z);
	return CVector3D(vector.x / length, vector.y / length, vector.z / length);
}

double DotProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z);
}

CVector3D CrossProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	return CVector3D((vector1.y * vector2.z - vector1.z * vector2.y), (vector1.z * vector2.x - vector1.x * vector2.z), (vector1.x * vector2.y - vector1.y * vector2.x));
}

CVector3D::~CVector3D()
{
}
