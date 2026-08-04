--From the table STADIUM, TEAM and PLAYER perform the following queries:  
--Part – A: 
SELECT * FROM PLAYER
SELECT * FROM STADIUM
SELECT * FROM TEAM
--1. Display players who belong to teams located in ‘Mumbai’.
SELECT P.PLAYER_FIRST_NAME, P.PLAYER_LAST_NAME
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
JOIN STADIUM S
ON S.Stadium_id = T.HOME_STADIUM_ID
WHERE S.Stadium_city = 'MUMBAI'

--2. Display all teams and players.
SELECT T.TEAM_NAME, P.PLAYER_FIRST_NAME, P.PLAYER_LAST_NAME
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID

--3. Display players along with team wins and stadium city.
SELECT P.PLAYER_FIRST_NAME, P.PLAYER_LAST_NAME, T.TEAM_WINS, S.Stadium_city
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
JOIN STADIUM S
ON S.Stadium_id = T.HOME_STADIUM_ID

--4. Display team name and number of players in each team.
SELECT T.TEAM_NAME, COUNT(T.TEAM_ID) AS NUMBER_OF_PLAYERS
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY T.TEAM_NAME

--5. Display team name, coach, and number of bowlers in each team.
SELECT T.TEAM_NAME, T.TEAM_COACH, COUNT(P.PLAYER_ID)
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
WHERE P.PLAYER_ROLE = 'BOWLER'
GROUP BY T.TEAM_NAME,T.TEAM_COACH

--6. Display team name with count of batsmen, bowlers, and all-rounders.
SELECT T.TEAM_NAME, P.PLAYER_ROLE, COUNT(CASE WHEN PLAYER_ROLE = 'BATSMAN' THEN 1 END) AS BATSMAN,
					COUNT(CASE WHEN PLAYER_ROLE = 'BOWLER' THEN 1 END) AS BOWLER,
					COUNT(CASE WHEN PLAYER_ROLE = 'ALL-ROUNDER' THEN 1 END) AS ALL_ROUNDER
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY T.TEAM_NAME, P.PLAYER_ROLE

--7. Display stadiums where teams have won more than 10 matches.
SELECT S.Stadium_name, T.TEAM_WINS
FROM TEAM T
JOIN STADIUM S
ON T.HOME_STADIUM_ID = S.Stadium_id
WHERE T.TEAM_WINS > 10

--8. Display team name and number of players whose matches played is greater than 25.
SELECT T.TEAM_NAME, COUNT(P.PLAYER_ID) AS NUMBER_OF_PLAYERS
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
WHERE P.PLAYER_MATCHES_PLAYED > 25
GROUP BY T.TEAM_NAME
--9. Display team name and total number of players having jersey number greater than 30.
SELECT T.TEAM_NAME, COUNT(P.PLAYER_ID) AS NUMBER_OF_PLAYERS
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
WHERE P.PLAYER_JERSEY_NUMBER > 30
GROUP BY T.TEAM_NAME

--10. Display team name and total matches played by its players.
SELECT T.TEAM_NAME, COUNT(P.PLAYER_ID) AS NUMBER_OF_PLAYERS, P.PLAYER_MATCHES_PLAYED
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY P.PLAYER_MATCHES_PLAYED, T.TEAM_NAME


--Part – B:
SELECT * FROM PLAYER
SELECT * FROM STADIUM
SELECT * FROM TEAM
--11. Display stadium city and total number of teams in each city.
SELECT S.Stadium_city, COUNT(T.TEAM_ID)
FROM STADIUM S
JOIN TEAM T
ON S.Stadium_id = T.HOME_STADIUM_ID
GROUP BY S.Stadium_city

--12. Display team name and average matches played by players in each team.
SELECT T.TEAM_NAME, AVG(P.PLAYER_MATCHES_PLAYED) AS NUMBER_OF_PLAYERS
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY T.TEAM_NAME

--13. Display team name and maximum matches played by any player in each team.
SELECT T.TEAM_NAME, MAX(P.PLAYER_MATCHES_PLAYED) AS MAX_MATCHES
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY T.TEAM_NAME

--14. Display team name and minimum matches played by any player in each team.
SELECT T.TEAM_NAME, MIN(P.PLAYER_MATCHES_PLAYED) AS MIN_MATCHES
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY T.TEAM_NAME

--15. Display stadium name and total number of players playing under teams of that stadium.
SELECT S.Stadium_name, COUNT(P.PLAYER_ID) AS TOTAL_PLATES, T.TEAM_NAME
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
JOIN STADIUM S
ON S.Stadium_id = T.HOME_STADIUM_ID
GROUP BY S.Stadium_name, T.TEAM_NAME


--Part – C:
SELECT * FROM PLAYER
SELECT * FROM STADIUM
SELECT * FROM TEAM
--16. Display teams having more all-rounders than bowlers.
SELECT T.TEAM_NAME,
					COUNT(CASE WHEN PLAYER_ROLE = 'BOWLER' THEN 1 END) AS BOWLER,
					COUNT(CASE WHEN PLAYER_ROLE = 'ALL-ROUNDER' THEN 1 END) AS ALL_ROUNDER
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY T.TEAM_NAME, P.PLAYER_ROLE
HAVING COUNT(CASE WHEN PLAYER_ROLE = 'BOWLER' THEN 1 END) < COUNT(CASE WHEN PLAYER_ROLE = 'ALL-ROUNDER' THEN 1 END)

--17. Display teams where difference between max and min player matches is greater than 5.
SELECT T.TEAM_NAME, MAX(P.PLAYER_MATCHES_PLAYED) - MIN(P.PLAYER_MATCHES_PLAYED) AS DIFF
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
JOIN STADIUM S
ON S.Stadium_id = T.HOME_STADIUM_ID
GROUP BY T.TEAM_NAME
HAVING MAX(P.PLAYER_MATCHES_PLAYED) - MIN(P.PLAYER_MATCHES_PLAYED) > 5

--18. Display stadium city and total wins of teams in that city.
SELECT S.Stadium_city, COUNT(T.TEAM_WINS) AS TOTAL_WINS
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
JOIN STADIUM S
ON S.Stadium_id = T.HOME_STADIUM_ID
GROUP BY S.Stadium_city

--19. Display team name and total number of players for each role (grouped by role).
SELECT T.TEAM_NAME, COUNT(P.PLAYER_ID), P.PLAYER_ROLE
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY T.TEAM_NAME, P.PLAYER_ROLE

--20. Display team name and total number of players whose name starts with ‘A’
SELECT T.TEAM_NAME, COUNT(CASE WHEN PLAYER_FIRST_NAME LIKE 'A%' THEN 1 END) AS TOTAL
FROM PLAYER P
JOIN TEAM T
ON T.TEAM_ID = P.TEAM_ID
GROUP BY T.TEAM_NAME
