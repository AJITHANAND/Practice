--  https://www.hackerrank.com/challenges/earnings-of-employees/problem
-- We define an employee's total earnifgs to be their monthly salary x months worked, and the maximum total earnings to be
-- the maximum total earnings for any|employee in the Employee table. Write a query to find the maximum total earnings for all
-- employees as well as the total number of employees who have maximum total earnings. Then print these values as 2 spafe-



-- SELECT MAX(months*salary) as max_sal,count(months*salary)
-- from employee
-- group by (months*salary)
-- order by max_sal DESC
-- limit 1;



SELECT MAX(EARNING) AS MAX_SAL, COUNT(*)
FROM
    (
        SELECT
            (MONTHS * SALARY) AS EARNING
        FROM
            EMPLOYEE
    ) AS SUBQUERY
WHERE
    EARNING = (
        SELECT
            MAX(MONTHS * SALARY)
        FROM
            EMPLOYEE
    );