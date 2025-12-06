#include <iostream>
#include <string>

#include "student.h"
#include "databaseManager.h"

using namespace std;

void handleDeleteStudent(DatabaseManager* dm);
void handleSelectStudent(DatabaseManager* dm);
void handleSelectAllStudents(DatabaseManager* dm);
void handleInsertStudent(DatabaseManager* dm);
void handleUpdateStudent(DatabaseManager* dm);
void displayMenu();

int main()
{
    DatabaseManager dm;
    DatabaseManager* pDM = &dm;

    while(true)
    {
        displayMenu();
        
        int input;
        cin >> input;
        cin.ignore();

        switch(input)
        {
            case(1):
                handleInsertStudent(pDM);
                break;
            
            case(2):
                handleSelectAllStudents(pDM);
                break;

            case(3):
                handleSelectStudent(pDM);
                break;

            case(4):
                handleUpdateStudent(pDM);
                break;

            case(5):
                handleDeleteStudent(pDM);
                break;

            case(6):
                cout << "Program Terminated" << endl;
                exit(0);

            default:
                cout << "Undefined Input! Try Again!" << endl;
        }
    }
    return 0;
}

void handleDeleteStudent(DatabaseManager* dm)
{
    int id;
    cout << "ID of student to be deleted: ";
    cin >> id;
    dm->deleteStudent(id);
}

void handleSelectStudent(DatabaseManager* dm)
{
    int id;
    cout << "ID of student to be selected: ";
    cin >> id;
    dm->getStudent(id);
}

void handleSelectAllStudents(DatabaseManager* dm)
{
    dm->getAllStudents();
}

void handleInsertStudent(DatabaseManager* dm)
{
    int id, age;
    string name, dept;
    double gpa;

    cout << "Enter ID of the new student: ";
    cin >> id;
    cin.ignore();

    cout << "Enter name of the new student: ";
    getline(cin, name);

    cout << "Enter age of the new student: ";
    cin >> age;
    cin.ignore();

    cout << "Enter department of the new student: ";
    getline(cin, dept);

    cout << "Enter gpa of the new student: ";
    cin >> gpa;

    Student s(id, name, age, dept, gpa);
    Student* pS = &s;
    dm->insertStudent(pS);
}

void handleUpdateStudent(DatabaseManager* dm)
{
    int age, id;
    string name, dept;
    double gpa;

    cout << "Enter ID of the student to update: ";
    cin >> id;
    cin.ignore();

    cout << "Enter name of the student: ";
    getline(cin, name);

    cout << "Enter age of the student: ";
    cin >> age;
    cin.ignore();

    cout << "Enter department of the student: ";
    getline(cin, dept);

    cout << "Enter gpa of the student: ";
    cin >> gpa;

    Student s(id, name, age, dept, gpa);
    Student* pS = &s;
    dm->updateStudent(pS);
}

void displayMenu() 
{
    cout << "\n======= Student Management System =======" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. View All Students" << endl;
    cout << "3. Search Student by ID" << endl;
    cout << "4. Update Student Details" << endl;
    cout << "5. Delete Student by ID" << endl;
    cout << "6. Exit" << endl;
    cout << "=========================================" << endl;
}