#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{
	//�繰��
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
	std::cout << "����Ʈ �����ڰ� ȣ��Ǿ����ϴ�.\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr)
{
	std::cout << co << "�� ����ϴ� �����ڰ� ȣ��Ǿ����ϴ�.\n";
	company = co;

	if (n < 0)
	{
		std::cerr << "�ֽ� ���� ������ �� �� �����Ƿ�, "
			<< company << "shares�� 0���� �����մϴ�.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::~stock()
{
	std::cout << "�ȳ�, " << company << "!\n";
}
void Strock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "���� �ֽ� ���� ������ �� �� �����Ƿ�, "
			<< "�ŷ��� ��ҵǾ����ϴ�.\n";
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
		cout<<"�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, "
			<< "�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else if (num > shares)
	{
		cout << "���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, "
			<< "�ŷ��� ��ҵǾ����ϴ�.\n";
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

	cout << "ȸ���: " << company
		<< "�ֽļ�: " << shares << '\n';
	cout << "�ְ�: $" << share_val;
	cout.precision(2);
	cout << "�ֽ� �� ��ġ: $" << total_val << '\n';

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
int main()
{
	{
		using std::cout;
		cout << "�����ڸ� ����Ͽ� ���ο� ��ü���� �����Ѵ�.\n";
		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);
		stock2.show();

		cout << "stock1dmf stock2�� �����Ѵ�.\n";
		stock2 = stock1;
		cout << "stock1�� stock2�� ����Ѵ�.\n";
		stock1.show();
		stock2.show();

		cout << "�����ڸ� ����Ͽ� ��ü�� �缳���Ѵ�.\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);
		cout << "���ŵ� stock1:\n";
		stock1.show();
		cout << "���α׷��� �����մϴ�.\n";
	}
	return 0;
}*/
	//������ �̱�
	/*using namespace std;
	srand((unsigned int)time(NULL));
	int A = 1, B = 3, C = 3, D = 5, E = 5, F = 10, G = 10, H = 10, I = 10, J = 10, K = 38;
	int num ;
	int item;
	int sec, thi, fou;
	cout << "Ƚ�� =";
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

	//����������
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
		cout << num << "��°�� �� �ո�" << ((double)front/num)*100 << "% �޸�" << ((double)back / num) * 100 <<"%\n";
	}
}*/

