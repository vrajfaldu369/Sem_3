--Perform SQL Queries Using Aggregate Functions with GROUP BY Clause (Without HAVING) 
-- From the tables EMPLOYEE perform the following queries 
--Part – A:
SELECT * FROM EMPLOYEE1

--1. Display the Highest, Lowest Salary and Label the columns Maximum, Minimum respectively.
SELECT MAX(SALARY) AS MAXIMUM,
		MIN(SALARY) AS MINIMUM
FROM EMPLOYEE1

--2. Display Total, and Average salary of all employees. Label the columns Total_Sal and Average_Sal, respectively.
SELECT SUM(SALARY) AS TOTAL_SAL,
		AVG(SALARY) AS Average_Sal
FROM EMPLOYEE1

--3. Find total number of employees of EMPLOYEE table.
SELECT COUNT(FIRSTNAME)
FROM EMPLOYEE1

--4. Find highest salary from Rajkot city.
SELECT MAX(SALARY) AS MAXIMUM_SAL
FROM EMPLOYEE1
WHERE CITY = 'RAJKOT'

--5. Give maximum salary from IT department.
SELECT MAX(SALARY) AS MAXIM_SAL
FROM EMPLOYEE1
WHERE DEPARTMENT = 'IT'

--6. Count employee department is HR.
SELECT COUNT(EID) AS DEP_HR
FROM EMPLOYEE1
WHERE DEPARTMENT = 'HR'

SELECT * FROM EMPLOYEE1


--7. Display average salary of Admin department.
SELECT AVG(SALARY) AS ADMIN_AVG
FROM EMPLOYEE1
WHERE DEPARTMENT = 'ADMIN'

--8. Display total salary of HR department.
SELECT SUM(SALARY) AS TOTAL_SAL_HR
FROM EMPLOYEE1
WHERE DEPARTMENT = 'HR'

--9. Count total number of cities of employee without duplication.
SELECT COUNT(DISTINCT CITY) AS CITY_TOTAL
FROM EMPLOYEE1

--10. Count unique departments.
SELECT COUNT(DISTINCT DEPARTMENT) AS UNI_DEP
FROM EMPLOYEE1

--11. Display minimum salary of employee who belongs to Ahmedabad.
SELECT MIN(SALARY) AS MIN_SAL
FROM EMPLOYEE1
WHERE CITY = 'AHMEDABAD'

--12. Find city wise highest salary.
SELECT MAX(SALARY), CITY AS CITY
FROM EMPLOYEE1
GROUP BY CITY

--13. Find department wise lowest salary.
SELECT MIN(SALARY), DEPARTMENT AS CITY
FROM EMPLOYEE1
GROUP BY DEPARTMENT

--14. Display minimum salary in each city.
SELECT MIN(SALARY), CITY AS CITY
FROM EMPLOYEE1
GROUP BY CITY

--15. Display average salary of employees from Surat.
SELECT AVG(SALARY) AS DEP_HR
FROM EMPLOYEE1
WHERE CITY = 'SURAT'

--16. Display total salary of female employees.
SELECT SUM(SALARY)
FROM EMPLOYEE1
WHERE GENDER = 'FEMALE'

--17. Count number of male employees.
SELECT COUNT(GENDER) AS DEP_HR
FROM EMPLOYEE1
WHERE GENDER = 'MALE'

--18. Display city with the total number of employees belonging to each city.
SELECT COUNT(DISTINCT CITY) AS DEP_HR
FROM EMPLOYEE1

--19. Count number of employees in each city where gender is MALE.
SELECT COUNT(EID) AS EMPLOYEE_COUNT, CITY
FROM EMPLOYEE1
WHERE GENDER = 'MALE'
GROUP BY CITY

--20. Display maximum salary in each department where city is not Ahmedabad.
SELECT MAX(SALARY), DEPARTMENT AS DEP
FROM EMPLOYEE1
WHERE CITY <> 'AHMEDABAD'
GROUP BY DEPARTMENT


--Part – B: 
SELECT * FROM EMPLOYEE1

--21. Display minimum salary in each city where gender is FEMALE.
SELECT MIN(SALARY) AS MIN_SAL, CITY AS CITY
FROM EMPLOYEE1
WHERE GENDER = 'FEMALE'
GROUP BY CITY

--22. Give total salary of each department of EMPLOYEE table.
SELECT SUM(SALARY) AS TOT_SAL, DEPARTMENT AS DEP
FROM EMPLOYEE1
GROUP BY DEPARTMENT

--23. Give average salary of each department of EMPLOYEE table without displaying the respective department name.
SELECT AVG(SALARY) AVG_SAL 
FROM EMPLOYEE1
GROUP BY DEPARTMENT

--24. Count the number of employees for each department in every city.
SELECT COUNT(EID) AS EMP_COUNT, DEPARTMENT, CITY
FROM EMPLOYEE1
WHERE GENDER = 'FEMALE'
GROUP BY DEPARTMENT, CITY

--25. Calculate the total salary distributed to male and female employees.
SELECT SUM(SALARY), GENDER AS GENDER
FROM EMPLOYEE1
GROUP BY GENDER


--Part – C: 
SELECT * FROM EMPLOYEE1
--26. Give city wise maximum and minimum salary of female employees.
SELECT MAX(SALARY) AS MAXIM,MIN(SALARY) AS MINI
FROM EMPLOYEE1
WHERE GENDER = 'FEMALE'
GROUP BY CITY

--27. Calculate department, city, and gender wise average salary.
SELECT AVG(SALARY) AS AVG_SAL, DEPARTMENT, CITY, GENDER
FROM EMPLOYEE1
WHERE GENDER = 'FEMALE'
GROUP BY DEPARTMENT, CITY, GENDER

--28. Display the difference between the highest and lowest salaries. Label the column DIFFERENCE.
SELECT MAX(SALARY) - MIN(SALARY) AS DIFFERNCE
FROM EMPLOYEE1

--29. Display sum of salaries of department wise where department name consist 5 letter.
SELECT SUM(SALARY) AS AVG_SAL, DEPARTMENT
FROM EMPLOYEE1
WHERE LEN(DEPARTMENT) = 5
GROUP BY DEPARTMENT

--30. Find the Maximum salary department & city wise in which city name starts with ‘R’.
SELECT MAX(SALARY) AS MAX_SAL, DEPARTMENT, CITY
FROM EMPLOYEE1
WHERE CITY LIKE 'R%'
GROUP BY DEPARTMENT, CITY
