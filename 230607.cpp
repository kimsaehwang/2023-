#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{
	//사물함
	/*using namespace std;
	int i,j;
	int locker[100] = { 0, };

	for (i = 0;i < 100;i++)
	{
		for (j = i;j < 100;j += i + 1)
		{
			if (locker[j] == 0)locker[j] = 1;
			else locker[j] = 0;
		}
	}
	for (i = 0;i < 100;i++)
	{
		if(locker[i] == 1)
			cout << "L" << i + 1<<" ";
	}
}*/

	/*
#ifndef STOCK10_H_
#define STOCK10_H_

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const std::string& co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};
#endif
Stock::Stock()
{
	std::cout << "디폴트 생성자가 호출되었습니다.\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr)
{
	std::cout << co << "를 사용하는 생성자가 호출되었습니다.\n";
	company = co;

	if (n < 0)
	{
		std::cerr << "주식 수는 음수가 될 수 없으므로, "
			<< company << "shares를 0으로 설정합니다.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::~stock()
{
	std::cout << "안녕, " << company << "!\n";
}
void Strock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "매입 주식 수는 음수가 될 수 없으므로, "
			<< "거래가 취소되었습니다.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Strock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout<<"매도 주식 수는 음수가 될 수 없으므로, "
			<< "거래가 취소되었습니다.\n";
	}
	else if (num > shares)
	{
		cout << "보유 주식보다 많은 주식을 매도할 수 없으므로, "
			<< "거래가 취소되었습니다.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Strock::update(double price)
{
	share_val = price;
	set_tot();
}
void Strock::show()
{
	using std::cout;
	using std::ios_base;
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "회사명: " << company
		<< "주식수: " << shares << '\n';
	cout << "주가: $" << share_val;
	cout.precision(2);
	cout << "주식 총 가치: $" << total_val << '\n';

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
int main()
{
	{
		using std::cout;
		cout << "생성자를 사용하여 샤로운 객체들을 생성한다.\n";
		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);
		stock2.show();

		cout << "stock1dmf stock2에 대입한다.\n";
		stock2 = stock1;
		cout << "stock1과 stock2를 출력한다.\n";
		stock1.show();
		stock2.show();

		cout << "생성자를 사용하여 객체를 재설정한다.\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);
		cout << "갱신된 stock1:\n";
		stock1.show();
		cout << "프로그램을 종료합니다.\n";
	}
	return 0;
}*/
	//아이템 뽑기
	/*using namespace std;
	srand((unsigned int)time(NULL));
	int A = 1, B = 3, C = 3, D = 5, E = 5, F = 10, G = 10, H = 10, I = 10, J = 10, K = 38;
	int num ;
	int item;
	int sec, thi, fou;
	cout << "횟수 =";
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		item = rand() % 100;

		if (item >= 38)
		{
			K++;
		}
		else if (item >= 10 && item < 38)
		{
			
		}
		else if (item >= 5 && item < 10)
		{
			
		}
		else if (item >= 3 && item < 5)
		{
			
		}
		else
		{
			
		}
	}
	cout << "A:" << A << ",B:" << B << ",C:" << C << ",D:" << D << ",E:" << E << ",F:" << F << ",G:" << G << ",H:" << H << ",I:" << I << ",J:" << J << ",K:" << K;
}*/

	//동전던지기
	/*using namespace std;
	int coin;
	int i = 0;
	int num = 0;
	int front = 0;
	int back = 0;
	srand((unsigned int)time(NULL));
	while (i < 100000)
	{
		for (i = 0;i < 1000000;i++)
		{
			num++;
			coin = rand() % 2;
			if (coin == 0)
			{ 
				front ++;
			}
			else
			{ 
				back ++;
			}
		}
		cout << num << "번째일 때 앞면" << ((double)front/num)*100 << "% 뒷면" << ((double)back / num) * 100 <<"%\n";
	}
}*/

