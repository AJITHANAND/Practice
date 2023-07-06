
 
-- https://www.hackerrank.com/challenges/weather-observation-station-19/problem
-- Consider Pj (a, ¢) and Py (b, d) to be two points on a 2D plane where (a, b) are the respective minimum and maximum values
-- of Northern Latitude (LAT_N) and (c,d) are the respective minimum and maximum values of Western Longitude (LONG_W) in

-- STATION.

-- Query the Euclidean Distance between points Pj and Py and format your answer to display 4 decimal digits.



select 
    ROUND(
        SQRT(
            POWER(min(LAT_N) - MAX(LAT_N),2) +
            POWER(MIN(LONG_W) - MAX(LONG_W),2)
        ),
        4)
    
from station;