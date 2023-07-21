#ifndef STUDENT
#define STUDENT

#include <string>

const int MAX_STUDENTS = 100;

struct Student {
    int number;
    std::string name;
};

void addStudent(Student studentList[], int& numStudents);
void removeStudent(Student studentList[], int& numStudents);
void printAllStudents1(Student studentList[], int& numStudents);
void searchStudent(Student studentList[], int& numStudents);

#endif 

