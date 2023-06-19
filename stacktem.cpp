#include<iostream>
#include<string>
#include<cctype>
#include"stacktp.h"
using std::cin;
using std::cout;

int main()
{
	Stack<std::string>st;
	char ch;
	std::string po;
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,  \n"
		<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case'A':
		case'a': cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";
			cin >> po;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(po);
			break;
		case'P':
		case'p':if (st.isempty())
			cout << "������ ��� �ֽ��ϴ�.\n";
			   else
		{
			st.pop(po);
			cout << "#" << po << "�ֹ����� ó�� �߽��ϴ�.\n";
			break;
		}
		}
		cout << "�ֹ����� �߰��Ϸ��� A,�ֹ����� ó���Ϸ��� P,\n"
			<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}