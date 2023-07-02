
-- https://www.hackerrank.com/challenges/weather-observation-station-5/problem
-- find out min and max length of the column values

-- SELECT CITY,LENGTH(CITY)
-- from STATION
-- WHERE
--     LENGTH(CITY)=(select MIN(LENGTH(CITY)) from STATION )
-- ORDER BY CITY
-- limit 1
-- SELECT CITY,LENGTH(CITY)
-- from STATION
-- WHERE
--     LENGTH(CITY)=(select MAX(LENGTH(CITY)) from STATION )
-- ORDER BY CITY
-- limit 1



with ShortCity as (
    SELECT CITY,LENGTH(CITY)
    from STATION
    WHERE
        LENGTH(CITY)=(select MIN(LENGTH(CITY)) from STATION )
    ORDER BY CITY
    limit 1
),

LongCity as (
    SELECT CITY,LENGTH(CITY)
    from STATION
    WHERE
        LENGTH(CITY)=(select MAX(LENGTH(CITY)) from STATION )
    ORDER BY CITY
    limit 1
)
Select * from ShortCity
UNION ALL
Select * from LongCity;