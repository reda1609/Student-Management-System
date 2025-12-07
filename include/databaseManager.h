#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <iostream>
#include <stdexcept>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/exception.h>

#include "student.h"

using namespace std;

const string DB_HOST = "tcp://127.0.0.1:3306";
const string DB_USER = "root";
const string DB_PASS = "omarreda@12";
const string DB_SCHEMA = "students";

class DatabaseManager
{
    protected:
        sql::Driver* driver;
        std::unique_ptr<sql::Connection> con;

        void connect();

    public:
        DatabaseManager();

        void insertStudent(Student* s);

        void deleteStudent(int id);

        void updateStudent(Student* s);

        void getStudent(int id);

        void getAllStudents();
};

#endif