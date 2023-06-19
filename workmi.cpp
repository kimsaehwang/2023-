#include<iostream>
#include<cstring>
#include"workermi.h"
const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Worker* lolas[SIZE];

	int ct;
	for (ct = 0;ct < SIZE;ct++)
	{
		char choice;
		cout << "������ �Է��Ͻʽÿ�:\n"
			<< "w: ������    s:����    "
			<< "t: �����������    q: ����\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w,s,t,q �߿��� �ϳ��� �����Ͻʽÿ�: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': lolas[ct] = new Waiter;
			break;
		case 's': lolas[ct] = new Singer;
			break;
		case 't': lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout << "\n��� ��Ȳ�� ������ �����ϴ�:\n";
	int i;
	for (i = 0;i < ct;i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0;i < ct;i++)
		delete lolas[i];
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}