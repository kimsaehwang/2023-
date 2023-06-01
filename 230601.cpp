#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<crtdbg.h>
#include<fstream>
#include<cmath>
using namespace std;
/*
const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);
unsigned int c_in_str(const char* str, char ch);
struct polar
{
	double distance;
	double angle;
};
struct rect
{
	double x;
	double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);
double calculate(double x, double y);
double add(double x, double y);*/

int search(const int a[], int n, int key);
int main()
{
	int i,key;
	int a[100];
	
	cout << "배열의 크기 : ";
	cin >> i;
	cout << "검색값 : ";
	cin >> key;
	cout << "\n  ㅣ ";
	for (int j = 0;j < i;j++)
	{
		cout << j<<" ";
	}
	cout << "\n-----------------";
	cout << "\n  ㅣ ";
	cin >> a[i];
	int idx = search(a, i, key);
	if (idx == -1)
		cout << "검색에 실패했습니다.";
	else
		cout << key << "는 " << idx << "번째에 있습니다.";
	free(a);

	return 0;
}
int search(const int a[], int n, int key)
{
	int i = 0;
	while (1)
	{
		if (i == n)
			return -1;
		if (a[i] == key)
			return i;
		i++;
	}
}

	//p464 10번
	/*double a, b;
	cin >> a >> b;
	double q = calculate(a, b, add);
	double m = calculate(a, b, sub);
	cout << q;
	cout << m;
}
double add(double x, double y)
{
	return x + y;
}
double sub(double x, double y)
{
	return x - y;
}*/

	//함수 포인터
	/*double av[3] = { 1112.3,1542.6,2227.9 };

	const double* (*p1)(const double*, int) = f1;
	auto p2 = f2;
	cout << "함수 포인터: \n";
	cout << "주소 값\n";
	cout << (*p1)(av, 3) << ":" << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ":" << *p2(av, 3) << endl;

	const double* (*pa[3])(const double*, int) = { f1,f2,f3 };
	auto pb = pa;
	cout << "\n함수 포인터를 원소로 가지는 배열:\n";
	cout << "주소 값\n";
	for (int i = 0;i < 3;i++)
		cout << pa[i](av, 3) << ":" << *pa[i](av, 3) << endl;
	cout << "\n함수 포인터를 가리키는 포인터:\n";
	cout << "주소 값\n";
	for (int i = 0;i < 3;i++)
		cout << pb[i](av, 3) << ":" << *pb[i](av, 3) << endl;

	cout << "\n포인터를 원소로 가지는 배열을 가리키는 포인터:\n";
	cout << "주소 값\n";

	auto pc = &pa;
	cout << (*pc)[0](av, 3) << ":" << *(*pc)[0](av, 3) << endl;
	const double* (*(*pd)[3])(const double*, int) = &pa;
	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << ":" << *pdb << endl;
	cout << (*(*pd)[2])(av, 3) << ":" << *(*(*pd)[2])(av, 3) << endl;
	return 0;
}
const double* f1(const double* ar, int n)
{
	return ar;
}
const double* f2(const double ar[], int n)
{
	return ar + 1;
}
const double* f3(const double ar[], int n)
{
	return ar + 2;
}*/

	//재귀호출
	/*char ruler[Len];
	int i;
	for (i = 1;i < Len - 2;i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;
	for (i = 1;i <= Divs;i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1;j < Len - 2;j++)
			ruler[j] = ' ';
	}
	return 0;
}
void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}*/

	/*using namespace std;;
	rect rplace;
	polar pplace;

	cout << "x값과 y값을 입력하십시오: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "x값과 y값을 입력하십시오(끝내려면 q를입력):";
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}

polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;

	answer.distance =
		sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;
}
void show_polar(polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;

	cout << "거리 = " << dapos.distance;
	cout << ",각도 = " << dapos.angle * Rad_to_deg;
	cout << "도\n";
}*/

	/*using namespace std;
	char mmm[15] = "minimum";

	const char* wail = "ululate";

	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << mmm << "에는 m이" << ms << "개 들어있습니다.\n";
	cout << wail << "에는 u가" << us << "개 들어있습니다.\n";
	return 0;
}
unsigned int c_in_str(const char* str, char ch)
{
	int count = 0;

	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return count;
}*/

	//Q1.삼각형의 면적
	/*using namespace std;
	double x1, x2, x3, y1, y2, y3;
	double area;
	double a, b, c, s;
	cout << "세점 입력 :";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	a = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
	b = sqrt(pow(x3 - x2,2) + pow(y3 - y2,2));
	c = sqrt(pow(x3 - x1,2) + pow(y3 - y1,2));
	s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));	
	cout << "삼각형의 면적 : " << area;
}*/