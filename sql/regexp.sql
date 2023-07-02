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