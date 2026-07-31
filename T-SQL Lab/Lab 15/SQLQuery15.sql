--From the table PUBLISHER, AUTHOR and BOOK perform the following queries:  
--Part – A: 
SELECT * FROM BOOK
SELECT * FROM AUTHOR
SELECT * FROM PUBLISHER
--1. List all books with their authors.
SELECT B.TITLE, A.AUTHORNAME
FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID

--2. List all books with their publishers.
SELECT B.TITLE, P.PUBLISHERNAME
FROM BOOK B
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID

--3. List all books with their authors and publishers.
SELECT B.TITLE, A.AUTHORNAME, P.PUBLISHERNAME
FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID

--4. List all books published after 2010 with their authors and publisher and price.
SELECT B.TITLE, A.AUTHORNAME, P.PUBLISHERNAME, B.PRICE
FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID
WHERE B.PUBLICATIONYEAR > 2010

--5. List all authors and the number of books they have written.
SELECT A.AUTHORNAME, COUNT(B.BOOKID) AS TOTAL
FROM AUTHOR A
LEFT JOIN BOOK B
ON A.AUTHORID = B.AUTHORID
GROUP BY A.AUTHORNAME

--6. List all publishers and the total price of books they have published.
SELECT P.PUBLISHERNAME, SUM(B.PRICE) AS TOTAL_PRICE
FROM PUBLISHER P
LEFT JOIN BOOK B 
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY P.PUBLISHERNAME

--7. List authors who have not written any books.
SELECT A.AUTHORNAME
FROM AUTHOR A
LEFT JOIN BOOK B
ON B.AUTHORID = A.AUTHORID
WHERE B.TITLE IS NULL

--8. Display the total number of books written by each author along with the average price of their books.
SELECT COUNT(B.BOOKID) AS TOTAL_BOOK, A.AUTHORNAME, AVG(B.PRICE) AS AVG_PRICE
FROM AUTHOR A
LEFT JOIN BOOK B
ON B.AUTHORID = A.AUTHORID
GROUP BY AUTHORNAME

--9. lists each publisher along with the total number of books they have published, sorted from highest to lowest.
SELECT COUNT(B.BOOKID) AS TOTAL, P.PUBLISHERNAME
FROM PUBLISHER P
LEFT JOIN BOOK B
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY P.PUBLISHERNAME
ORDER BY TOTAL DESC

--10. Display number of books published each year.
SELECT COUNT(B.BOOKID), B.PUBLICATIONYEAR
FROM BOOK B
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY B.PUBLICATIONYEAR
ORDER BY B.PUBLICATIONYEAR


-- ------------------- ------------------------ --------------------- ------------------- --

CREATE TABLE EMPLOYEE_MASTER(
	EmployeeNo VARCHAR(10),
	Name VARCHAR(30),
	ManagerNo VARCHAR(10)
)

INSERT INTO EMPLOYEE_MASTER
VALUES('E01', 'Tarun', NULL),
	  ('E02', 'Rohan', 'E02'),
	  ('E03', 'Priya', 'E01'),
	  ('E04', 'Milan', 'E03'),
	  ('E05', 'Jay', 'E01'),
	  ('E06', 'Anjana', 'E04')

SELECT * FROM EMPLOYEE_MASTER

-- PART B

--11. List the publishers whose total book prices exceed 500, ordered by the total price.
SELECT P.PUBLISHERNAME, SUM(B.PRICE) AS TOTAL
FROM PUBLISHER P
JOIN BOOK B
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY P.PUBLISHERNAME
HAVING SUM(B.PRICE) > 500
ORDER BY TOTAL DESC

--12. List most expensive book for each author, sort it with the highest price.
SELECT A.AUTHORNAME, MAX(B.PRICE) AS MAXIMUM
FROM AUTHOR A
JOIN BOOK B
ON A.AUTHORID = B.AUTHORID
GROUP BY A.AUTHORNAME
ORDER BY MAXIMUM DESC

--13. Display publisher name and difference between maximum and minimum book price.
SELECT P.PUBLISHERNAME, MAX(B.PRICE) - MIN(B.PRICE) AS DIFFER
FROM PUBLISHER P
JOIN BOOK B
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY P.PUBLISHERNAME

--14. List publisher name and total price of books published each year.
SELECT P.PUBLISHERNAME, B.PUBLICATIONYEAR, SUM(B.PRICE) AS TOTAL
FROM PUBLISHER P
JOIN BOOK B
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY P.PUBLISHERNAME, B.PUBLICATIONYEAR
ORDER BY B.PUBLICATIONYEAR, P.PUBLISHERNAME


--15. Display author name and total price of books sorted by highest total price.
SELECT A.AUTHORNAME, SUM(B.PRICE) AS TOTAL
FROM AUTHOR A
JOIN BOOK B
ON A.AUTHORID = B.AUTHORID
GROUP BY A.AUTHORNAME
ORDER BY TOTAL DESC


--Part – C: 
--16. Retrieve the names of employee along with their manager’s name from the Employee table.
SELECT E.Name AS EMP_NAME,
	   M.Name AS MANAGER_NAME
FROM EMPLOYEE_MASTER E
LEFT JOIN EMPLOYEE_MASTER M
ON E.ManagerNo = M.ManagerNo

--17. Display employees who are managers.
SELECT DISTINCT M.EmployeeNo,
       M.Name
FROM EMPLOYEE_MASTER E
JOIN EMPLOYEE_MASTER M
ON E.ManagerNo = M.EmployeeNo

--18. Display number of employees working under each manager.
SELECT M.Name AS Manager_Name,
       COUNT(E.EmployeeNo) AS Total_Employees
FROM EMPLOYEE_MASTER M
JOIN EMPLOYEE_MASTER E
ON M.EmployeeNo = E.ManagerNo
GROUP BY M.Name;

--19. Display the employee’s name along with their manager’s name and senior manager name.
SELECT E.Name AS Employee_Name,
       M.Name AS Manager_Name,
       SM.Name AS Senior_Manager_Name
FROM EMPLOYEE_MASTER E
LEFT JOIN EMPLOYEE_MASTER M
ON E.ManagerNo = M.EmployeeNo
LEFT JOIN EMPLOYEE_MASTER SM
ON M.ManagerNo = SM.EmployeeNo

--20. Display managers and count of employees under them in descending order.
SELECT M.Name AS Manager_Name,
       COUNT(E.EmployeeNo) AS Employee_Count
FROM EMPLOYEE_MASTER M
JOIN EMPLOYEE_MASTER E
ON M.EmployeeNo = E.ManagerNo
GROUP BY M.Name
ORDER BY Employee_Count DESC
