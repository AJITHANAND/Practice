

 
-- https://www.hackerrank.com/challenges/weather-observation-station-20
-- A median is defined as a number separating the higher half of a data set from the lower half. Query the median of the Northern

-- Latitudes (LAT_N) from STATION and round your answer to 4 decimal places.


SET @ridx :=-1;

SELECT round(avg(d.lat_n),4) as median
from (
        select @ridx := @ridx + 1 as ridx,
        station.lat_n as lat_n
        from station
        order by station.lat_n
) as d
where d.ridx IN ((FLOOR(@ridx/2)), CEIL(@ridx/2));