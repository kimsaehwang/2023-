#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include "StopWatch.h"
#include <vector>
#include "LinkedList.h"
#include <string>
/*
int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}
int bin_search2(const int a[], int n, int key);

typedef struct
{
	int max;
	int ptr;
	int* stk;
}Intstack;
using namespace std;
void reverseDisplay(int value);
void reverseDisplay(const string& str);

using namespace std;
void hanoi(int discus, int a, int b);

void insertion(int list[], int n);
void move(int no, int x, int y);
*/

using namespace std;

	int main() 
	{
		/*
		학생관리하는 구조체를 생성
		-번호,이름 멤버를 포함
		구조체 리스트를 만들어라
		1.입력 (번호와 이름을 입력받아 리스트에 추가)
		2.삭제 (해당번호를 입력받아 리스트에 삭제)
		3.전체 출력(리스트에 있는 학생의 번호와 이름을 출력)
		*/
		Student studentList[MAX_STUDENTS];
		int numStudents = 0;
		int choice,rev;
		while (true) 
		{
			cout << "1. 학생 추가 | 2. 학생 삭제 | 3. 전체 학생 출력 | 4. 종료\n";
			cout << "원하는 기능을 선택하세요: ";
			cin >> choice;

			switch (choice) 
			{
			case 1:
				addStudent(studentList, numStudents);
				break;
			case 2:
				removeStudent(studentList, numStudents);
				break;
			case 3:
				cin >> rev;
				switch (rev)
				{
				case 1:
					printAllStudents1(studentList, numStudents);
					break;
				case 2:
					printAllStudents2(studentList, numStudents);
					break;
				}
			
			case 4:
				cout << "프로그램을 종료합니다.\n";
				return 0;
			default:
				cout << "잘못 선택 했습니다.\n";
				break;
			}
		}
		return 0;
	}
	
	
	//len - s_value = 이동량
	/*
	char txt[30] = "ADGERDEFABC";
	char pat[30] = "ABC";
	int pt = strlen(txt);
	int pp = strlen(pat);
	cout << "텍스트 : " << txt << endl;
	cout << "패턴 : " << pat << endl;
	char* len = strstr(txt, pat);
	
	if (len == NULL) cout << "패턴이 없습니다.";
	else
	{
		int movement = len - txt;
	}
	
	
}*/

	//도수 정렬
	/*int arr[7] = { 5, 2, 4, 8, 9, 1, 4 };

	cout << "정렬 전: ";
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	countingSort(arr, 7);

	cout << "정렬 후: ";
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

void countingSort(int arr[], int n)
{
	int i;
	int max = arr[0];
	int* count = new int[max + 1]();
	int index = 0;
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	for (i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}

	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			arr[index++] = i;
			count[i]--;
		}
	}
}*/

	//친구수 분석
	/*int arr[][2] = {
		{1, 3},
		{2, 4},
		{3, 2},
		{4, 3},
		{5, 2}
	};
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int n = 1; n <= 5; n++) {
		int friendCount = countFriends(arr, size, n);
		std::cout << n << "번: " << friendCount << "명" << std::endl;
	}

	return 0;
}
int countFriends(int arr[][2], int size, int n) 
{
	int count = 0;

	for (int i = 0; i < size; i++) 
	{
		if (arr[i][0] == n || arr[i][1] == n) 
		{
			count++;
		}
	}

	return count;
}*/

	//heapsort
	/*int num = 7;
	int i;
	int heap[7] = { 6,4,3,7,1,9,8 };
	
	cout << "정렬전 : ";
	for (i = 0;i < num;i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl;

}

void heapsort(int heap[], int n)
{
	int i;
	for(i=0;i<=n;i++)

}*/

	//merge sort
	/*int i;
	int a[13] = { 2,4,6,8,11,13,1,2,3,4,9,16,21 };
	cout << "정렬전 : ";
	for (i = 0;i < 13;i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl;
}

void mergesort(int a[], int left, int right)
{

}*/

	//Quick sort
	/*int i;
	int a[9] = { 5,7,1,4,6,2,3,9,8 };

	cout << "정렬전 : ";
	for (i = 0;i < 9;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	quicksort(a, 0, 9 - 1);

	cout << "정렬후 : ";
	for(i = 0;i < 9;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	StopWatch sw;
	double elapTime = sw.getElapsedTime();
	cout << "걸린 시간 : " << elapTime << "s";
}

void quicksort(int a[], int L, int R)
{
	int left = L;
	int right = R;
	int pivot = a[(L + R) / 2];
	int temp;
	do
	{
		while (a[L] < pivot) L++;
		while (a[R] > pivot) R--;
		if (L <= R)
		{
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
			L++;
			R--;
		}
	} while (L <= R);
	if (left < R)quicksort(a, left, R);
	if (L < right)quicksort(a, L, right);
}*/

	//p.226 단순 삽입 정렬
	/*int a;
	int list[] = { 6,4,8,5,2,9,7 };

	for (int i = 0;i < 7;i++)
	{
		cout << " "<< list[i] << " ";
	}
	cout << endl << endl;

	insertion(list, 7);

	for (int i = 0;i < 7;i++)
	{
		cout << " " << list[i] << " ";
	}
}

void insertion(int list[], int n)
{
	int i, j, tmp;
	for (i = 1;i < n;i++)
	{
		tmp = list[i];
		for (j = i - 1;j >= 0 && list[j] > tmp;j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = tmp;
	}
}

void move(int list[], int x, int y, int z)
{

}*/

	//Q2.하노이탑 >>원반 최대 크기(0:exit) :1
	/*int discus;
	cout << "원반 최대 크기(0:exit) : ";
	cin >> discus;
	hanoi(discus, 1, 3);
	
}
void hanoi(int discus, int a, int b)
{
	if (discus > 1)
	{
		hanoi(discus - 1, a, 6 - a - b);
	}
	cout << "원반[" << discus << "]을 " << "[" << a << "]기둥에서 " << "[" << b << "]기둥으로 옮김"<<endl;
	if (discus > 1)
	{
		hanoi(discus - 1, 6 - a - b, b);
	}
}*/

	//재귀호출 리버스
	/*reverseDisplay(12345);
	reverseDisplay("abcd");
}

void reverseDisplay(int value)
{
	if (value > 0)
	{
		cout << value % 10;
		reverseDisplay(value / 10);
	}
}

void reverseDisplay(const string& str)
{
	if (str.length() > 0)
	{
		cout << str.back();
		reverseDisplay(str.substr(0, str.size() - 1));
	}
}*/

	//큐
	/*IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("큐의 생성에 실패했습니다.");
		return 1;
	}
	while (1)
	{
		int m, x;

		printf("현재 데이터 수: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료: ");
		scanf("%d", &m);

		if (m == 0)break;
		switch (m)
		{
		case1:
			printf("데이터: ");scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a오류: 인큐에 실패하였습니다.");
			break;

		case2:
			if (Degue(&que, &x) == -1)
				puts("\a오류: 디큐에 실패하였습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;

		case3:
			if (Peek(&que, &x) == -1)
				puts("\a오류: 피크에 실패하였습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case4:
			Printf(&que);
			break;
		}
	}
	Terminate(&que);
	return 0;
}*/

	//스택
	/*IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("스택 생성에 실패했습니다.");
		return 1;
	}
	while (1)
	{
		int menu, x;
		printf("현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료: ");
		scanf("%d", &menu);

		if (menu == 0)break;
		switch (menu)
		{
		case 1:
			printf("데이터: ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류: 푸시에 실패했습니다.");
			break;
		case2:
			if (Pop(&s, &x) == -1)
				puts("\a오류: 팝에 실패했습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;
		case3:
			if (Peek(&s, &x) == -1)
				puts("\a오류: 피크에 실패했습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;
		case4:
			print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}*/

	//오름차순
	/*int nx, ky;
	puts("bsearch 함수를 사용하여 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	printf("오름차순으로 입력하세요.\n");
	printf("x[0]: ");
	scanf("%d", &x[0]);
	for (int i = 1;i < nx;i++)
	{
		do
		{
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("검색값: ");
	scanf("%d", &ky);
	int* p = bsearch(
		&ky,
		x,
		nx,
		sizeof(int),
		(int(*)(const void*, const void*))int_cmp
	);
	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d은(는) x[%d]에 있습니다.\n", ky, (int)(p - x));
	free(x);
	return 0;
}*/