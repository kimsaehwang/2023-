#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<string>
#include <new>
/*
const int BUF = 512;
const int N = 5;
char buffer[BUF];
*/


int main()
{
	//두 원의관계
	/*using namespace std;
	double x, y, r;
	double x1, y1, r1;
	double Distance;
	cout << "첫 번째 원 x,y,r : ";
	cin >> x >> y >> r;
	cout << "두 번째 원 x,y,r : ";
	cin >> x1 >> y1 >> r1;
	Distance = pow(x1 - x, 2) + pow(y1 - y, 2);
	Distance = sqrt(Distance);
	if (r - r1 >= Distance)
	{
		cout << "두 번째 원은 첫번째원 내부에 있다.";
	}
	else if (r + r1 > Distance)
	{
		cout << "두 번째 원은 첫번째원과 겹친다.";
	}
	else
	{
		cout << "두 번째 원은 첫번째원 외부에 있다.";
	}
}*/

	//위치지정new연산자
	/*using namespace std;

	double* pd1, * pd2;
	int i;
	cout << "new와 위치 지정 new의 첫번째 호출:\n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N];
	for (i = 0;i < N;i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "메모리 주소:\n" << pd1 << " :힙; "
		<< (void*)buffer << " : 정적" << endl;
	cout << "메모리 내용:\n";
	for (i = 0;i < N;i++)
	{
		cout << &pd1[i] << "에" << pd1[i] << ";  ";
		cout << &pd2[i] << "에" << pd2[i] << endl;
	}

	cout << "\nnew와 위치 지정 new의 두 번째 호출:\n";
	double* pd3, * pd4;
	pd3 = new double[N];
	pd4 = new(buffer)double[N];
	for (i = 0;i < N;i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "메모리 내용:\n";
	for (i = 0;i < N;i++)
	{
		cout << &pd3[i] << "에" << pd3[i] << ";  ";
		cout << &pd4[i] << "에" << pd4[i] << endl;
	}
	cout<< "\nnew와 위치 지정 new의 세 번째 호출:\n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0;i < N;i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "메모리 내용:\n";
	for (i = 0;i < N;i++)
	{
		cout << &pd1[i] << "에" << pd1[i] << ";  ";
		cout << &pd2[i] << "에" << pd2[i] << endl;
	}
	delete[]pd1;	
	delete[]pd3;
	return 0;
}*/

	//두 사각형의관계
	/*using namespace std;
	double x, y, width, height;
	double x1, y1, width1, height1;
	double Distance, Distance1;
	cout << "첫 번째 사각형 x, y, width, height: ";
	cin >> x >> y >> width >> height;
	cout << "두 번째 사각형 x1, y1, width1, height1: ";
	cin >> x1 >> y1 >> width1 >> height1;
	Distance = pow((x1 + width1) - x, 2) + pow((y1 + height1) - y, 2);
	Distance = sqrt(Distance);
	Distance1 = pow((x1 + width1) - x, 2) + pow((y1 + height1) - (y + height), 2);
	Distance1 = sqrt(Distance1);
	if (Distance <= width && Distance1 <=height)
	{
		cout << "내부에 있음";
	}
	else if (x1 > x && x1 < x + width && y1 > y && y1 < y + height)
	{
		cout << "두 번째 사각형은 첫 번째 사각형과 겹쳤다.";
	}
	else
	{
		cout << "두 번째 사각형은 첫 번째 사각형과 겹치지 않는다.";
	}
}*/