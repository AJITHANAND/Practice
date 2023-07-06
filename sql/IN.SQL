
--  https://www.hackerrank.com/challenges/asian-population/problem?isFullScreen=false

-- Given the CITY and COUNTRY tables, query the sum of the populations of all cities where the CONTINENT is ‘Asia’.

-- Note: CITY.CountryCode and COUNTRY.Code are matching key columns.


SELECT SUM(POPULATION)
FROM CITY 
WHERE CITY.COUNTRYCODE IN (SELECT CODE FROM COUNTRY WHERE CONTINENT LIKE 'Asia');