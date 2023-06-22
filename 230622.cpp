#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>

void outint(int n) { std::cout << n << " "; }

//const int NUM = 5;
/*
struct Review
{
	std::string title;
	int rating;
};
bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);
*/
int main()
{
	//p.1295 ���տ���
	/*using namespace std;
	const int N = 6;
	string s1[N] = { "buffon","thinkers","for","heavy","can","for" };
	string s2[N] = { "metal","any","food","elegant","deliver","for" };
	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);

	ostream_iterator<string, char>out(cout, " ");
	cout << "���� A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "���� B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;

	cout << "A�� B�� ������:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A�� B�� ������:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A�� B�� ������:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	cout << "���� C: \n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C,C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "������ ���� ���� C:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "Ư���� ������ ǥ��:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;

	return 0;
}*/

	//p.1287 list
	/*using namespace std;
	list<int>one(5, 2);
	int stuff[5] = { 1,2,4,8,6 };
	list<int>two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6,4,2,4,6,5 };
	list<int>three(two);
	three.insert(three.end(), more, more + 6);

	cout << "����Ʈ one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl << "����Ʈ three: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "����Ʈ three: ";
	for_each(three.begin(), three.end(), outint);
	three.remove(2);
	cout << endl << "����Ʈ three���� 2���� ����: ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << endl << "���� ���� ����Ʈ three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "����Ʈ one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();
	cout << endl << "����ȭ ���� ����Ʈ three: ";
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout << endl << "���İ� ����ȭ ���� ����Ʈ three: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	two.unique();
	three.merge(two);
	cout << endl << "���ĵ� ����Ʈ two�� ����Ʈ three�� �պ�: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	return 0;
}*/

	//p.1254 ����
	/*using namespace std;

	vector<Review>books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "�����մϴ�. ����� ������ ���� " << books.size() << "���� å ����� �Է��ϼ̽��ϴ�.\n" << "���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), ShowReview);
		cout << "å ������ �������� ����:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "å ����� �������� ����:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());
		cout << "������ ������ �ٽ� ��ġ:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

bool operator<(const Review& r1, const Review& r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool FillReview(Review & rr)
{
	std::cout << "å ������ �Է��Ͻʽÿ�(�������� quit�� �Է�): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "å ���(0-10)�� �Է��Ͻʽÿ�: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
		return true;
}
void ShowReview(const Review& rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}*/

	//p.1243 ���� ���ø�
	/*using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;
	vector<int>ratings(NUM);
	vector<string>titles(NUM);
	cout << NUM << "���� å ����� å ���(0~10)�� �Է��Ͻʽÿ�.\n";
	int i;
	for (i = 0;i < NUM;i++)
	{
		cout << i + 1 << "�� å�� ������ �Է��Ͻʽÿ�: ";
		getline(cin, titles[i]);
		cout << i + 1 << "�� å�� ��� (0~10)�� �Է��Ͻʽÿ�: ";
		cin >> ratings[i];
		cin.get();
	}
	cout << "�����մϴ�.����� ������ ���� �Է��Ͽ����ϴ�: \n" << "���\t����\n";
	for (i = 0;i < NUM;i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}
	return 0;
}*/

	//p.1231������ ������
	/*
class Report
{
private:
	std::string str;
public:
	Report(const std::string s) : str(s)
	{
		std::cout << "��ü�� �����Ǿ����ϴ�!\n";
	}
	~Report() 
	{
		std::cout << "��ü�� ���� �Ǿ����ϴ�!\n";
	}
	void comment()const
	{
		std::cout << str << "\n";
	}
};
int main()
{
	{
		std::auto_ptr<Report>ps(new Report("auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report>ps(new Report("shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report>ps(new Report("unique_ptr"));
		ps->comment();
	}
	return 0;
}*/

	//p.1225
	/*using namespace std;
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "ũ��:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "�뷮:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "empty.reserve(50) ���� �뷮: " << empty.capacity() << endl;
	return 0;
}*/

	//���ڿ� ����
	/*using namespace std;
	string one("Lottery Winner!");
	cout << one << endl;
	string two(20, '$');
	cout << two << endl;
	string three(one);
	cout << three << endl;
	one += "Oops!";
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'p';
	string four;
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);
	cout << five << "!\n";
	string six(alls + 6, alls + 10);
	cout << six << ", ";
	string seven(&five[6], &five[10]);
	cout << seven << ",,,\n";
	string eight(four, 7, 16);
	cout << eight << "in motion!" << endl;
	return 0;
}*/

	//Q1.�ﰢ��
	/*using namespace std;
	int k;
	cout << "k = ";
	cin >> k;
	for (int i = 0;i < k; i++)
	{
		for (int j = k;j > 0; j--)
		{
			if (j>i)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << "\n";
	}
	for (int i = 0;i < k; i++)
	{
		for (int j = 0;j < k; j++)
		{
			if (j - 1 > i)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
}*/