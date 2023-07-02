-- https://www.hackerrank.com/challenges/weather-observation-station-6/
-- Query the list of CITY names starting with vowels (i.e., a, e, i, o, or u) from STATION

-- SELECT DISTINCT CITY
-- FROM STATION
-- WHERE REGEXP_LIKE(CITY, '^[aeiou]', 'i');

SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '^[aeiouAEIOU]';
