#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<crtdbg.h>
#include<fstream>
const int SIZE = 60;

void showmenu();
void realname();
void member();
void title();

int main()
{
	//Q5. �Ҽ��Ǻ�
	using namespace std;
	int n,i,j;
	unsigned long counter = 0;
	cout << "�����Է�: ";
	cin >> n;
	for (i = 3;i <= n; i+=2)
	{
		for (j = 3;j < i;j+=2)
		{
			counter++;
			if (i % j == 0)break;
		}
	}
	cout << "\n�������� ������ Ƚ��: " << counter;

}

	//Q4. p78 5��
	/*using namespace std;
	int a[10];
	int n;
	cout << "�迭�� ������ �Է��ϼ���: ";
	cin >> n;
	cout << "�迭�� �Է��Ͻÿ�" <<"\n";
	cin >> a[n];
	for (int i = 0;i < n / 2;i++)
	{
		cout << "a[" << i << "]�� a[" << n - i - 1 << "]�� ��ȯ�մϴ�.\n";
		int temp;
		temp = a[n];
		a[n] = a[n - i - 1];
		a[n - i - 1] = temp;
		cout << a[n] << "\n";
	}
	cout << "���� ������ �����մϴ�.";
	
	

}*/

	//Q2.p368 4��
	/*showmenu();
	int choice;
	cin >> choice;

	ofstream outFile;
	outFile.open("bop.txt");

	while(choice != 'Q' && choice != 'q')
	{
		switch (choice)
		{
		case'a':
		case'A': member(); break;
		case'b':
		case'B': cout << "����: "; break;
		case'c':
		case'C': cout << "bop id: "; break;
		case'd':
		case'D': cout << "\a\n"; break;
		case'q':
		case'Q': cout << "���α׷��� �����մϴ�.\n"; break;
		}
	}
}

void showmenu()
{
	cout << "Benevolent Order of Programmers\n"
		"a.ȸ�� ���     b.�Ǹ� ����\n"
		"c.���� ����     d.ȸ���� ������ ������ ����\n"
		"q.����\n";
}
void member()
{
	char name,title,bop;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "�̸�: ";
	cin >> name;
	cout << "����: ";
	cin >> title;
	cout << "bop id: ";
	cin >> bop;

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	
}*/

	//sumafile���
	/*using namespace std;
	char filename[SIZE];
	ifstream inFile;
	cout << "������ ������ �̸��� �Է��Ͻÿ�: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << filename << "������ �� �� �����ϴ�." << endl;
		cout << "���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good())
	{
		++count;
		sum += value;
		inFile >> value;
	}
	if (inFile.eof())
		cout << "���� ���� �����߽��ϴ�.\n";
	else if (inFile.fail())
		cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�.\n";
	else
		cout << "�� �� ���� �̷��� �Է��� ����Ǿ����ϴ�.\n";
	if (count == 0)
		cout << "�����Ͱ� �����ϴ�.\n";
	else
	{
		cout << "���� �׸��� ����: " << count << endl;
		cout << "�հ�: " << sum << endl;
		cout << "���: " << sum / count << endl;
	}
	inFile.close();
	return 0;*/

	//outFile ��� ����
	/*using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");
	
	cout << "�ڵ��� ����Ŀ�� ������ �Է��Ͻÿ�: ";
	cin.getline(automobile, 50);
	cout << "������ �Է��Ͻÿ�: ";
	cin >> year;
	cout << "���� ������ �Է��Ͻÿ�: ";
	cin >> a_price;
	d_price = 0.193 * a_price;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout <<"����Ŀ�� ����: " << automobile << endl;
	cout << "����: " << year << endl;
	cout << "���԰��� $ " << a_price << endl;
	cout << "���簡�� $ " << d_price << endl;

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "����Ŀ�� ����: " << automobile << endl;
	outFile << "����: " << year << endl;
	outFile << "���԰��� $ " << a_price << endl;
	outFile << "���簡�� $ " << d_price << endl;

	outFile.close();
	return 0;*/

	//Q1.�����
	/*using namespace std;
	double v ,a;
	double length;
	cout << "Speed and Accelation :";
	cin >> v >> a;
	length = pow(v, 2) / (2 * a);
	cout << "Minimum runway length :" << length;*/

	//Q2.�� �������ǰŸ�
	/*using namespace std;
	double x1, x2, y1, y2;
	double Distance;
	cout << "x1 , y1 :";
	cin >> x1 >> y1;
	cout << "x2 , y2 :";
	cin >>x2 >> y2;
	Distance = pow(x2 - x1,2) + pow(y2 - y1,2);
	Distance = sqrt(Distance);
	cout << "Distance : " << Distance;*/