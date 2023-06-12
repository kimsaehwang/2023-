#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846
#include<iostream>
#include<cmath>
#include "cvector.h"
//Q2. ���� Ŭ������ �����϶�.
	/*
	class cVector3
	{
		// : �������
		// : ������
		// : �Ҹ���
		public :
		// : ������ �����ε�
			== , != , + , - , = , * , /
			<<
		// : ��� �Լ�
		double length() ; // ���� ����
		cVector3 normalize() ; // : ��������

		//
		double dot(cVector3 & v1, cVector3 & v2);
		cVector3 cross(cVector3 & v1, cVector3 & v2);
		double angle(cVector3 & v1, cVector3 & v2);
	};

	ex > v1 x,y,z : 1 2 3
		 v2 x,y,z : -4 -5 6
		 v1 length : 3.74166
		 v2 length : 8.77496
		 v1 �� 3 �� �� : 3 6 9
		 v2 �� 2 �� ���� : -2 -2.5 3
		 �� ������ dot   : xx
		 �� ������ cross : 27 -18 3
		 �� ������ ���̰� : 83.0023
	*/


cVector::cVector()
{
	x = y = z = 0.0;
}
cVector::cVector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
cVector::~cVector() 
{
}

bool cVector::operator==(cVector& vec)
{
	if (x == vec.x && y == vec.y && z == vec.z)
		return true;
    return false;
}

bool cVector::operator!=(cVector& vec)
{
	if (x == vec.x && y == vec.y && z == vec.z)
		return false;
    return true;
}

cVector cVector::operator+(cVector& vec)
{
	return cVector(x + vec.x, y + vec.y, z + vec.z);
}

cVector cVector::operator-(cVector& vec)
{
    return cVector(x - vec.x, y - vec.y, z - vec.z);
}

cVector cVector::operator*(double d)
{
	return cVector(x * d, y * d, z * d);
}

cVector cVector::operator/(double d)
{
	return cVector(x / d, y / d, z / d);
}

double cVector::length()
{

	return sqrt(x * x + y * y + z * z);
}

cVector cVector::Normalize()
{
	return cVector(x / length(), y / length(), z / length());
}

double cVector::Dot(cVector& v1)
{
	return x * v1.x + y * v1.y + z * v1.z;
}

cVector cVector::Cross(cVector& v1)
{
    return cVector(y*v1.z - z*v1.y,z*v1.x-x*v1.z,x*v1.y-y*v1.x);
}

double cVector::Angle(cVector& v1)
{
	return acos(this -> Dot(v1) / (v1.length() * this -> length())) * 180 / M_PI;
}

cVector operator*(double n, cVector vec)
{
	return cVector(n * vec.x, n * vec.y, n * vec.z);
}

std::ostream& operator<<(std::ostream& os, const cVector& v)
{
	os << v.x << "," << v.y << "," << v.z;
	return os;
}
