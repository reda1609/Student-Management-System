#include <iostream>
#include <string>

#include "student.h"

using namespace std;

Student::Student(int id, string name, int age, string dept, double gpa)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->dept = dept;
    this->gpa = gpa;
}

void Student::displayDetails() 
{
    cout << " | Name: " << getName()
         << " | Age: " << getAge()
         << " | Dept: " << getDept()
         << " | GPA: " << getGPA() << std::endl;
}