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
	//�� ���ǰ���
	/*using namespace std;
	double x, y, r;
	double x1, y1, r1;
	double Distance;
	cout << "ù ��° �� x,y,r : ";
	cin >> x >> y >> r;
	cout << "�� ��° �� x,y,r : ";
	cin >> x1 >> y1 >> r1;
	Distance = pow(x1 - x, 2) + pow(y1 - y, 2);
	Distance = sqrt(Distance);
	if (r - r1 >= Distance)
	{
		cout << "�� ��° ���� ù��°�� ���ο� �ִ�.";
	}
	else if (r + r1 > Distance)
	{
		cout << "�� ��° ���� ù��°���� ��ģ��.";
	}
	else
	{
		cout << "�� ��° ���� ù��°�� �ܺο� �ִ�.";
	}
}*/

	//��ġ����new������
	/*using namespace std;

	double* pd1, * pd2;
	int i;
	cout << "new�� ��ġ ���� new�� ù��° ȣ��:\n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N];
	for (i = 0;i < N;i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "�޸� �ּ�:\n" << pd1 << " :��; "
		<< (void*)buffer << " : ����" << endl;
	cout << "�޸� ����:\n";
	for (i = 0;i < N;i++)
	{
		cout << &pd1[i] << "��" << pd1[i] << ";  ";
		cout << &pd2[i] << "��" << pd2[i] << endl;
	}

	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ��:\n";
	double* pd3, * pd4;
	pd3 = new double[N];
	pd4 = new(buffer)double[N];
	for (i = 0;i < N;i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "�޸� ����:\n";
	for (i = 0;i < N;i++)
	{
		cout << &pd3[i] << "��" << pd3[i] << ";  ";
		cout << &pd4[i] << "��" << pd4[i] << endl;
	}
	cout<< "\nnew�� ��ġ ���� new�� �� ��° ȣ��:\n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0;i < N;i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "�޸� ����:\n";
	for (i = 0;i < N;i++)
	{
		cout << &pd1[i] << "��" << pd1[i] << ";  ";
		cout << &pd2[i] << "��" << pd2[i] << endl;
	}
	delete[]pd1;	
	delete[]pd3;
	return 0;
}*/

	//�� �簢���ǰ���
	/*using namespace std;
	double x, y, width, height;
	double x1, y1, width1, height1;
	double Distance, Distance1;
	cout << "ù ��° �簢�� x, y, width, height: ";
	cin >> x >> y >> width >> height;
	cout << "�� ��° �簢�� x1, y1, width1, height1: ";
	cin >> x1 >> y1 >> width1 >> height1;
	Distance = pow((x1 + width1) - x, 2) + pow((y1 + height1) - y, 2);
	Distance = sqrt(Distance);
	Distance1 = pow((x1 + width1) - x, 2) + pow((y1 + height1) - (y + height), 2);
	Distance1 = sqrt(Distance1);
	if (Distance <= width && Distance1 <=height)
	{
		cout << "���ο� ����";
	}
	else if (x1 > x && x1 < x + width && y1 > y && y1 < y + height)
	{
		cout << "�� ��° �簢���� ù ��° �簢���� ���ƴ�.";
	}
	else
	{
		cout << "�� ��° �簢���� ù ��° �簢���� ��ġ�� �ʴ´�.";
	}
}*/