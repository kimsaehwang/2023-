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
	//Q5. 소수판별
	using namespace std;
	int n,i,j;
	unsigned long counter = 0;
	cout << "숫자입력: ";
	cin >> n;
	for (i = 3;i <= n; i+=2)
	{
		for (j = 3;j < i;j+=2)
		{
			counter++;
			if (i % j == 0)break;
		}
	}
	cout << "\n나눗셈을 실행한 횟수: " << counter;

}

	//Q4. p78 5번
	/*using namespace std;
	int a[10];
	int n;
	cout << "배열의 갯수를 입력하세요: ";
	cin >> n;
	cout << "배열을 입력하시오" <<"\n";
	cin >> a[n];
	for (int i = 0;i < n / 2;i++)
	{
		cout << "a[" << i << "]과 a[" << n - i - 1 << "]를 교환합니다.\n";
		int temp;
		temp = a[n];
		a[n] = a[n - i - 1];
		a[n - i - 1] = temp;
		cout << a[n] << "\n";
	}
	cout << "역순 정렬을 종료합니다.";
	
	

}*/

	//Q2.p368 4번
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
		case'B': cout << "직함: "; break;
		case'c':
		case'C': cout << "bop id: "; break;
		case'd':
		case'D': cout << "\a\n"; break;
		case'q':
		case'Q': cout << "프로그램을 종료합니다.\n"; break;
		}
	}
}

void showmenu()
{
	cout << "Benevolent Order of Programmers\n"
		"a.회원 등록     b.실명 열람\n"
		"c.직함 열람     d.회원이 지정한 것으로 열람\n"
		"q.종료\n";
}
void member()
{
	char name,title,bop;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "이름: ";
	cin >> name;
	cout << "직함: ";
	cin >> title;
	cout << "bop id: ";
	cin >> bop;

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	
}*/

	//sumafile사용
	/*using namespace std;
	char filename[SIZE];
	ifstream inFile;
	cout << "데이터 파일의 이름을 입력하시오: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << filename << "파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다.\n";
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
		cout << "파일 끝에 도달했습니다.\n";
	else if (inFile.fail())
		cout << "데이터 불일치로 입력이 종료되었습니다.\n";
	else
		cout << "알 수 없는 이류로 입력이 종료되었습니다.\n";
	if (count == 0)
		cout << "데이터가 없습니다.\n";
	else
	{
		cout << "읽은 항목의 개수: " << count << endl;
		cout << "합계: " << sum << endl;
		cout << "평균: " << sum / count << endl;
	}
	inFile.close();
	return 0;*/

	//outFile 사용 예시
	/*using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");
	
	cout << "자동차 메이커와 차종을 입력하시오: ";
	cin.getline(automobile, 50);
	cout << "연식을 입력하시오: ";
	cin >> year;
	cout << "구입 가격을 입력하시오: ";
	cin >> a_price;
	d_price = 0.193 * a_price;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout <<"메이커와 차종: " << automobile << endl;
	cout << "연식: " << year << endl;
	cout << "구입가격 $ " << a_price << endl;
	cout << "현재가격 $ " << d_price << endl;

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "메이커와 차종: " << automobile << endl;
	outFile << "연식: " << year << endl;
	outFile << "구입가격 $ " << a_price << endl;
	outFile << "현재가격 $ " << d_price << endl;

	outFile.close();
	return 0;*/

	//Q1.비행기
	/*using namespace std;
	double v ,a;
	double length;
	cout << "Speed and Accelation :";
	cin >> v >> a;
	length = pow(v, 2) / (2 * a);
	cout << "Minimum runway length :" << length;*/

	//Q2.두 점사이의거리
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