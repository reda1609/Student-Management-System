# Student Management System

A console-based C++ application for managing student records with MySQL database integration. This project demonstrates CRUD operations, object-oriented programming, and secure database connectivity using MySQL Connector/C++.

## 📋 Features

- **Add New Student** - Insert student records with ID, name, age, department, and GPA
- **View All Students** - Display complete list of all students in the database
- **Search Student** - Find and display specific student details by ID
- **Update Student** - Modify existing student information
- **Delete Student** - Remove student records by ID
- **Data Validation** - Automatic validation using MySQL triggers (prevents negative age/GPA values)
- **SQL Injection Protection** - Secure database operations using prepared statements

## 🛠️ Technologies Used

- **Language:** C++
- **Database:** MySQL
- **Connector:** MySQL Connector/C++ 9.5.0
- **Compiler:** Microsoft Visual C++ (cl.exe)
- **Build System:** VS Code Tasks with MSBuild Tools

## 📁 Project Structure

```
Student-Management-System/
├── include/
│   ├── student.h              # Student class declaration
│   └── databaseManager.h      # Database operations class
├── src/
│   ├── main.cpp               # Main application entry point
│   ├── student.cpp            # Student class implementation
│   └── databaseManager.cpp    # Database CRUD operations
├── resources/
│   └── sms_schema.sql         # Database schema, triggers & stored procedures
├── build/                     # Build output directory
├── mysqlcppconn-10-vs14.dll   # MySQL Connector runtime library
├── mysqlcppconnx-2-vs14.dll   # MySQL Connector X DevAPI library
└── README.md
```

## 🔧 Prerequisites

- **MySQL Server** (8.0 or higher recommended)
- **MySQL Connector/C++** 9.5.0
- **Microsoft Visual Studio Build Tools** 2022
- **Windows OS** with PowerShell

## 📦 Installation & Setup

### 1. Clone the Repository

```bash
git clone https://github.com/reda1609/Student-Management-System.git
cd Student-Management-System
```

### 2. Database Setup

Run the SQL schema file to create the database and tables:

```sql
mysql -u root -p < resources/sms_schema.sql
```

Or manually execute the SQL file in MySQL Workbench.

### 3. Configure Database Connection

Edit the database credentials in `include/databaseManager.h`:

```cpp
const string DB_HOST = "tcp://127.0.0.1:3306";
const string DB_USER = "root";           // Your MySQL username
const string DB_PASS = "your_password";  // Your MySQL password
const string DB_SCHEMA = "students";
```

### 4. Update MySQL Connector Path

Modify the build task in `.vscode/tasks.json` if your MySQL Connector is installed in a different location:

```json
"/I", "YOUR_PATH\\mysql-connector-c++-9.5.0-winx64\\include",
"/LIBPATH:YOUR_PATH\\mysql-connector-c++-9.5.0-winx64\\lib64\\vs14"
```

### 5. Build the Project

In VS Code, press `Ctrl+Shift+B` or run:

```powershell
# The build task will execute:
# - Load Visual Studio Developer Command Prompt
# - Compile with cl.exe
# - Link MySQL Connector libraries
```

### 6. Run the Application

```powershell
.\build\main.exe
```

## 🎯 Usage

Upon running, you'll see an interactive menu:

```
======= Student Management System =======
1. Add New Student
2. View All Students
3. Search Student by ID
4. Update Student Details
5. Delete Student by ID
6. Exit
=========================================
```

### Example Workflow:

1. **Add a student:**
   - Select option `1`
   - Enter ID: `101`
   - Enter name: `Ahmed Hassan`
   - Enter age: `20`
   - Enter department: `Computer Science`
   - Enter GPA: `3.75`

2. **View all students:**
   - Select option `2`
   - Displays all student records

3. **Search for a student:**
   - Select option `3`
   - Enter ID to search

## 🗄️ Database Schema

### Student Table

| Column      | Type          | Constraints    |
|-------------|---------------|----------------|
| id          | INTEGER       | UNIQUE, PRIMARY KEY |
| full_name   | VARCHAR(20)   |                |
| age         | INTEGER       |                |
| dept        | VARCHAR(30)   |                |
| gpa         | DECIMAL(3,2)  |                |

### Triggers

- **before_insert_check_values** - Validates GPA and age on insert (sets to 0 if negative)
- **before_update_check_values** - Validates GPA and age on update (sets to 0 if negative)

### Stored Procedures

- `getAllStudents()` - Retrieve all student records
- `getStudent(student_id)` - Retrieve specific student by ID
- `insertStudent(...)` - Insert new student record
- `updateStudent(...)` - Update existing student record
- `deleteStudent(student_id)` - Delete student by ID

*Note: Current implementation uses direct SQL with prepared statements instead of stored procedures for better portability.*

## 🔒 Security Features

- **Prepared Statements:** All database queries use parameterized queries to prevent SQL injection attacks
- **Input Validation:** MySQL triggers ensure data integrity (no negative values for age/GPA)
- **Connection Management:** Proper resource cleanup using smart pointers

## 🏗️ Class Architecture

### Student Class
- Encapsulates student data (ID, name, age, department, GPA)
- Provides getters/setters for all attributes
- Implements `displayDetails()` method

### DatabaseManager Class
- Manages MySQL connection lifecycle
- Implements CRUD operations with prepared statements
- Handles connection errors and query execution

## 🚀 Future Enhancements

- [ ] Implement search by name/department
- [ ] Add sorting and filtering options
- [ ] Export data to CSV/PDF
- [ ] Add authentication system
- [ ] GUI implementation using Qt or wxWidgets
- [ ] Multi-user support with role-based access

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📄 License

This project is open source and available for educational purposes.

## 👨‍💻 Author

**Reda** - [GitHub Profile](https://github.com/reda1609)

## 📞 Contact

For questions or suggestions, please open an issue on GitHub.

---

⭐ If you found this project helpful, please consider giving it a star!