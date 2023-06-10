#pragma once
#include<iostream>

class cVector3
{
private:
	double x, y, z;
public:
	cVector3();
	cVector3(double x, double y, double z);
	~cVector3();

	bool operator==(cVector3& vec);
	bool operator!=(cVector3& vec);
	cVector3 operator+(cVector3& vec);
	cVector3 operator-(cVector3& vec);
	cVector3 operator*(double d);
	cVector3 operator/(double d);

	double length();
	cVector3 Normalize();

	double Dot(cVector3& v1, cVector3& v2);
	cVector3 Cross(cVector3& v1, cVector3& v2);
	double Angle(cVector3& v1, cVector3& v2);
	// : 위에 있는 함수들재정의
	double Dot(cVector3& v1);
	cVector3 Cross(cVector3& v1);
	double Angle(cVector3& v1);

	friend cVector3 operator*(double n, cVector3 vec);
	friend std::ostream& operator<<(std::iostream & os, const cVector3 & v);
};
