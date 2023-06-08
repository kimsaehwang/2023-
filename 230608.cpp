#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{
	//Q2. 행맨
	using namespace std;
	char a;
	char answer[5];
	char question[5] = { '*','*', '*', '*', '*' };
	cout << "생성된 단어: ";
	cin >> answer;
	int over = 0;
	for (int i = 0;i < 100;i++)
	{
		cin >> a;
		for (int j = 0;j < 5;j++)
		{
			cout << ">> 단어 중 한글자를 입력하시오. " << "\n"  ;
			
			if (a == answer[j])
			{
				over++;
				question[j] = a;
				cout << question[j];
			}
			else
			{
				cout << question[j];
			}
			if (over == 5)
			{
				exit(0);
			}
		}
	}
	cout << "총" << over - 1 << "번 실패, " << over << "번 만에 정답!" << answer;
	
}
	//Q1. 선과점의 관계
	/*using namespace std;
	double x0, y0, x1, y1, x2, y2;
	cout << "> p0, p1, p2: ";
	cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
	cout << "(" << x0 << "," << y0 << ")" << " (" << x1 << "," << y1 << ")" << " (" << x2 << "," << y2 << ")";
	
	double a = y2 * (x1 - x0) - x2 * (y1 - y0);
	if (a > 0)
	{
		cout << "\n>> " << "p2는 선의 왼쪽에있다.";
	}
	else if (a < 0)
	{
		cout << "\n>> " << "p2는 선의 오른쪽에 있다.";
	}
	else if (a == 0)
	{
		cout << "\n>> " << "p2는 선상에 있다.";
	}
}*/