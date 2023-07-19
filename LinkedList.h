#ifndef STUDENT
#define STUDENT

#include <string>
#include <vector>

struct Student {
    int number;
    std::string name;
};

void addStudent(std::vector<Student>& studentList);
void removeStudent(std::vector<Student>& studentList);
void printAllStudents(const std::vector<Student>& studentList);

#endif 

