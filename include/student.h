#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
    protected:
        int id;
        string name;
        int age;
        string dept;
        double gpa;

    public:
        // Parameterized Constructor
        Student(int id, string name, int age, string dept, double gpa);

        // Setters
        void setID(int id) {this->id = id;}
        void setName(string name) {this->name = name;}
        void setAge(int age) {this->age = age;}
        void setDept(string dept) {this->dept = dept;}
        void setGPA(double gpa) {this->gpa = gpa;}

        // Getters
        int getID() {return this->id;}
        string getName() {return this->name;}
        int getAge() {return this->age;}
        string getDept() {return this->dept;}
        double getGPA() {return this->gpa;}

        void Student::displayDetails();
};

#endif