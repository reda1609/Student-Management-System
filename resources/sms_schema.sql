DROP TABLE IF EXISTS student;

CREATE TABLE IF NOT EXISTS student (
	id integer unique key,
    full_name varchar(20),
    age integer,
    dept varchar(30),
    gpa decimal(3,2)
);

DROP TRIGGER IF EXISTS before_insert_check_values;

DELIMITER $$
CREATE TRIGGER before_insert_check_values
BEFORE INSERT ON student
FOR EACH ROW
BEGIN
	IF NEW.gpa < 0 THEN 
		SET NEW.gpa = 0; 
	END IF;
    
    IF NEW.age < 0 THEN 
		SET NEW.age = 0; 
	END IF;
END$$
DELIMITER ;

DROP TRIGGER IF EXISTS before_update_check_values;

DELIMITER $$
CREATE TRIGGER before_update_check_values
BEFORE UPDATE ON student
FOR EACH ROW
BEGIN
    IF NEW.gpa < 0 THEN 
        SET NEW.gpa = 0.00; 
    END IF;

    IF NEW.age < 0 THEN 
        SET NEW.age = 0; 
    END IF;
END$$
DELIMITER ;

DROP PROCEDURE IF EXISTS getAllStudents;

DELIMITER $$
CREATE PROCEDURE getAllStudents()
BEGIN
	SELECT * FROM student;
END$$
DELIMITER ;

DROP PROCEDURE IF EXISTS getStudent;

DELIMITER $$
CREATE PROCEDURE getStudent(IN student_id INT)
BEGIN
	SELECT * FROM student where id = student_id;
END$$
DELIMITER ;

DROP PROCEDURE IF EXISTS insertStudent;

DELIMITER $$
CREATE PROCEDURE insertStudent(IN student_id INT, IN student_name VARCHAR(20), IN student_age INT, IN student_dept VARCHAR(30), IN student_gpa DECIMAL(3,2))
BEGIN
	INSERT INTO student VALUES(student_id, student_name, student_age, student_dept, student_gpa);
END$$
DELIMITER ;

DROP PROCEDURE IF EXISTS updateStudent;

DELIMITER $$
CREATE PROCEDURE updateStudent(IN student_id INT, IN student_name VARCHAR(20), IN student_age INT, IN student_dept VARCHAR(30), IN student_gpa DECIMAL(3,2))
BEGIN
	UPDATE student SET full_name = student_name, age = student_age, dept = student_dept, gpa = student_gpa WHERE id = student_id;
END$$
DELIMITER ;

DROP PROCEDURE IF EXISTS deleteStudent;

DELIMITER $$
CREATE PROCEDURE deleteStudent(IN student_id INT)
BEGIN
	DELETE FROM student WHERE id = student_id;
END$$
DELIMITER ;
