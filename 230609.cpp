#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "cVector.h"

//연산자 오버로딩
/*
Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::Sum(const Time& t)const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

void Time::Show()const
{
	std::cout << hours << "시간, " << minutes << "분";
}
*/
int main()
{
	//Q2. 벡터 클래스를 구현하라.
	/*
	class cVector3
	{
		// : 멤버변수
		// : 생성자
		// : 소멸자
		public :
		// : 연산자 오버로딩
			== , != , + , - , = , * , /
			<<
		// : 멤버 함수
		double length() ; // 벡터 길이
		cVector3 normalize() ; // : 단위벡터

		//
		double dot(cVector3 & v1, cVector3 & v2);
		cVector3 cross(cVector3 & v1, cVector3 & v2);
		double angle(cVector3 & v1, cVector3 & v2);
	};

	ex > v1 x,y,z : 1 2 3
		 v2 x,y,z : -4 -5 6
		 v1 length : 3.74166
		 v2 length : 8.77496
		 v1 에 3 을 곱 : 3 6 9
		 v2 에 2 를 나눔 : -2 -2.5 3
		 두 벡터의 dot   : xx
		 두 벡터의 cross : 27 -18 3
		 두 벡터의 사이각 : 83.0023
	*/
	using namespace std;
	double x, y, z;
	cout << "> v1 x, y, z : ";
	cin >> x >> y >> z;
	cVector v1(x, y, z);
	cout << "> v2 x, y, z : ";
	cin >> x >> y >> z;
	cVector v2(x, y, z);
	cout << "v1 length : " << v1.length() <<endl;
	cout << "v2 length : " << v2.length() <<endl;
	cout << "v1에 3을 곱 : " << v1 * 3 << endl;
	cout << "v2에 2로 나눔 : " << v2 / 2 << endl;
	cout << "두 벡터의 Dot : " << v1.Dot(v2) << endl;
	cout << "두 벡터의 Cross : "<< v1.Cross(v2) << endl;
	cout << "두 벡터의 사이각 : "<< v1.Angle(v2) << endl;
}
	//연산자 오버로딩
	/*using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.Show();
	cout << endl;

	return 0;
}*/

	//Q1. n을 입력받아 다음과 같이 2^n 형태의 값들로 출력하는 프로그램을 작성
	/*ex > n = 3
				1
			1	2	1
		1	2	4	2	1
	1	2	4	8	4	2	1
	
	using namespace std;
	int n;
	cout << "n = ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j =0; j < n-i;j++)
		{
			cout << "  ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << pow(2, j) << " ";
		}
		for (int j = i-1; j >= 0; j--)
		{
			cout << pow(2,j) <<" ";
		}
		cout << endl;
	}
}*/
