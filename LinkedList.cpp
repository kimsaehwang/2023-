#include "LinkedList.h"
#include <iostream>

using namespace std;

// 학생 추가 
void addStudent(vector<Student>& studentList) 
{
    Student newStudent;
    cout << "학생 번호를 입력하세요: ";
    cin >> newStudent.number;
    cout << "학생 이름을 입력하세요: ";
    cin.ignore(); 
    getline(cin, newStudent.name);
    studentList.push_back(newStudent);

    cout << "학생 정보가 추가되었습니다.\n";
}

// 학생 삭제 
void removeStudent(vector<Student>& studentList)
{
    if (studentList.empty()) 
    {
        cout << "삭제할 학생 정보가 없습니다.\n";
        return;
    }

    int targetNumber;
    cout << "삭제할 학생의 번호를 입력하세요: ";
    cin >> targetNumber;

    for (size_t i = 0; i < studentList.size(); i++) 
    {
        if (studentList[i].number == targetNumber) 
        {
            studentList.erase(studentList.begin() + i);
            cout << "학생 정보가 삭제되었습니다.\n";
            return;
        }
    }

    cout << "해당 번호의 학생을 찾을 수 없습니다.\n";
}

// 전체 학생 출력 
void printAllStudents(const vector<Student>& studentList)
{
    if (studentList.empty())
    {
        cout << "출력할 학생 정보가 없습니다.\n";
        return;
    }

    cout << "\n전체 학생 정보\n";
    for (const auto& student : studentList) 
    {
        cout << "번호: " << student.number << ", 이름: " << student.name << endl;
    }
    cout << endl;
}


