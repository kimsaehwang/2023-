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
	cout << "d1�� d2������ �Ÿ� : " << d1.length(d2) << endl;
	cout << "contains(c1,d2) : " << contains(c1, d2) << endl;
	cout << "contains(r1,d2) : " << contains(r1, d2) << endl;
}

	//Q1. Rectangle2D Ŭ���� �����϶�.
	/* ���簢���� �߽��� ��Ÿ����x,y ��� �ΰ��� double ������ �ʵ�,
	  -�̿� ���� get ����Լ���set�Լ�, �簢���� ���� x,y�࿡
	   ������ ������ �����Ѵ�.
	  -double ������ �ʵ� width,height �� �̿� ���� get ��� �Լ��� set �Լ�
	  -(x,y)�� (0,0),width,height �� ���1�� �⺻ ���簢���� �����ϴ�
	   �μ� ���� ������
	  -������ x,y,width,height �� ���簢���� �����ϴ� ������
	  -���簢���� ������ ��ȯ�ϴ� getAgree()��� �Լ�
	  -���簢���� �ѷ��� ��ȯ�ϴ� getPerimeter()��� �Լ�
	  -������ ��(x,y)�� ������ ���簢���� ���ο� �������, true�� ��ȯ�ϴ�
	   contains(double x,double y)��� �Լ�
	  -������ ��(x,y)�� ������ ���簢���� ���ο� �������, true�� ��ȯ�ϴ�
	   contains(const Rectangle2D &r)��� �Լ�
	  -������ ��(x,y)�� ������ ���簢���� ��ø�Ǵ� ���, true�� ��ȯ�ϴ�
	   contains(const Rectangle2D &r)��� �Լ�
	Ŭ������ ���� UML ���̾�׷��� �׸���, Ŭ������ �����϶�.
	�� ���� Rectangle2D ��ü 
	-r1(2,2,5.5,4.9),
	-r2(4,5,10.5,3.2),
	-r3(3,5,2.3,5.4)
	�� �����ϰ�, r1�� ������ �ѷ��� ȭ�鿡 ����ϸ�,r1.contains(r2),
	r1.overlaps(r3)�� ����� ȭ�鿡 ����ϴ� �׽�Ʈ ���α׷��� �ۼ��϶�.
	*/

	/*using namespace std;
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.2);
	cout << "r1�� �������ѷ�: " << r1.getArea() << " " << r1.getPerimeter()<<endl;
	cout << "r1.contains(r2): " << r1.contains(r2) << endl;
	cout << "r1.overlaps(r3): " << r1.overlaps(r3) << endl;
}*/