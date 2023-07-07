--  https://www.hackerrank.com/challenges/weather-observation-station-18/problem

-- Consider Pj (a, b) and Py(c, d) to be two points on a 2D plane.

-- « a happens to equal the minimum value in Northern Latitude (LAT_N in STATION).
-- « bhappens to equal the minimum value in Western Longitude (LONG_W in STATION).
-- « chappens to equal the maximum value in Northern Latitude (LAT_N in STATION).
-- « d happens to equal the maximum value in Western Longitude (LONG_W in STATION).

-- Query the Manhattan Distance between points Pj and P; and round it to a scale of 4 decimal places.


SELECT ROUND(
     ((MAX(LAT_N) - MIN(LAT_N) ) 
        +
    (MAX(LONG_W) - MIN(LONG_W))),4
)

FROM STATION;