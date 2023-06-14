#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int bin_search(const int a[], int n, int key)
/*
template<typename T>
void Swap(T& a, T& b);
template<typename T>
void Swap(T* a, T* b, int n);
void Show(int a[]);
const int Lim = 8;
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);
template<typename T>
void Swap(T& a, T& b);

struct job
{
	char name[40];
	double salary;
	int floor;
}
template<> void Swap<job>(job& j1, job& j2);
void Show(job& j);*/

int main()
{


}

	/*using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j = " << i << "," << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i,j = " << i << "," << j << ".\n";

	job sue = { "Susan Yaffee",73000.60,7 };
	job sidney = { "Sidney Taffee",78060.72,9 };
	cout << "job 교환 전:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "job 교환 후:\n";
	Show(sue);
	Show(sidney);
	return 0;
}
template<typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<> void Swap<job>(job& j1, job& j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}
void Sow(job& j)
{
	using namespace std;
	cout << j.name << ":(" << j.floor << "층에 거주)" << "$" << j.salary << endl;
}*/

	/*using namespace std;
	int i = 10, j = 20;
	cout << "i,j =" << i << "," << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i,j =" << i << "," << j << ".\n";

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,6,2,0,1,9,6,9 };
	cout << "원본 배열:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	cout << "교환된 배열:\n";
	Show(d1);
	Show(d2);
	return 0;
}

template<typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0;i < n;i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	using namespace std;
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4;i < Lim;i++)
		cout << a[i];
	cout << endl;
}*/

	/*using namespace std;
	char* trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;

	for (i = 1;i < 10;i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[]temp;
	}
	return 0;
}
unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++;
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
}
char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0;i < n && str[i];i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';
	return p;
}*/
	
	
	//참조 변수 생성 
	/*using namespace std;
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ",rodents = " << rodents << endl;
	rodents++;
	cout << "rats =" << rats;
	cout << ",rodents = " << rodents << endl;

	cout << "rats의 주소 = " << &rats;
	cout << ",rodents의 주소 = " << &rodents << endl;
	return 0;
}*/

    //원
	/*using namespace std;
	int r, x, y;
	int x0 = 0;
	int y0 = 0;
	cout << "input> r:";
	cin >> r;
	cout << "x :";
	cin >> x;
	cout << "y :";
	cin >> y;
	if (sqrt(pow(x - x0,2) + pow(y - y0, 2) <= r))
	{
		cout << "점 (" << x << "," << y << ")는 중점이 (0.0)이고 반지름이 " << r << "인 원 안에 있습니다";
	}
	else 
	{
		cout << "점 (" << x << "," << y << ")는 중점이 (0.0)이고 반지름이 " << r << "인 원 안에 없습니다";
	}
}*/
