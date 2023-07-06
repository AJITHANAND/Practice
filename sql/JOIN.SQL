 
-- https://www.hackerrank.com/challenges/average-population-of-each-continent/problem?isFullScreen=false
-- Given the CITY and COUNTRY tables, query the names of all the continents (COUNTRY.Continent) and ftheir respective average
-- city populations (CITY.Population) rounded down to the nearest integer.
-- Note: CITY.CountryCode and COUNTRY.Code are matching key columns.




SELECT COUNTRY.Continent, FLOOR(AVG(CITY.POPULATION))
FROM CITY JOIN COUNTRY 
ON COUNTRY.CODE = CITY.COUNTRYCODE
GROUP BY COUNTRY.CONTINENT;