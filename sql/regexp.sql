-- https://www.hackerrank.com/challenges/weather-observation-station-6/
-- Query the list of CITY names starting with vowels (i.e., a, e, i, o, or u) from STATION

-- SELECT DISTINCT CITY
-- FROM STATION
-- WHERE REGEXP_LIKE(CITY, '^[aeiou]', 'i');

SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '^[aeiouAEIOU]';


-- https://www.hackerrank.com/challenges/weather-observation-station-7
-- Query the list of CITY names ending with vowels (a, e, i, o, u) from STATION. Your result cannot contain duplicates.


select distinct city
from station 
where 
    city REGEXP '[aeiouAEIOU]$';




-- https://www.hackerrank.com/challenges/weather-observation-station-8/
-- Query the list of CITY names from STATION which have vowels (i.e., a, e, i, o, and u) as both their first and last characters. Your result cannot contain duplicates.

select distinct city 
from station
where city REGEXP '^[aeiouAEIOU].*[AEIOUaeiou]$';



-- https://www.hackerrank.com/challenges/weather-observation-station-9
-- Query the list of CITY names from STATION that do not start with vowels. Your result cannot contain duplicates.


select distinct city 
from station
where city regexp '^[^aeiouAEIOU]';



-- https://www.hackerrank.com/challenges/weather-observation-station-10
-- Query the list of CITY names from STATION that do not end with vowels. Your result cannot contain duplicates.


select distinct city 
from station
where city regexp '[^aeiouAEIOU]$';


-- Query the list of CITY names from STATION that either do not start with vowels or do not end with vowels. Your result cannot contain duplicates.
-- https://www.hackerrank.com/challenges/weather-observation-station-11/

select distinct city 
from station
where city regexp '^[^aeiouAEIOU]|[^aeiouAEIOU]$';


-- Query the list of CITY names from STATION that do not start with vowels and do not end with vowels. Your result cannot contain duplicates.
-- https://www.hackerrank.com/challenges/weather-observation-station-12/problem

select distinct city 
from station
where city regexp '^[^aeiouAEIOU].*[^aeiouAEIOU]$';



-- RIGHT() https://www.hackerrank.com/challenges/more-than-75-marks/
-- Query the Name of any student in STUDENTS who scored higher than  Marks. Order your output by the last three characters of each name. If two or more students both have names ending in the same last three characters (i.e.: Bobby, Robby, etc.), secondary sort them by ascending ID.

Select name 
from STUDENTS
where marks>75
order by RIGHT(name,3),ID ASC;
