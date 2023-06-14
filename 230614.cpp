#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Rectangle2D.h"
#include"Cirect2D.h"
#include"MyPoint.h"
int main()
{
	using namespace std;
	MyPoint d1(0, 0);
	MyPoint d2(10, 30.5);
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Cirect2D c1(4, 5, 10.5);
	cout << "d1과 d2사이의 거리 : " << d1.length(d2) << endl;
	cout << "contains(c1,d2) : " << contains(c1, d2) << endl;
	cout << "contains(r1,d2) : " << contains(r1, d2) << endl;
}

	//Q1. Rectangle2D 클래스 정의하라.
	/* 직사각형의 중심을 나타내는x,y 라는 두개의 double 데이터 필드,
	  -이에 대한 get 상수함수와set함수, 사각형의 변은 x,y축에
	   평행인 것으로 가정한다.
	  -double 데이터 필드 width,height 와 이에 대한 get 상수 함수와 set 함수
	  -(x,y)는 (0,0),width,height 는 모두1인 기본 직사각형을 생성하는
	   인수 없는 생성자
	  -지정된 x,y,width,height 로 직사각형을 생성하는 생성자
	  -직사각형의 면적을 반환하는 getAgree()상수 함수
	  -직사각형의 둘레를 반환하는 getPerimeter()상수 함수
	  -지정된 점(x,y)가 생성된 직사각형의 내부에 있을경우, true를 반환하는
	   contains(double x,double y)상수 함수
	  -지정된 점(x,y)가 생성된 직사각형의 내부에 있을경우, true를 반환하는
	   contains(const Rectangle2D &r)상수 함수
	  -지정된 점(x,y)가 생성된 직사각형의 중첩되는 경우, true를 반환하는
	   contains(const Rectangle2D &r)상수 함수
	클래스에 대한 UML 다이어그램을 그리고, 클래스를 구현하라.
	세 개의 Rectangle2D 객체 
	-r1(2,2,5.5,4.9),
	-r2(4,5,10.5,3.2),
	-r3(3,5,2.3,5.4)
	를 생성하고, r1의 면적과 둘레를 화면에 출력하며,r1.contains(r2),
	r1.overlaps(r3)의 결과를 화면에 출려하는 테스트 프로그램을 작성하라.
	*/

	/*using namespace std;
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.2);
	cout << "r1의 면적과둘레: " << r1.getArea() << " " << r1.getPerimeter()<<endl;
	cout << "r1.contains(r2): " << r1.contains(r2) << endl;
	cout << "r1.overlaps(r3): " << r1.overlaps(r3) << endl;
}*/