#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"string1.h"
#include"string2.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
	
	      
}
	//p.889 2��
	/*using namespace std;
	String s1(" and I am a C++ student.");
	String s2 = "���� �̸��� �Է��Ͻʽÿ�: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is" + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.~Stringup();
	cout << "���� ���ڿ�����\n" << s2 << "\n���� 'A'�� "
		<< s2.has('A') << "�� ��� �ֽ��ϴ�.\n";
	s1 = "red";
	String rgb[3] = { String(s1),String("green"),String("blue") };
	cout << "���� ������� �̸��� �ϳ��� �Է��Ͻʽÿ�: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		for (int i = 0;i < 3;i++)
		{
			if (ans == rgb[i])
			{
				if (ans == rgb[i])
				{
					cout << "�¾ҽ��ϴ�!\n";
					success = true;
					break;
				}
			}
			if (success)
				break;
			else
				cout << "�ٽ� �Է��Ͻʽÿ�: ";
		}
		cout << "���α׷��� �����մϴ�.\n";
		return 0;
	}
}*/

	/*using namespace std;
	String name;
	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n>> ";
	cin >> name;

	cout << name << "��! ������ �츮 �Ӵ�" << ArSize
		<< "���� �Է��� �ֽʽÿ�(�������� Enter) :\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0;i < ArSize;i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "(������ ���� �Ӵ���� �Է��Ͽ����ϴ�.)\n";
		for (i = 0;i < total;i++)
			cout << sayings[i] << "\n";
		String* shortest = &sayings[0];
		String* first = &sayings[0];
		for (i = 1;i < total;i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "���� ª�� �Ӵ�:\n" << *shortest << endl;
		cout << "���������� ���� �տ� ������ �Ӵ�:\n" << *first << endl;
		srand(time(0));
		int choice = rand() % total;
		String* favorite = new String(sayings[choice]);
		cout << "���� ���� �����ϴ� �Ӵ�:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "�˰� �ִ� �Ӵ��� �ϳ��� �����?\n";
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}*/