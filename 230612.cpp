#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"cVector.h"
#include"Cirect2D.h"

int main()
{
	using namespace std;
	Cirect2D c1(2, 2, 5.5);
	Cirect2D c2(2, 2, 5.5);
	Cirect2D c3(4, 5, 10.5);
	cout << "c1의 면적: " << c1.getArea() << endl;
	cout << "c1의 둘레: " << c1.getPerimeter() << endl;
	cout << "c1.contains(3,3): " << c1.contains(3, 3) << endl;
	cout << "c1.contains(c2): " << c1.contains(c2) << endl;
	cout << "c1.overlaps(c3): " << c1.overlaps(c3) << endl;
}
	//벡터 연산 구하기
	/*cVector u(-1, 3, 2);
	cVector v(3, -4, 1);
	cVector x = 3 * u;
	cVector y = 2 * v;
	cVector z = -2 * u;
	cout << "1\n" << "(a)u + v : " << u + v << endl;
	cout << "(b) u - v : " << u - v << endl;
	cout << "(c) 3u + 2v : " << x + y << endl;
	cout << "(d) -2u + v : " << z + v << endl;
	cout << "2\n" << "u를 정규화 : " << u.Normalize() << endl;
	cout << "v를 정규화 : " << v.Normalize() << endl;
	cVector u1(1, 1, 1);
	cVector u2(1, 1, 0);
	cVector u3(-1, -1, -1);
	cVector v1(2, 3, 4);
	cVector v2(-2, 2, 0);
	cVector v3(3, 1, 0);
	cout << "3\n" << "(a) u = (1, 1, 1), v = (2, 3, 4) : " << u1.Angle(v1) << endl;
	cout << "(a) u = (1, 1, 0), v = (-2, 2, 0) : " << u2.Angle(v2) << endl;
	cout << "(a) u = (-1, -1, -1), v = (3, 1, 0) : " << u3.Angle(v3) << endl;
	cVector A(0, 0, 0);
	cVector B(0, 1, 3);
	cVector C(5, 1, 0);
	cout << "4\n" << B.Cross(C);
}*/