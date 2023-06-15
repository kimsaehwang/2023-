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
	//p.889 2번
	/*using namespace std;
	String s1(" and I am a C++ student.");
	String s2 = "영문 이름을 입력하십시오: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is" + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.~Stringup();
	cout << "다음 문자열에는\n" << s2 << "\n문자 'A'가 "
		<< s2.has('A') << "개 들어 있습니다.\n";
	s1 = "red";
	String rgb[3] = { String(s1),String("green"),String("blue") };
	cout << "빛의 삼원색의 이름을 하나만 입력하십시오: ";
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
					cout << "맞았습니다!\n";
					success = true;
					break;
				}
			}
			if (success)
				break;
			else
				cout << "다시 입력하십시오: ";
		}
		cout << "프로그램을 종료합니다.\n";
		return 0;
	}
}*/

	/*using namespace std;
	String name;
	cout << "안녕하십니까? 성함이 어떻게 되십니까?\n>> ";
	cin >> name;

	cout << name << "씨! 간단함 우리 속담" << ArSize
		<< "개만 입력해 주십시오(끝내려면 Enter) :\n";
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
		cout << "(다음과 같은 속담들을 입력하였습니다.)\n";
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
		cout << "가장 짧은 속담:\n" << *shortest << endl;
		cout << "사전순으로 가장 앞에 나오는 속담:\n" << *first << endl;
		srand(time(0));
		int choice = rand() % total;
		String* favorite = new String(sayings[choice]);
		cout << "내가 가장 좋아하는 속담:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "알고 있는 속담이 하나도 없어요?\n";
	cout << "프로그램을 종료합니다.\n";
	return 0;
}*/