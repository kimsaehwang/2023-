#pragma once

class cVector
{
private:
	double x, y, z;
public:
	cVector();
	cVector(double x, double y, double z);
	~cVector();

	bool operator==(cVector& v);
	bool operator!=(cVector& v);
	cVector operator+(cVector& v);
	cVector operator-(cVector& v);
	cVector operator*(double d);
	cVector operator/(double d);

	double length();
	cVector Normalize();

	double Dot(cVector& v1, cVector& v2);
	cVector Cross(cVector& v1, cVector& v2);
	double Angle(cVector& v1, cVector& v2);
	// : 위에 있는 함수들재정의
	double Dot(cVector& v1);
	cVector Cross(cVector& v1);
	double Angle(cVector& v1);

	friend cVector operator*(double n, cVector vec);
	friend std::ostream& operator<<(std::ostream & os, const cVector & v);
};
