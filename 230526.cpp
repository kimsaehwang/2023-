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
	cout << "몇 단인가요?";
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

	//알고리즘33p Q8
	/*
	int a, b;
	int sum = 0;
	cout <<"a,b의 값: ";
	cin >> a >>b;

	if (a > b)
	{
		sum = (a + b) * (a - b + 1) * 1 / 2;
	}
	else if (b > a)
	{
		sum = (a + b) * (b - a + 1) * 1 / 2;
	}
	cout<<"a부터b까지의 합 : "<< sum;

	//Q9
	int n;
	cout << "n의 값: ";
	cin >> n;

	n = (1 + n) * (n - 1 + 1) * 1 / 2;
	cout << "1부터n까지의 합 :" << n;
}*/

	//Q1. p232. 5,6,9,번
	/*using namespace std;
	int* pt = new int;
	inflatable snack =
	{
		"Mocha Munch",2.3 ,350
	};
	cout << "상표명 : " << snack.CandyBar << "\n";
	cout << "중량 : " << snack.volume << "\n";
    cout << "칼로리 : "<<snack.price << "\n";

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
	cout << "이름을 입력하십시오: ";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);

	return pn;
}*/

	//strcpy사용
	/*
	using namespace std;
	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	cout << animal << " and ";
	cout << bird << "\n";

	cout << "동물의 종류를 압력하시오: ";
	cin >> animal;

	ps = animal;
	cout << ps << "s!=n";
	cout << " strcpy() 사용 전:\n";
	cout << (int*)animal << " : " << animal << ps << endl;
	cout << (int*)ps << " : " << ps << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;
	delete[] ps;
	return 0;
	*/

	//포인터와 배열크기
	/*
	using namespace std;
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3,2,1 };

	double* pw = wages;
	short* ps = &stacks[0];

	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "pw 포인터에 1을 더함:\n";
	cout << "pw = " << pw << ",*pw = " << *pw << "\n\n";

	cout << "ps = " << ps << ",*ps = " << *ps << endl;
	ps = ps + 1;
	cout << "ps 포인터에 1을 더함";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	cout << "배열 표기로 두 원소에 접근\n";
	cout << "stacks[0] = " << stacks[0]
		<< ", stacks[1] = " << stacks[1] << endl;
	cout << "포인터 표기로 두 원소에 접근\n";
	cout << "*stacks = " << *stacks
		<< ", *(stacks + 1) = " << *(stacks + 1) << endl;

	cout << sizeof(wages) << " = wages 배열의 크기\n";
	cout << sizeof(pw) << " = pw 포인터의 크기\n";
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
	cout << "p3[1]은 " << p3[1] << "입니다.\n";
	p3 = p3 + 1;
	cout << "이제는 p3 [0]이 " << p3[0] << "이고, ";
	cout << "p3[1]이 " << p3[1] << "입니다.\n";
	p3 = p3 - 1;
	delete[] p3;
	_CrtDumpMemoryLeaks();
	return 0;
	*/

	//string 예시
	/*
	using namespace std;
	string s1 = "penguin";
	string s2, s3;

	cout << "string 객체를 string 객체에 대입할 수 있다: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ",s2 : "<< s2 << endl;
	cout << "string 객체에 c 스타일 문자열을 대입할 수 있다.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;
	cout << "string 객체들을 결합할 수 있다: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string 객체들을 추가할 수 있다.\n";
	s1 += s2;
	cout << "s1 += s2 --> s1 = " << s1 << endl;
	s2 += "for a day";
	cout << "s2 += \"for a day\" --> s2 = " << s2 << endl;
	return 0;
	*/

	//문자열 읽기
	/*
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름을 입력하십시오: \n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get(name, ArSize).get();
	cout << "좋아하는 디저트를 입력하십시오: \n";	cin.get(dessert, ArSize).get();
	cout << "맛있는 " << dessert;
	cout << "디저트를 준비하겠습니다. " << name << "님!\n";
	return 0;
	*/
