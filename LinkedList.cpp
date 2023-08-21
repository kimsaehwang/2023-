#include "LinkedList.h"
#include <iostream>
#include<string>

using namespace std;

void addStudent(Student studentList[], int& numStudents) 
{
    Student newStudent;
    cout << "�л� ��ȣ�� �Է��ϼ���: ";
    cin >> newStudent.number;
    cout << "�л� �̸��� �Է��ϼ���: ";
    cin.ignore();
    getline(cin, newStudent.name);
    studentList[numStudents] = newStudent;
    numStudents++;

    cout << "�л� ������ �߰��Ǿ����ϴ�.\n";
}

void removeStudent(Student studentList[], int& numStudents) 
{
    if (numStudents == 0) 
    {
        cout << "������ �л� ������ �����ϴ�.\n";
        return;
    }

    int targetNumber;
    cout << "������ �л��� ��ȣ�� �Է��ϼ���: ";
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
        cout << "�ش� ��ȣ�� �л��� ã�� �� �����ϴ�.\n";
        return;
    }

    for (int i = foundIndex; i < numStudents - 1; i++) 
    {
        studentList[i] = studentList[i + 1];
    }

    numStudents--;
    cout << "�л� ������ �����Ǿ����ϴ�.\n";
}

void printAllStudents1(Student studentList[], int& numStudents)
{
    if (numStudents == 0)
    {
        cout << "����� �л� ������ �����ϴ�.\n";
        return;
    }
    cout << "\n----- ��ü �л� ���� -----\n";
    for (int i = 0; i < numStudents; i++) 
    {
        cout << "��ȣ: " << i<< ", �̸�: " << studentList[i].name << endl;
        if (i == studentList[i].number)
        {
            cout << ", �̸�: " << studentList[i].name << endl;
        }
        
    }
}

void searchStudent(Student studentList[], int& numStudents)
{
    if (numStudents == 0)
    {
        cout << "�˻��� �л� ������ �����ϴ�.\n";
        return;
    }

    int targetNumber;
    cout << "�˻��� �л��� ��ȣ�� �Է��ϼ���: ";
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
        cout << "�ش� ��ȣ�� �л��� ã�� �� �����ϴ�.\n";
        return;
    }

    for (int i = foundIndex; i < numStudents - 1; i++)
    {
        studentList[i] = studentList[i + 1];
    }
    cout << "�л� ������ �˻��Ǿ����ϴ�.\n";
    cout << targetNumber << "��, �̸� :" << studentList->name << endl;
}

