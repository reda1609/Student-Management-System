#include <iostream>
#include <stdexcept>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/exception.h>

#include "databaseManager.h"
#include "student.h"

using namespace std;

DatabaseManager::DatabaseManager() 
{
    driver = get_driver_instance();
    connect();
}

void DatabaseManager::connect() 
{
    con.reset(driver->connect(DB_HOST, DB_USER, DB_PASS));
    con->setSchema(DB_SCHEMA);
    cout << "Database connection successful." << std::endl;
}

void DatabaseManager::insertStudent(Student* s)
{
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    
    stmt->execute(
        "INSERT INTO student VALUES (" + 
        std::to_string(s->getID()) + ", '" + 
        s->getName() + "', " + 
        std::to_string(s->getAge()) + ", '" + 
        s->getDept() + "', " + 
        std::to_string(s->getGPA()) + ")"
    );
    cout << "Student inserted successfully." << std::endl;
}

void DatabaseManager::deleteStudent(int id)
{
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    stmt->execute("DELETE FROM student WHERE id = " + to_string(id));
    cout << "Student with ID " << id << " deleted." << std::endl;
}

void DatabaseManager::updateStudent(Student* s)
{
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    stmt->execute(
        "UPDATE student SET full_name = '" + s->getName() + 
        "', age = " + std::to_string(s->getAge()) + 
        ", dept = '" + s->getDept() + 
        "', gpa = " + std::to_string(s->getGPA()) + 
        " WHERE id = " + std::to_string(s->getID())
    );
    cout << "Student with ID " << s->getID() << " updated." << std::endl;
}

void DatabaseManager::getStudent(int id)
{
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    std::unique_ptr<sql::ResultSet> res(
        stmt->executeQuery("SELECT * FROM student WHERE id = " + to_string(id))
    );

    if (res->next()) 
    {
        std::cout << res->getInt("id") << " - " 
                    << res->getString("full_name") << " - "
                    << res->getInt("age") << " - "
                    << res->getString("dept") << " - "
                    << res->getDouble("gpa") << std::endl;
    }
    else 
    {
        cout << "No student found with ID " << id << std::endl;
    }
    cout << "===================" << std::endl;
}

void DatabaseManager::getAllStudents()
{
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM student"));

    cout << "\n=== All Students ===" << std::endl;
    bool hasResults = false;
    while (res->next()) 
    {
        hasResults = true;
        std::cout << res->getInt("id") << " - " 
                    << res->getString("full_name") << " - "
                    << res->getInt("age") << " - "
                    << res->getString("dept") << " - "
                    << res->getDouble("gpa") << std::endl;
    }
    if (!hasResults) 
    {
        cout << "No students found." << std::endl;
    }
    cout << "===================" << std::endl;
}