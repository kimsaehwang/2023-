#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<crtdbg.h>
using namespace std;
//char* getname(void);
struct inflatable
{
	char CandyBar[20];
	float volume;
	double price;
};
int main()
{
	int n;
	int cnt = 1;
	cout << "�� ���ΰ���?";
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if(i == j || i + j == n - 1 || i > j && i + j >= n - 1 || i < j && i + j < n)
			{
				cnt = (i % 10)+1;
				
				cout << cnt;
			}
			else
			{
				cout <<" ";
			}
		}
		cout << "\n";
	}
}

	//�˰���33p Q8
	/*
	int a, b;
	int sum = 0;
	cout <<"a,b�� ��: ";
	cin >> a >>b;

	if (a > b)
	{
		sum = (a + b) * (a - b + 1) * 1 / 2;
	}
	else if (b > a)
	{
		sum = (a + b) * (b - a + 1) * 1 / 2;
	}
	cout<<"a����b������ �� : "<< sum;

	//Q9
	int n;
	cout << "n�� ��: ";
	cin >> n;

	n = (1 + n) * (n - 1 + 1) * 1 / 2;
	cout << "1����n������ �� :" << n;
}*/

	//Q1. p232. 5,6,9,��
	/*using namespace std;
	int* pt = new int;
	inflatable snack =
	{
		"Mocha Munch",2.3 ,350
	};
	cout << "��ǥ�� : " << snack.CandyBar << "\n";
	cout << "�߷� : " << snack.volume << "\n";
    cout << "Į�θ� : "<<snack.price << "\n";

}*/

	//
	/*
	char* name;

	name = getname();
	cout << (int*)name << ": " << name << "\n";
	delete[]name;

	name = getname();
	cout << (int*)name << ": " << name << "\n";
	delete[]name;
	return 0;
}
char* getname()
{
	char temp[80];
	cout << "�̸��� �Է��Ͻʽÿ�: ";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);

	return pn;
}*/

	//strcpy���
	/*
	using namespace std;
	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	cout << animal << " and ";
	cout << bird << "\n";

	cout << "������ ������ �з��Ͻÿ�: ";
	cin >> animal;

	ps = animal;
	cout << ps << "s!=n";
	cout << " strcpy() ��� ��:\n";
	cout << (int*)animal << " : " << animal << ps << endl;
	cout << (int*)ps << " : " << ps << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;
	delete[] ps;
	return 0;
	*/

	//�����Ϳ� �迭ũ��
	/*
	using namespace std;
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3,2,1 };

	double* pw = wages;
	short* ps = &stacks[0];

	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "pw �����Ϳ� 1�� ����:\n";
	cout << "pw = " << pw << ",*pw = " << *pw << "\n\n";

	cout << "ps = " << ps << ",*ps = " << *ps << endl;
	ps = ps + 1;
	cout << "ps �����Ϳ� 1�� ����";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	cout << "�迭 ǥ��� �� ���ҿ� ����\n";
	cout << "stacks[0] = " << stacks[0]
		<< ", stacks[1] = " << stacks[1] << endl;
	cout << "������ ǥ��� �� ���ҿ� ����\n";
	cout << "*stacks = " << *stacks
		<< ", *(stacks + 1) = " << *(stacks + 1) << endl;

	cout << sizeof(wages) << " = wages �迭�� ũ��\n";
	cout << sizeof(pw) << " = pw �������� ũ��\n";
	return 0;
	*/

	//Memory Leak
	/*
	using namespace std;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * 4);
	double* p3 = new double[3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1]�� " << p3[1] << "�Դϴ�.\n";
	p3 = p3 + 1;
	cout << "������ p3 [0]�� " << p3[0] << "�̰�, ";
	cout << "p3[1]�� " << p3[1] << "�Դϴ�.\n";
	p3 = p3 - 1;
	delete[] p3;
	_CrtDumpMemoryLeaks();
	return 0;
	*/

	//string ����
	/*
	using namespace std;
	string s1 = "penguin";
	string s2, s3;

	cout << "string ��ü�� string ��ü�� ������ �� �ִ�: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ",s2 : "<< s2 << endl;
	cout << "string ��ü�� c ��Ÿ�� ���ڿ��� ������ �� �ִ�.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;
	cout << "string ��ü���� ������ �� �ִ�: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string ��ü���� �߰��� �� �ִ�.\n";
	s1 += s2;
	cout << "s1 += s2 --> s1 = " << s1 << endl;
	s2 += "for a day";
	cout << "s2 += \"for a day\" --> s2 = " << s2 << endl;
	return 0;
	*/

	//���ڿ� �б�
	/*
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸��� �Է��Ͻʽÿ�: \n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get(name, ArSize).get();
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�: \n";	cin.get(dessert, ArSize).get();
	cout << "���ִ� " << dessert;
	cout << "����Ʈ�� �غ��ϰڽ��ϴ�. " << name << "��!\n";
	return 0;
	*/
