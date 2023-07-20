#include "LinkedList.h"
#include <iostream>
#include<string>

using namespace std;

void addStudent(Student studentList[], int& numStudents) 
{
    Student newStudent;
    cout << "학생 번호를 입력하세요: ";
    cin >> newStudent.number;
    cout << "학생 이름을 입력하세요: ";
    cin.ignore();
    getline(cin, newStudent.name);
    studentList[numStudents] = newStudent;
    numStudents++;

    cout << "학생 정보가 추가되었습니다.\n";
}

void removeStudent(Student studentList[], int& numStudents) 
{
    if (numStudents == 0) 
    {
        cout << "삭제할 학생 정보가 없습니다.\n";
        return;
    }

    int targetNumber;
    cout << "삭제할 학생의 번호를 입력하세요: ";
    cin >> targetNumber;

    int foundIndex = -1;
    for (int i = 0; i < numStudents; i++) 
    {
        if (studentList[i].number == targetNumber)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        cout << "해당 번호의 학생을 찾을 수 없습니다.\n";
        return;
    }

    for (int i = foundIndex; i < numStudents - 1; i++) 
    {
        studentList[i] = studentList[i + 1];
    }

    numStudents--;
    cout << "학생 정보가 삭제되었습니다.\n";
}

void printAllStudents1(Student studentList[], int& numStudents)
{
    if (numStudents == 0)
    {
        cout << "출력할 학생 정보가 없습니다.\n";
        return;
    }
    cout << "정방향 출력(1) 역방향출력(2) :";
    cout << "\n----- 전체 학생 정보 -----\n";
    for (int i = 0; i < numStudents; i++) 
    {
        cout << "번호: " << studentList[i].number << ", 이름: " << studentList[i].name << endl;
    }
}
void printAllStudents2(Student studentList[], int& numStudents)
{
    if (numStudents == 0)
    {
        cout << "출력할 학생 정보가 없습니다.\n";
        return;
    }
    cout << "정방향 출력(1) 역방향출력(2) :";
    cout << "\n----- 전체 학생 정보 -----\n";
    for (int i = numStudents; i > 0;i--)
    {
        cout << "번호: " << studentList[i].number << ", 이름: " << studentList[i].name << endl;
    }
}

