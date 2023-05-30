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
	//Q6. 10진수를 각진수로 변환
	/*using namespace std;
	int n, num;
	char num[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "값을 입력하시오: ";
	cin >> n;
	cout << "몇 진수로 변환(2~36): ";
	cin >> num;

	cout << num << "진수 ";
	for (int i = 0; i < )*/




		//Q5. p305 8번

		//Q4. p305 7번
		/*using namespace std;
		int n;
		cout << "몇 대의 차를 목록으로 관리하시겠습니까? ";
		cin >> n;
		car* taegeuk = new car;
		cout << "자동차 #1 :" << "\n";
		cout << "제작업체 : " << "\n";;
		cin.get(taegeuk->name, 20);
		cout << "제작년도 : " << "\n";;
		cin >> (*taegeuk).year;
		car *Mugunghwa = new car;
		cout << "자동차 #2 :" << "\n";
		cout << "제작업체 : " << "\n";;
		cin.get(Mugunghwa->name, 20);
		cout << "제작년도 : " << "\n";;
		cin >> (*Mugunghwa).year;
		cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다." << "\n";
		cout << taegeuk -> year <<"년형 "<< (*taegeuk).name << "\n";
		cout << Mugunghwa -> year << "년형 " << (*Mugunghwa).name << "\n";
		delete taegeuk, Mugunghwa;
		return 0;*/

		//Q3. 1~10사이의 정수 입력받아 출력
		/*using namespace std;
		int n = 0;
		cout << "라인 숫자를 입력 : ";
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

		//cin.get(char)이용한 입력
		/*using namespace std;
		char ch;
		int count = 0;

		cout << "문자들을 입력하시오; 끝내려면 #을 입력하시오 :\n";
		cin.get(ch);
		while (ch != '#')
		{
			cout << ch;
			++count;
			cin.get(ch);
		}
		cout << endl << count << "문자를 읽었습니다.\n";
		return 0;*/

		//Q2.단어 입력받고 회문인지 판단하기
		/*using namespace std;
		cout << "단어 하나를 입력하십시오: ";
		string word;
		cin >> word;

		for (int i = word.size() - 1; i >= 0;i--)
		{
			cout << word[i];

		}
		cout << "\n";
		if (word == word.size() - 1)
			cout << word << "는 회문입니다.";
		else
			cout << word << "는 회문이 아닙니다.";
		return 0;*/

		//bool값
		/*using namespace std;
		int x;

		cout << "대입 표현식 x = 100의 값은 ";
		cout << (x = 100) << endl;
		cout << "현재 x 의값은 " << x << endl;
		cout << "관계 표현식 x < 3의 정수값은";
		cout << (x < 3) << endl;
		cout << "관계 표현식 x > 3의 정수값은";
		cout << (x > 3) << endl;
		cout.setf(ios_base::boolalpha);
		cout << "관계 표현식 x < 3의 정수값은";
		cout << (x < 3) << endl;
		cout << "관계 표현식 x > 3의 정수값은";
		cout << (x > 3) << endl;
		return 0;*/

		//Q1.p232 7,8번
		/*using namespace std;
		TCL.pizza;
		cout << "피자 회사의 이름 : " << pizza.pizza << "\n";
		cout << "피자의 지름 : " << diameter << "\n";
		cout << "피자의 중량 : " << weight << "\n";*/
}