#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "cVector.h"

//������ �����ε�
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
	std::cout << hours << "�ð�, " << minutes << "��";
}
*/
int main()
{
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
	cout << "v1�� 3�� �� : " << v1 * 3 << endl;
	cout << "v2�� 2�� ���� : " << v2 / 2 << endl;
	cout << "�� ������ Dot : " << v1.Dot(v2) << endl;
	cout << "�� ������ Cross : "<< v1.Cross(v2) << endl;
	cout << "�� ������ ���̰� : "<< v1.Angle(v2) << endl;
}
	//������ �����ε�
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

	//Q1. n�� �Է¹޾� ������ ���� 2^n ������ ����� ����ϴ� ���α׷��� �ۼ�
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
