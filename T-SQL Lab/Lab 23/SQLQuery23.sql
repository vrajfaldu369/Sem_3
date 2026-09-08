--From the table STUDENT perform the following queries:  
--Part – A:  
--SELECT * FROM STUDENT
--1. INSERT Procedures: Create stored procedures to insert records into STUDENT tables
--(PR_INSERT_STUDENT) 
CREATE PROC PR_INSERT_STUDENT
@STDID INT,
@SNAME VARCHAR(20),
@CITY VARCHAR(20),
@SPI DECIMAL(4,2),
@BRANCH VARCHAR(20)

AS
BEGIN
	INSERT INTO STUDENT(STDID, SNAME, CITY, SPI, BRANCH)
	VALUES(@STDID, @SNAME, @CITY, @SPI, @BRANCH)
END

EXEC PR_INSERT_STUDENT 115, 'PUSHTI', 'RAJKOT', 9.48, 'COMPUTER'
EXEC PR_INSERT_STUDENT 116, 'NIKUNJ', 'SURAT', 8.80, 'CHEMICAL'

--2. INSERT Procedures: Create stored procedures to insert records into DEPOSIT tables  
--(SP_INSERT_DEPOSIT)
CREATE PROC PR_INSERT_DEPOSIT
@ACTNO INT,
@CNAME VARCHAR(20),
@BNAME VARCHAR(20), 
@AMOUNT DECIMAL(8,2),
@ADATE DATETIME

AS
BEGIN
		INSERT INTO DEPOSIT(ACTNO, CNAME, BNAME, AMOUNT, ADATE)
		VALUES(@ACTNO, @CNAME, @BNAME, @AMOUNT, @ADATE)
END

EXEC SP_INSERT_DEPOSIT 118, 'HEMANT', 'BEDI', 16000, '05-05-2025'
EXEC SP_INSERT_DEPOSIT 119, 'RAVI', 'MAVDI', 24000, '09-07-2024'

--SELECT * FROM DEPOSIT

--3. UPDATE Procedures: Create stored procedure SP_UPDATE_STUDENT to update Branch in STUDENT 
--table. (Update using studentID)
CREATE PROC PR_UPDATE_STUDENT
@STDID INT,
@BRANCH VARCHAR(20)
AS
BEGIN
	UPDATE STUDENT
	SET BRANCH = @BRANCH
	WHERE STDID = @STDID
END

EXEC PR_UPDATE_STUDENT 115, 'ELECTRICAL'
EXEC PR_UPDATE_STUDENT 116, 'MECHANICAL'

--4. DELETE Procedures: Create stored procedure SP_DELETE_STUDENT to delete records from STUDENT 
--where Student Name is RAVI.
CREATE PROC PR_DELETE_STUDENT
    @SNAME VARCHAR(20)
AS
BEGIN
    DELETE FROM STUDENT
    WHERE SNAME = @SNAME
END

EXEC PR_DELETE_STUDENT 'RAVI'

--5. SELECT BY PRIMARY KEY: Create stored procedures to select records by primary key 
--(SP_SELECT_STUDENT_BY_ID) from Student table. (Display All Columns)
CREATE PROC PR_SELECT_STUDENT_BY_ID
    @STDID INT
AS
BEGIN
    SELECT * FROM STUDENT
    WHERE STDID = @STDID
END

EXEC PR_SELECT_STUDENT_BY_ID 103

--6. Create a stored procedure that shows details of the first 5 students ordered by SPI (Highest First).
CREATE PROC PR_TOP_5_STUDENTS
AS
BEGIN
    SELECT TOP 5 *
    FROM STUDENT
    ORDER BY SPI DESC
END

EXEC PR_TOP_5_STUDENTS

 
--From the table EMPLOYEE perform the following queries:  
--Part – B:   
--7. Create a stored procedure which displays all employee details. 
CREATE PROC PR_SELECT_ALL_EMPLOYEE
AS
BEGIN
    SELECT *
    FROM EMPLOYEE1
END

EXEC PR_SELECT_ALL_EMPLOYEE

--8. Create a stored procedure that takes department name as input and returns all the employee in that 
--department. 
CREATE PROC PR_EMPLOYEE_BY_DEPARTMENT
    @DEPT VARCHAR(20)
AS
BEGIN
    SELECT *
    FROM EMPLOYEE1
    WHERE DEPARTMENT = @DEPT
END

EXEC PR_EMPLOYEE_BY_DEPARTMENT 'IT'

--SELECT * FROM EMPLOYEE1

--Part – C:  
--9. Create a stored procedure which displays department-wise maximum, minimum, and average salary of 
--employee. 
CREATE PROC PR_DEPARTMENT_SALARY
AS
BEGIN
    SELECT 
        DEPARTMENT,
        MAX(SALARY) AS MAX_SALARY,
        MIN(SALARY) AS MIN_SALARY,
        AVG(SALARY) AS AVG_SALARY
    FROM EMPLOYEE1
    GROUP BY DEPARTMENT
END

EXEC PR_DEPARTMENT_SALARY

--10. Create a stored procedure that accepts department name as parameter and returns total salary of their 
--department. 
CREATE PROCEDURE PR_TOTAL_SALARY
    @DEPT VARCHAR(20)
AS
BEGIN
    SELECT 
        @DEPT AS [DEPARTMENT],
        SUM(SALARY) AS TOTAL_SALARY
    FROM EMPLOYEE1
    WHERE DEPARTMENT = @DEPT
END

EXEC PR_TOTAL_SALARY 'ADMIN'
SELECT * FROM EMPLOYEE1


------------------------------------------------------
--EXTRA
--DELETE Procedures: Create stored procedure PR_DELETE_CNAME to delete records from DEPOSIT 
CREATE PROC PR_DELETE_CNAME
    @CNAME VARCHAR(20)
AS
BEGIN
    DELETE FROM DEPOSIT
    WHERE CNAME = @CNAME
END

EXEC PR_DELETE_CNAME 'HEMANT'