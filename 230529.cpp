#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<crtdbg.h>
/*struct car
{
	char name[20];
	float year;
};*/


int main()
{
	//Q6. 10������ �������� ��ȯ
	/*using namespace std;
	int n, num;
	char num[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "���� �Է��Ͻÿ�: ";
	cin >> n;
	cout << "�� ������ ��ȯ(2~36): ";
	cin >> num;

	cout << num << "���� ";
	for (int i = 0; i < )*/




		//Q5. p305 8��

		//Q4. p305 7��
		/*using namespace std;
		int n;
		cout << "�� ���� ���� ������� �����Ͻðڽ��ϱ�? ";
		cin >> n;
		car* taegeuk = new car;
		cout << "�ڵ��� #1 :" << "\n";
		cout << "���۾�ü : " << "\n";;
		cin.get(taegeuk->name, 20);
		cout << "���۳⵵ : " << "\n";;
		cin >> (*taegeuk).year;
		car *Mugunghwa = new car;
		cout << "�ڵ��� #2 :" << "\n";
		cout << "���۾�ü : " << "\n";;
		cin.get(Mugunghwa->name, 20);
		cout << "���۳⵵ : " << "\n";;
		cin >> (*Mugunghwa).year;
		cout << "���� ���ϰ� �����ϰ� �ִ� �ڵ��� ����� ������ �����ϴ�." << "\n";
		cout << taegeuk -> year <<"���� "<< (*taegeuk).name << "\n";
		cout << Mugunghwa -> year << "���� " << (*Mugunghwa).name << "\n";
		delete taegeuk, Mugunghwa;
		return 0;*/

		//Q3. 1~10������ ���� �Է¹޾� ���
		/*using namespace std;
		int n = 0;
		cout << "���� ���ڸ� �Է� : ";
		cin >> n;

		for (int i = 0;i <= n;i++)
		{
			for (int j = i; j < n ;j++)
			{
				cout << " ";
			}
			for (int j = i; j > 0; j--)
			{
				cout << j;
			}
			for (int j = 2; j <= i; j++)
			{
				cout << j;
			}
			cout << endl;
		}*/

		//cin.get(char)�̿��� �Է�
		/*using namespace std;
		char ch;
		int count = 0;

		cout << "���ڵ��� �Է��Ͻÿ�; �������� #�� �Է��Ͻÿ� :\n";
		cin.get(ch);
		while (ch != '#')
		{
			cout << ch;
			++count;
			cin.get(ch);
		}
		cout << endl << count << "���ڸ� �о����ϴ�.\n";
		return 0;*/

		//Q2.�ܾ� �Է¹ް� ȸ������ �Ǵ��ϱ�
		/*using namespace std;
		cout << "�ܾ� �ϳ��� �Է��Ͻʽÿ�: ";
		string word;
		cin >> word;

		for (int i = word.size() - 1; i >= 0;i--)
		{
			cout << word[i];

		}
		cout << "\n";
		if (word == word.size() - 1)
			cout << word << "�� ȸ���Դϴ�.";
		else
			cout << word << "�� ȸ���� �ƴմϴ�.";
		return 0;*/

		//bool��
		/*using namespace std;
		int x;

		cout << "���� ǥ���� x = 100�� ���� ";
		cout << (x = 100) << endl;
		cout << "���� x �ǰ��� " << x << endl;
		cout << "���� ǥ���� x < 3�� ��������";
		cout << (x < 3) << endl;
		cout << "���� ǥ���� x > 3�� ��������";
		cout << (x > 3) << endl;
		cout.setf(ios_base::boolalpha);
		cout << "���� ǥ���� x < 3�� ��������";
		cout << (x < 3) << endl;
		cout << "���� ǥ���� x > 3�� ��������";
		cout << (x > 3) << endl;
		return 0;*/

		//Q1.p232 7,8��
		/*using namespace std;
		TCL.pizza;
		cout << "���� ȸ���� �̸� : " << pizza.pizza << "\n";
		cout << "������ ���� : " << diameter << "\n";
		cout << "������ �߷� : " << weight << "\n";*/
}