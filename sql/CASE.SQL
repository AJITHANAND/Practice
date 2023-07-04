-- Generate the following two result sets:

-- Query an alphabetically ordered list of all names in OCCUPATIONS, immediately followed by the first letter of each profession as a parenthetical (i.e.: enclosed in parentheses). For example: AnActorName(A), ADoctorName(D), AProfessorName(P), and ASingerName(S).
-- Query the number of ocurrences of each occupation in OCCUPATIONS. Sort the occurrences in ascending order, and output them in the following format:

-- There are a total of [occupation_count] [occupation]s.
-- where [occupation_count] is the number of occurrences of an occupation in OCCUPATIONS and [occupation] is the lowercase occupation name. If more than one Occupation has the same [occupation_count], they should be ordered alphabetically.
-- https://www.hackerrank.com/challenges/the-pads/


SELECT
    CASE
        WHEN OCCUPATION = 'Doctor' THEN CONCAT(name, '(D)')
        WHEN OCCUPATION = 'Professor' THEN CONCAT(name, '(P)')
        WHEN OCCUPATION = 'Singer' THEN CONCAT(name, '(S)')
        WHEN OCCUPATION = 'Actor' THEN CONCAT(name, '(A)')
    END AS nameWithProfession
FROM OCCUPATIONS
ORDER BY nameWithProfession;


SELECT CONCAT('There are a total of ',COUNT(OCCUPATION),' ',LOWER(OCCUPATION),'s.')
FROM OCCUPATIONS
GROUP BY OCCUPATION
ORDER BY COUNT(OCCUPATION);


SELECT CONCAT(name, '(', LEFT(OCCUPATION, 1), ')') AS nameWithProfession
FROM OCCUPATIONS
ORDER BY nameWithProfession;
