With temp as (Select
    Case When Occupation = 'Doctor' then name else Null end as Doctor,
    Case When Occupation = 'Professor' then name else Null end as Professor,
    Case When Occupation = 'Singer' then name else Null end as Singer,
    Case When Occupation = 'Actor' then name else Null end as Actor,
    ROW_NUMBER () OVER (PARTITION BY Occupation ORDER BY Name) as FIX
From Occupations)
Select MAX(Doctor),MAX(Professor),MAX(Singer),MAX(Actor)
from temp
Group By FIX