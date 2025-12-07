#include <iostream>
#include <stdexcept>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
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
    std::unique_ptr<sql::PreparedStatement> pstmt(
        con->prepareStatement("INSERT INTO student VALUES (?, ?, ?, ?, ?)")
    );
    
    pstmt->setInt(1, s->getID());
    pstmt->setString(2, s->getName());
    pstmt->setInt(3, s->getAge());
    pstmt->setString(4, s->getDept());
    pstmt->setDouble(5, s->getGPA());
    pstmt->execute();
    
    cout << "Student inserted successfully." << std::endl;
}

void DatabaseManager::deleteStudent(int id)
{
    std::unique_ptr<sql::PreparedStatement> pstmt(
        con->prepareStatement("DELETE FROM student WHERE id = ?")
    );
    
    pstmt->setInt(1, id);
    pstmt->execute();
    
    cout << "Student with ID " << id << " deleted." << std::endl;
}

void DatabaseManager::updateStudent(Student* s)
{
    std::unique_ptr<sql::PreparedStatement> pstmt(
        con->prepareStatement(
            "UPDATE student SET full_name = ?, age = ?, dept = ?, gpa = ? WHERE id = ?"
        )
    );
    
    pstmt->setString(1, s->getName());
    pstmt->setInt(2, s->getAge());
    pstmt->setString(3, s->getDept());
    pstmt->setDouble(4, s->getGPA());
    pstmt->setInt(5, s->getID());
    pstmt->execute();
    
    cout << "Student with ID " << s->getID() << " updated." << std::endl;
}

void DatabaseManager::getStudent(int id)
{
    std::unique_ptr<sql::PreparedStatement> pstmt(
        con->prepareStatement("SELECT * FROM student WHERE id = ?")
    );
    
    pstmt->setInt(1, id);
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

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