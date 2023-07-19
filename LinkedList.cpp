#include "LinkedList.h"
#include <iostream>

using namespace std;

// �л� �߰� 
void addStudent(vector<Student>& studentList) 
{
    Student newStudent;
    cout << "�л� ��ȣ�� �Է��ϼ���: ";
    cin >> newStudent.number;
    cout << "�л� �̸��� �Է��ϼ���: ";
    cin.ignore(); 
    getline(cin, newStudent.name);
    studentList.push_back(newStudent);

    cout << "�л� ������ �߰��Ǿ����ϴ�.\n";
}

// �л� ���� 
void removeStudent(vector<Student>& studentList)
{
    if (studentList.empty()) 
    {
        cout << "������ �л� ������ �����ϴ�.\n";
        return;
    }

    int targetNumber;
    cout << "������ �л��� ��ȣ�� �Է��ϼ���: ";
    cin >> targetNumber;

    for (size_t i = 0; i < studentList.size(); i++) 
    {
        if (studentList[i].number == targetNumber) 
        {
            studentList.erase(studentList.begin() + i);
            cout << "�л� ������ �����Ǿ����ϴ�.\n";
            return;
        }
    }

    cout << "�ش� ��ȣ�� �л��� ã�� �� �����ϴ�.\n";
}

// ��ü �л� ��� 
void printAllStudents(const vector<Student>& studentList)
{
    if (studentList.empty())
    {
        cout << "����� �л� ������ �����ϴ�.\n";
        return;
    }

    cout << "\n��ü �л� ����\n";
    for (const auto& student : studentList) 
    {
        cout << "��ȣ: " << student.number << ", �̸�: " << student.name << endl;
    }
    cout << endl;
}


